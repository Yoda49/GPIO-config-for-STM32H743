#include <stm32h7xx.h>
#include <stm32h743xx.h>
#include "stm32h743_gpio.h"

unsigned short gpio_bank [11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned char  gpio_conflict_flag = 0;

void gpio_init (unsigned char port, unsigned char pin, unsigned long mode, unsigned long type, unsigned long speed, unsigned long pull, unsigned long alt_func)
{
	GPIO_TypeDef * base = (GPIO_TypeDef *)(D3_AHB1PERIPH_BASE + (port * 0x0400UL));
	
	RCC->AHB4ENR |= (0x1UL << port); // set
	
	MODIFY_REG (base->MODER,    MODE_RESET << (pin * 2),  mode << (pin * 2));
	MODIFY_REG (base->OTYPER,   TYPE_RESET << (pin * 1),  type << (pin * 1));
	MODIFY_REG (base->OSPEEDR, SPEED_RESET << (pin * 2), speed << (pin * 2));
	MODIFY_REG (base->PUPDR,    PULL_RESET << (pin * 2),  pull << (pin * 2));
	
	if (pin <= 7) MODIFY_REG (base->AFR[0], ALTF_RS << ((pin - 0) * 4),  alt_func << ((pin - 0) * 4));
	else          MODIFY_REG (base->AFR[1], ALTF_RS << ((pin - 8) * 4),  alt_func << ((pin - 8) * 4));
	
	// check for conflict	
	if (gpio_bank[port] & (1UL << pin)) gpio_conflict_flag = 1; else gpio_bank [port] |= 1UL << pin;
}
