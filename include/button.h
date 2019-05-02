/*
 * button.h
 *
 *  Created on: May 2, 2019
 *      Author: jains
 */

#ifndef INCLUDE_BUTTON_H_
#define INCLUDE_BUTTON_H_

#include "motor_task.h"

void Button_ISR(void);
void ConfigureButton();

uint16_t button_flag;
uint8_t startup, obstacle;


#endif /* INCLUDE_BUTTON_H_ */
