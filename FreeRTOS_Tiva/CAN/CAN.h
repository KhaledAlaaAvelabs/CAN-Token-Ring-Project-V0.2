/*
 * CAN.h
 *
 *  Created on: Jul 3, 2019
 *      Author: AVE-LAP-016
 */

#ifndef CAN_CAN_H_
#define CAN_CAN_H_


/* CAN TX init task for initialize CAN0 Tx
 * input ; void
 * output ; void */
void CAN_TX_Init (void *x);


/* CAN TX init task for initialize CAN0 Rx
 * input ; void
 * output ; void */
void CAN_RX_Init (void *x);


/* CAN0 Send task for send data with CAN0
 * input ; void
 * output ; void */
void CAN0_Send (void *x);


/* CAN0 Receive task for receive data with CAN0
 * input ; void
 * output ; void */
void CAN0_Receive (void *x);

#endif /* CAN_CAN_H_ */
