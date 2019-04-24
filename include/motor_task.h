/*
 * alert_task.h
 *
 *  Created on: 09-Apr-2019
 *      Author: hardik
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
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/pwm.h"
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"


#define TASKSTACKSIZE               (128)
#define PRIORITY_MOTOR_TASK         (1)
#define QUEUE_SIZE                  (10)

#define MOVE_FORWARD_BIT            (0)
#define MOVE_BACKWARD_BIT           (1)
#define MOVE_RIGHT_BIT              (2)
#define MOVE_LEFT_BIT               (3)
#define BREAK_BIT                   (4)
#define STOP_BIT                    (5)


#define PWM_PERIOD_90               (57600)
#define PWM_PERIOD_50               (32000)

uint32_t TaskMotorInit(void);
void setup_motors(void);
void setup_gpio(void);
void forwared(void);
void move_backward(void);
void turn_left(void);
void turn_right(void);
void slow_motor(void);
void stop_motor(void);

#endif /* INCLUDE_MOTOR_TASK_H_ */
