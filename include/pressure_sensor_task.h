/*
 * temperature_task.h
 *
 *  Created on: 08-Apr-2019
 *      Author: hardi
 */

#ifndef INC_TEMPERATURE_TASK_H_
#define INC_TEMPERATURE_TASK_H_

#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"
#include "semphr.h"
#include "FreeRTOSConfig.h"
#include "utils/uartstdio.h"
#include "driverlib/i2c.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/interrupt.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"

#include <stdlib.h>

extern xSemaphoreHandle g_pUARTSemaphore;

#define TASKSTACKSIZE                    (128)
#define PRIORITY_PRESSURE_TASK            (4)

#define MOVE_FORWARD_BIT            (0)
#define MOVE_BACKWARD_BIT           (1)
#define MOVE_RIGHT_BIT              (2)
#define MOVE_LEFT_BIT               (3)
#define BREAK_BIT                   (4)
#define STOP_BIT                    (5)

extern QueueHandle_t motor_q;

uint32_t PressureSensorTaskInit(void);
void PressureFunction(void *pvParameters);


#endif /* INC_TEMPERATURE_TASK_H_ */
