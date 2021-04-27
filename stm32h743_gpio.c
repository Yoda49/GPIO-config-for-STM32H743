#include <stm32h743xx.h>
#include "stm32h743_gpio.h"

void gpio_init (unsigned char port, unsigned char pin, unsigned char mode, unsigned char type, unsigned char speed, unsigned char pull, unsigned char alt_func)
{
	GPIO_TypeDef * base = (GPIO_TypeDef *)(D3_AHB1PERIPH_BASE + (port * 0x0400UL));
	
	RCC->AHB4ENR   |= (0x1UL << port); // set
	
	base->MODER   &= ~(MODE_RESET << (pin * 2)); // clear
	base->MODER   |= (unsigned long)mode << (pin * 2); // set
	
	base->OTYPER  &= ~(TYPE_RESET << pin); // clear
	base->OTYPER  |= (unsigned long)type << pin; // set
	
	base->OSPEEDR &= ~(SPEED_RESET << (pin * 2)); // clear
	base->OSPEEDR |= (unsigned long)speed << (pin * 2); // set
	
	base->PUPDR   &= ~(PULL_RESET << (pin * 2)); // reset
	base->PUPDR   |= (unsigned long)pull << (pin * 2); // set
	
	base->AFR[pin / 8] &= ~(0x0000000F << (pin * 4)); // reset
	base->AFR[pin / 8] |= (unsigned long)alt_func << (pin * 4); // set
}
