/*
 * alert_task.c
 *
 *  Created on: 09-Apr-2019
 *      Author: hardi
 */

#include "motor_task.h"

TaskHandle_t g_MotorTaskHandle;


static void TaskFunction(void *pvParameters)
{
    UARTprintf("Motor TASK\n");

    uint32_t ulNotifiedValue = 0;

    while (1)
    {
        xTaskNotifyWait(0x00, 0xFFFF, &ulNotifiedValue, portMAX_DELAY);

        UARTprintf("\n\nNotification Received with value of - %d\n\n", ulNotifiedValue);

        /*TODO switch case*/
        if(ulNotifiedValue & MOVE_FORWARD_BIT){

        }

        if(ulNotifiedValue & MOVE_BACKWARD_BIT){

        }

        if(ulNotifiedValue & MOVE_RIGHT_BIT){

        }

        if(ulNotifiedValue & MOVE_LEFT_BIT){

        }

    }
}


uint32_t TaskMotorInit()
{

    if (xTaskCreate(TaskFunction, (const portCHAR *) "TASK_MOTOR",
            TASKSTACKSIZE, NULL, tskIDLE_PRIORITY + PRIORITY_MOTOR_TASK,
            &g_MotorTaskHandle) != pdTRUE)
    {
        UARTprintf("ERROR: creating Motor task\n");
        return (1);
    }

    return (0);
}

