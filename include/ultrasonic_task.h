/*
 * led_task.h
 *
 *  Created on: 08-Apr-2019
 *      Author: hardik
 */

#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"
#include "semphr.h"
#include "FreeRTOSConfig.h"
#include "utils/uartstdio.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include <stdlib.h>

#define TASKSTACKSIZE                       (128)
#define PRIORITY_ULTRASONIC_TASK           (3)


uint32_t UltrasonicTaskInit(void);
