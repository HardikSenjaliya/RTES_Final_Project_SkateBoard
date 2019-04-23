/*
 * temperature_task.c
 *
 *  Created on: 08-Apr-2019
 *      Author: hardik
 */

#include "pressure_sensor_task.h"

extern TaskHandle_t g_MotorTaskHandle;
extern xSemaphoreHandle g_pPressureTaskSemaphore;

static void TaskFunction(void *pvParameters)
{
    while (1)
    {
        if ( xSemaphoreTake(g_pPressureTaskSemaphore, portMAX_DELAY) == pdTRUE)
        {
            //TODO task notification
        }
    }
}

uint32_t PressureSensorTaskInit()
{

    if (xTaskCreate(TaskFunction, (const portCHAR *) "TASK_PRESSURE", TASKSTACKSIZE,
            NULL, tskIDLE_PRIORITY + PRIORITY_PRESSURE_TASK, NULL) != pdTRUE)
    {
        UARTprintf("ERROR: creating Pressure task\n");
        return (1);
    }


    return (0);
}

