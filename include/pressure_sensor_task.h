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
#include "include/logger_task.h"

#include <stdlib.h>


#define TASKSTACKSIZE                    (128)
#define PRIORITY_PRESSURE_TASK            (4)

uint32_t PressureSensorTaskInit(void);


#endif /* INC_TEMPERATURE_TASK_H_ */
