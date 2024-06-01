/*
 * led.c
 *
 *  Created on: Oct 2, 2023
 *      Author: sunbeam
 */
#include"led.h"

void led_init(void)
{
	// enable clock for gpio D port
	RCC->AHB1ENR |= BV(GPIOD_CLK_ENB);

	// select mode of GPIO pins as output
	LED_GPIO->MODER |= BV(24) | BV(26) | BV(28) | BV(30);
	LED_GPIO->MODER &= ~(BV(25) | BV(27) | BV(29) | BV(31));

	// select output type as push pull
	LED_GPIO->OTYPER &= ~(BV(12) | BV(13) | BV(14) | BV(15));

	// select output speed as low
	LED_GPIO->OSPEEDR &= ~(BV(24) | BV(26) | BV(28) | BV(30));
	LED_GPIO->OSPEEDR &= ~(BV(25) | BV(27) | BV(29) | BV(31));

	// do not select pull up / pull down resistor
	LED_GPIO->PUPDR &= ~(BV(24) | BV(26) | BV(28) | BV(30));
	LED_GPIO->PUPDR &= ~(BV(25) | BV(27) | BV(29) | BV(31));
}
void led_on(void)
{
	// write 1 on respective bits of ODR
	LED_GPIO->ODR |= BV(LED_GREEN) | BV(LED_ORANGE) | BV(LED_RED) | BV(LED_BLUE);
}
void led_off(void)
{
	// write 0 on respective bits of ODR
	LED_GPIO->ODR &= ~(BV(LED_GREEN) | BV(LED_ORANGE) | BV(LED_RED) | BV(LED_BLUE));
}


void led_toggle(void)
{
	LED_GPIO->ODR ^= BV(LED_GREEN) | BV(LED_ORANGE) | BV(LED_RED) | BV(LED_BLUE);
}
