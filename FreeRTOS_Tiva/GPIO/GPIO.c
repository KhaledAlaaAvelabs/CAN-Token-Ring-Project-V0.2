/*
 * GPIO.c
 *
 *  Created on: Jul 3, 2019
 *      Author: AVE-LAP-016
 */

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "../FreeRTOS_Files/FreeRTOS.h"
#include "../FreeRTOS_Files/task.h"
#include "../FreeRTOS_Files/semphr.h"
#include "../FreeRTOS_Files/queue.h"

#include "GPIO.h"



TaskHandle_t handler_init_GPIO = NULL;       /* init GPIO task handlar ceariation */

//extern xSemaphoreHandle CAN_semaphore;      /* This semaphore to check if Bottom pressed or not (check event)*/
//extern xSemaphoreHandle LED_semaphore;      /* This semaphore to check if Bottom pressed or not (check event)*/

/* toggle_LED_one task for toggol LED & increment delay depend on boutton pressing
 * input ; void
 * output ; void */
void toggle_LED_one (void *x)
{
    configASSERT(((uint32_t)x)==1);
    while(1)
    {

               /* Turn on the LED.*/

     //   if(LED_semaphore == 1) /* cheak if semaphore if given */
       //         {
                    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);
                    vTaskDelay(1000);   /* task delay */


                       /* Turn off the LED.*/

                    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);
                    vTaskDelay(1000);   /* task delay */
         //       }
  //      xSemaphoreGive(CAN_semaphore);   /*GIVE SEMAPHORE AFTER PRESSED*/

    }
}

/* GPIO init task for initialize system clock for GPIO
 * input ; void
 * output ; void */
void init_GPIO (void *x)
{
    configASSERT(((uint32_t)x)==1);
           /* Enable the GPIO port that is used for the on-board LED.*/
           SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

           /* Check if the peripheral access is enabled.*/
           while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
           {
           }

        /* Enable the GPIO pin for the LED (PF3).  Set the direction as output, and*/
        /* enable the GPIO pin for digital function.*/
        GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);

        vTaskSuspend(handler_init_GPIO); /* suspend init_GPIO task */


}

