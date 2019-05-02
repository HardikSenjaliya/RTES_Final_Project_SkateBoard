/*
 * main.h
 *
 *  Created on: 08-Apr-2019
 *      Author: hardi
 */

#ifndef INC_MAIN_H_
#define INC_MAIN_H_

#include "motor_task.h"
#include "pressure_sensor_task.h"
#include "ultrasonic_task.h"
#include "button.h"


volatile unsigned long long SeqCnt=0;
volatile TickType_t time_tickers;

/*Function Prototypes*/
void configure_uart(void);
void initialize_hardware_timer0(void);
void disable_hardware_timer0(void);


#endif /* INC_MAIN_H_ */
