/*
 * button.c
 *
 *  Created on: May 2, 2019
 *      Author: jains
 */

#include "Include/button.h"

/**
 * @brief Configure On board user button on PJ0
 */
void ConfigureButton()
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD_WPU);
    GPIOIntRegister(GPIO_PORTF_BASE, Button_ISR);
    GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_FALLING_EDGE);
    GPIOIntEnable(GPIO_PORTF_BASE, GPIO_INT_PIN_4);
    startup = 1;
}

/**
 * @brief Button click
 */
void Button_ISR(void)
{
    uint32_t i;
    GPIOIntDisable(GPIO_PORTF_BASE, GPIO_INT_PIN_4);
    i = GPIOIntStatus(GPIO_PORTF_BASE, false);
    GPIOIntClear(GPIO_PORTF_BASE, i);
    if((startup == 1) || (obstacle == 1))
    {
        startup = 0; obstacle = 0;
        button_flag = 1;
        for(i=0; i<1000; i++);
        move_forward();
    }
    GPIOIntEnable(GPIO_PORTF_BASE, GPIO_INT_PIN_4);
}


