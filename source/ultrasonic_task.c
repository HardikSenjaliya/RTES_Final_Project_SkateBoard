/*
 * led_task.c
 *
 *  Created on: 08-Apr-2019
 *      Author: hardik
 */

#include "ultrasonic_task.h"


extern xSemaphoreHandle g_pUltrasonicTaskSemaphore;

static void TaskFunction(void *pvParameters)
{

    while (1)
    {
        if ( xSemaphoreTake(g_pUltrasonicTaskSemaphore, portMAX_DELAY) == pdTRUE)
        {

        }
    }
}

uint32_t UltrasonicTaskInit()
{

    if (xTaskCreate(TaskFunction, (const portCHAR *) "TASK_ULTRASONIC", TASKSTACKSIZE,
            NULL, tskIDLE_PRIORITY + PRIORITY_ULTRASONIC_TASK, NULL) != pdTRUE)
    {
        UARTprintf("ERROR: creating Ultrasonic task\n");
        return (1);
    }

    return (0);
}
