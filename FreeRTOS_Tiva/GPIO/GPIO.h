/*
 * GPIO.h
 *
 *  Created on: Jul 3, 2019
 *      Author: AVE-LAP-016
 */

#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_


/* toggle_LED_one task for toggol LED & increment delay depend on boutton pressing
 * input ; void
 * output ; void */
void toggle_LED_one (void *x);

/* GPIO init task for initialize system clock for GPIO
 * input ; void
 * output ; void */
void init_GPIO (void *x);

#endif /* GPIO_GPIO_H_ */
