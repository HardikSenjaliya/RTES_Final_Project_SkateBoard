/*
 * temperature_task.c
 *
 *  Created on: 08-Apr-2019
 *      Author: hardik
 */

#include "pressure_sensor_task.h"

extern TaskHandle_t g_MotorTaskHandle;
extern xSemaphoreHandle g_pPressureTaskSemaphore;

void PressureFunction(void *pvParameters)
{
    TickType_t start;
    while (1)
    {
        if ( xSemaphoreTake(g_pPressureTaskSemaphore, portMAX_DELAY) == pdTRUE)
        {
            start = xTaskGetTickCount();
            xSemaphoreTake(g_pUARTSemaphore, portMAX_DELAY);
//            UARTprintf("\nPressure Task at %d msecs\n", start);
            xSemaphoreGive(g_pUARTSemaphore);
            //TODO task notification
        }
    }
    vTaskDelete(NULL);
}

uint32_t PressureSensorTaskInit()
{

    if (xTaskCreate(PressureFunction, (const portCHAR *) "TASK_PRESSURE", TASKSTACKSIZE,
            NULL, tskIDLE_PRIORITY + PRIORITY_PRESSURE_TASK, NULL) != pdTRUE)
    {
        UARTprintf("ERROR: creating Pressure task\n");
        return (1);
    }


    return (0);
}

