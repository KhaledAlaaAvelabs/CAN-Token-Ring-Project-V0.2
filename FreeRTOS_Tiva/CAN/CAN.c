/*
 * CAN.c
 *
 *  Created on: Jul 3, 2019
 *      Author: AVE-LAP-016
 */

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_can.h"


#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/fpu.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"
#include "driverlib/pin_map.h"

#include "driverlib/can.h"
#include "driverlib/interrupt.h"

#include "../FreeRTOS_Files/FreeRTOS.h"
#include "../FreeRTOS_Files/task.h"
#include "../FreeRTOS_Files/semphr.h"
#include "../FreeRTOS_Files/queue.h"
#include "CAN.h"



TaskHandle_t handler_init_CAN_Tx = NULL;       /* init CAN_Tx task handlar ceariation */
TaskHandle_t handler_init_CAN_Rx = NULL;        /* init CAN_Rx task handlar ceariation */

TaskHandle_t handler_CAN_Tx = NULL;       /* init CAN_Tx task handlar ceariation */
TaskHandle_t handler_CAN_Rx = NULL;        /* init CAN_Rx task handlar ceariation */

//extern xSemaphoreHandle CAN_semaphore;      /* This semaphore to check if Bottom pressed or not (check event)*/
//extern xSemaphoreHandle LED_semaphore;      /* This semaphore to check if Bottom pressed or not (check event)*/

/* CAN TX init task for initialize CAN0 Tx
 * input ; void
 * output ; void */
void CAN_TX_Init (void *x)
{


    configASSERT(((uint32_t)x)==1);

    tCANBitClkParms CANBitClk;
    tCANMsgObject sMsgObjectRx;



    uint8_t pui8BufferIn[8];
    uint8_t pui8BufferOut[8];


    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                      SYSCTL_XTAL_16MHZ);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

    GPIOPinConfigure(GPIO_PB4_CAN0RX);
    GPIOPinConfigure(GPIO_PB5_CAN0TX);

    GPIOPinTypeCAN(GPIO_PORTB_BASE, GPIO_PIN_4 | GPIO_PIN_5);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN0);

    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_CAN0))
      {
      }
    CANInit(CAN0_BASE);
    CANBitRateSet(CAN0_BASE, SysCtlClockGet(), 500000);

    CANEnable(CAN0_BASE);


        vTaskSuspend(handler_init_CAN_Tx); /* suspend init_system task */
}

/* CAN TX init task for initialize CAN0 Rx
 * input ; void
 * output ; void */
void CAN_RX_Init (void *x)
{
    configASSERT(((uint32_t)x)==1);

    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                       SYSCTL_XTAL_16MHZ);



        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

        GPIOPinConfigure(GPIO_PB4_CAN0RX);
        GPIOPinConfigure(GPIO_PB5_CAN0TX);


        GPIOPinTypeCAN(GPIO_PORTB_BASE, GPIO_PIN_4 | GPIO_PIN_5);


        SysCtlPeripheralEnable(SYSCTL_PERIPH_CAN0);


        CANInit(CAN0_BASE);


        CANBitRateSet(CAN0_BASE, SysCtlClockGet(), 500000);


        CANEnable(CAN0_BASE);

        vTaskSuspend(handler_init_CAN_Rx); /* suspend init_system task */

}


/* CAN0 Send task for send data with CAN0
 * input ; void
 * output ; void */
void CAN0_Send (void *x)
{
    configASSERT(((uint32_t)x)==1);
    uint8_t i=0;
    tCANMsgObject sCANMessage;


           sCANMessage.ui32MsgID = 2;
           sCANMessage.ui32MsgIDMask = 1;
           sCANMessage.ui32Flags =0;// MSG_OBJ_TX_INT_ENABLE;
           sCANMessage.ui32MsgLen =8;// sizeof(pui8MsgData);
           sCANMessage.pui8MsgData = '1' ;

           while(1)
           {
               /* CANMessageSet(ui32Base, ui32ObjID, psMsgObject, eMsgType);  */
               for(i=0;i<3;i++)
               {
                   CANMessageSet(CAN0_BASE, 1, &sCANMessage, MSG_OBJ_TYPE_TX);
               }

                   vTaskResume(handler_CAN_Rx);
                   vTaskSuspend(handler_CAN_Tx);

                   vTaskDelay(200);   /* task delay */
           }



}



/* CAN0 Receive task for receive data with CAN0
 * input ; void
 * output ; void */
void CAN0_Receive (void *x)
{
    configASSERT(((uint32_t)x)==1);

    uint32_t ui32Status;
       tCANMsgObject sCANMessage;
       uint8_t pui8MsgData[8];

        sCANMessage.ui32MsgID = 3;
        sCANMessage.ui32MsgIDMask = 3;
        sCANMessage.ui32Flags = MSG_OBJ_RX_INT_ENABLE | MSG_OBJ_USE_ID_FILTER;
        sCANMessage.ui32MsgLen = 8;

        CANMessageSet(CAN0_BASE, 1, &sCANMessage, MSG_OBJ_TYPE_RX);
    /* CANMessageGet(ui32Base, ui32ObjID, psMsgObject, bClrPendingInt); */

    for(;;)
        {

            ui32Status = CANStatusGet(CAN0_BASE, CAN_STS_CONTROL);
            if(ui32Status)
            {

                sCANMessage.pui8MsgData = pui8MsgData;
                CANMessageGet(CAN0_BASE, 1, &sCANMessage, 0);


                vTaskResume(handler_CAN_Tx);
                vTaskSuspend(handler_CAN_Rx);

            }

            vTaskDelay(200);   /* task delay */

        }



}

