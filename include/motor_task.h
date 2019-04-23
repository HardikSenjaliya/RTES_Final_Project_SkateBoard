/*
 * alert_task.h
 *
 *  Created on: 09-Apr-2019
 *      Author: hardi
 */

#ifndef INCLUDE_MOTOR_TASK_H_
#define INCLUDE_MOTOR_TASK_H_

#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"
#include "semphr.h"
#include "FreeRTOSConfig.h"
#include "utils/uartstdio.h"
#include "motor_task.h"

#define TASKSTACKSIZE               (128)
#define PRIORITY_MOTOR_TASK         (1)
#define QUEUE_SIZE                  (10)

#define MOVE_FORWARD_BIT            (0)
#define MOVE_BACKWARD_BIT           (1)
#define MOVE_RIGHT_BIT              (2)
#define MOVE_LEFT_BIT               (3)

uint32_t TaskMotorInit(void);

#endif /* INCLUDE_MOTOR_TASK_H_ */
