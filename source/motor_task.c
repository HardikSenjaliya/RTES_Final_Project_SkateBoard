/*
 * alert_task.c
 *
 *  Created on: 09-Apr-2019
 *      Author: hardik
 */

#include "motor_task.h"

TaskHandle_t g_MotorTaskHandle;

void move_forward()
{
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, PWM_PERIOD_90);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, PWM_PERIOD_90);

    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, GPIO_PIN_4);

    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, GPIO_PIN_2);
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0);

    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, GPIO_PIN_5);
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6, 0);
}

void move_backward()
{
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, PWM_PERIOD_90);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, PWM_PERIOD_90);

    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, GPIO_PIN_4);

    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0);
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, GPIO_PIN_3);

    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0);
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6, GPIO_PIN_6);

}

//TODO add timer for turning
void turn_left()
{
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, PWM_PERIOD_90);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, PWM_PERIOD_90);

    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, GPIO_PIN_4);

    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, GPIO_PIN_2);
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0);

    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0);
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6, 0);
}

//TODO add timer for turning
void turn_right()
{
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, PWM_PERIOD_90);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, PWM_PERIOD_90);

    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, GPIO_PIN_4);

    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0);
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0);

    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, GPIO_PIN_5);
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6, GPIO_PIN_6);
}

void slow_motor()
{

    /*Set duty cycle to be 50%*/
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, PWM_PERIOD_50);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, PWM_PERIOD_50);

    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, GPIO_PIN_4);

    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, GPIO_PIN_2);
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, GPIO_PIN_3);

    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, GPIO_PIN_5);
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6, GPIO_PIN_6);

}

void stop_motor()
{

    /*Set duty cycle to be 90%*/
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0, PWM_PERIOD_90);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1, PWM_PERIOD_90);

    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_4, GPIO_PIN_4);

    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0);
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_3, 0);

    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_5, 0);
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_6, 0);

}

void setup_gpio()
{

    /*Set up GPIO pins for direction of motors
     * PA2 - Motor1 direction input AIN1
     * PA3 - Motor1 direction input AIN2
     * PA5 - Motor2 direction input BIN1
     * PA6 - Motor2 direction input BIN2
     * PA4 - Standby input
     * */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    GPIOPinTypeGPIOOutput(
            GPIO_PORTA_BASE,
            GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6);

}

void setup_motors()
{

    /*Set the PWM clock to be system clock*/
    SysCtlPWMClockSet(SYSCTL_PWMDIV_1);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);

    /*For this example PWM0 is used with PortB Pin6.  The actual port and pins
     used may be different on your part, consult the data sheet for more
     information.  GPIO port B needs to be enabled so these pins can be used.*/

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

    /*Configure the GPIO pin muxing to select PWM00 functions for these pins.
     This step selects which alternate function is available for these pins.
     This is necessary if your part supports GPIO pin function muxing.
     Consult the data sheet to see which functions are allocated per pin.*/

    GPIOPinConfigure(GPIO_PB6_M0PWM0);
    GPIOPinConfigure(GPIO_PB7_M0PWM1);

    /*Configure the PWM function for this pin.
     Consult the data sheet to see which functions are allocated per pin.*/

    GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_6 | GPIO_PIN_7);

    /*Configure the PWM0 to count down without synchronization.*/
    PWMGenConfigure(PWM0_BASE, PWM_GEN_0,
    PWM_GEN_MODE_DOWN | PWM_GEN_MODE_NO_SYNC);

    /*Set PWM period*/
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, 64000);

    /*
     Enable processor interrupts.
     IntMasterEnable();
     */

    /*    Allow PWM0 generated interrupts.  This configuration is done to
     differentiate fault interrupts from other PWM0 related interrupts.
     PWMIntEnable(PWM0_BASE, PWM_INT_GEN_0);*/

    /*Enable the PWM0 LOAD interrupt on PWM0.*/
    PWMGenIntTrigEnable(PWM0_BASE, PWM_GEN_0, PWM_INT_CNT_LOAD);

    /*
     Enable the PWM0 interrupts on the processor (NVIC).
     IntEnable (INT_PWM0_0);

     */
    /*Enable the PWM0 output signal.*/
    PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT, true);
    PWMOutputState(PWM0_BASE, PWM_OUT_1_BIT, true)

    /*Enables the PWM generator block.*/
    PWMGenEnable(PWM0_BASE, PWM_GEN_0);
}

static void TaskFunction(void *pvParameters)
{
    UARTprintf("Motor TASK\n");

    uint32_t ulNotifiedValue = 0;

    while (1)
    {
        xTaskNotifyWait(0x00, 0xFFFF, &ulNotifiedValue, portMAX_DELAY);

        UARTprintf("\n\nNotification Received with value of - %d\n\n",
                   ulNotifiedValue);

        /*TODO switch case*/
        if (ulNotifiedValue & MOVE_FORWARD_BIT)
        {
            move_forward();
        }

        if (ulNotifiedValue & MOVE_BACKWARD_BIT)
        {
            move_backward();
        }

        if (ulNotifiedValue & MOVE_RIGHT_BIT)
        {
            turn_right();
        }

        if (ulNotifiedValue & MOVE_LEFT_BIT)
        {
            turn_left();
        }

        if (ulNotifiedValue & BREAK_BIT)
        {
            slow_motor();
        }

        if (ulNotifiedValue & STOP_BIT)
        {
            stop_motor();
        }

    }
}

uint32_t TaskMotorInit()
{

    if (xTaskCreate(TaskFunction, (const portCHAR *) "TASK_MOTOR",
            TASKSTACKSIZE, NULL, tskIDLE_PRIORITY + PRIORITY_MOTOR_TASK,
            &g_MotorTaskHandle) != pdTRUE)
    {
        UARTprintf("ERROR: creating Motor task\n");
        return (1);
    }

    setup_gpio();
    setup_motors();

    return (0);
}

