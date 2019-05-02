/*
 * led_task.h
 *
 *  Created on: 08-Apr-2019
 *      Author: hardik
 */

#include <stdlib.h>
#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"
#include "semphr.h"
#include "FreeRTOSConfig.h"
#include "utils/uartstdio.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "distance.h"

#define TASKSTACKSIZE                       (128)
#define PRIORITY_ULTRASONIC_TASK           (4)

#define MOVE_FORWARD_BIT            (0)
#define MOVE_BACKWARD_BIT           (1)
#define MOVE_RIGHT_BIT              (2)
#define MOVE_LEFT_BIT               (3)
#define BREAK_BIT                   (4)
#define STOP_BIT                    (5)

extern xSemaphoreHandle g_pUARTSemaphore;
extern QueueHandle_t motor_q;
extern uint8_t obstacle;
uint8_t command;

uint32_t UltrasonicTaskInit(void);
void UltrasonicFunction(void *pvParameters);
