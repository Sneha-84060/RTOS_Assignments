/*
 * led.h
 *
 *  Created on: Oct 2, 2023
 *      Author: sunbeam
 */

#ifndef LED_H_
#define LED_H_

#include<stm32f407xx.h>

#define BV(n)	(1 << (n))

#define GPIOD_CLK_ENB	3

#define LED_GPIO	GPIOD

#define LED_GREEN	12
#define LED_ORANGE	13
#define LED_RED		14
#define LED_BLUE	15

void led_init(void);
void led_on(void);
void led_off(void);
void led_toggle(void);


#endif /* LED_H_ */
