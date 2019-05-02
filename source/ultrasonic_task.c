/*
 * led_task.c
 *
 *  Created on: 08-Apr-2019
 *      Author: hardik
 */

#include "ultrasonic_task.h"

extern xSemaphoreHandle g_pUltrasonicTaskSemaphore;

void UltrasonicFunction(void *pvParameters)
{
    uint32_t distance_cm;
    TickType_t start;
    while (1)
    {
        if ( xSemaphoreTake(g_pUltrasonicTaskSemaphore, portMAX_DELAY) == pdTRUE)
        {
            start = xTaskGetTickCount();
            UARTprintf("\nUltrasonic Task released at %d msecs", distance_cm, start);

            if((distance_cm = distSensor_getDistance(HCSR04)) < 50)
            {
                command = BREAK_BIT;
                if(xQueueSend(motor_q, (void*)&command, portMAX_DELAY) != pdTRUE)//message queue to motors to slow down
                {
                    UARTprintf("\nError sending to queue from Ultrasonic Func.\n");
                }
            }
            else if((distance_cm = distSensor_getDistance(HCSR04)) < 25)
            {
                obstacle = 1;
                command = STOP_BIT;
                if(xQueueSend(motor_q, (void*)&command, portMAX_DELAY) != pdTRUE)//message queue to motors to slow down
                {
                    UARTprintf("\nError sending to queue from Ultrasonic Func.\n");
                }
                //message queue to motors to stop
            }
            else
            {
                command = MOVE_FORWARD_BIT;
                if(xQueueSend(motor_q, (void*)&command, portMAX_DELAY) != pdTRUE)//message queue to motors to slow down
                {
                    UARTprintf("\nError sending to queue from Ultrasonic Func.\n");
                }
                //message queue to motors to move forward
            }
            xSemaphoreTake(g_pUARTSemaphore, portMAX_DELAY);
            UARTprintf("\nDistance : %d cm at %d msecs", distance_cm, start);
            xSemaphoreGive(g_pUARTSemaphore);
        }
    }
    vTaskDelete(NULL);
}

uint32_t UltrasonicTaskInit()
{

    if (xTaskCreate(UltrasonicFunction, (const portCHAR *) "TASK_ULTRASONIC", TASKSTACKSIZE,
            NULL, tskIDLE_PRIORITY + PRIORITY_ULTRASONIC_TASK, NULL) != pdTRUE)
    {
        UARTprintf("ERROR: creating Ultrasonic task\n");
        return (1);
    }
    distSensor_Config(HCSR04);

    return (0);
}
