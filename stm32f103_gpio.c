#include "stm32f10x.h"
#include "stm32f103_gpio.h"

unsigned short gpio_bank [7] = {0, 0, 0, 0, 0, 0, 0};
unsigned char  gpio_conflict_flag = 0;

void gpio_init (unsigned char port, unsigned char pin, unsigned long mode, unsigned long cnf, unsigned long pull)
{
	GPIO_TypeDef * base = (GPIO_TypeDef *)(APB2PERIPH_BASE + ((port + 2) * 0x0400UL));
	
	RCC->APB2ENR |= 0x1UL << (port + 2); // switch on GPIO PORT
	
	if (pin <= 7) 
	{
		MODIFY_REG (base->CRL, 0x0F << (pin * 4), ((cnf << 2) + mode) << (pin * 4));
	}
	else
	{
		MODIFY_REG (base->CRH, 0x0F << ((pin - 8) * 4), ((cnf << 2)+ mode) << ((pin - 8) * 4));
	}
	
	if (mode == MODE_INPUT && cnf >= 2) MODIFY_REG (base->ODR, 1UL << pin,  pull << (pin * 1));
	
	
	// check for conflict	
	if (gpio_bank[port] & (1UL << pin)) gpio_conflict_flag = 1; else gpio_bank [port] |= 1UL << pin;
}

