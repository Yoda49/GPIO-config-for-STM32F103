#ifndef _STM32F103_GPIO_H_
#define _STM32F103_GPIO_H_

#define GPIO_PORT_A 0
#define GPIO_PORT_B 1
#define GPIO_PORT_C 2
#define GPIO_PORT_D 3
#define GPIO_PORT_E 4
#define GPIO_PORT_F 5
#define GPIO_PORT_G 6


// MODE = INPUT:
//
// 00 – аналоговый вход.
// 01 – вход в третьем состоянии. (Устанавливается после сброса).
// 10 – вход с подтягивающим резистором (направление устанавливается в GPIOx->ODR).
// 11 – зарезервировано для будущих применений.

// MODE = OUTPUT
//
// 00 – цифровой выход
// 01 – цифровой выход с открытым стоком
// 10 – цифровой выход, подключенный специализированным блокам
// 11 – цифровой выход, подключенный специализированным блокам с открытым стоком 


#define MODE_INPUT                 0UL
#define MODE_OUTPUT_10MHZ          1UL 
#define MODE_OUTPUT_20MHZ          2UL
#define MODE_OUTPUT_50MHZ          3UL

#define CNF_INPUT_ANALOG           0UL
#define CNF_INPUT_FLOATING         1UL
#define CNF_INPUT_WITH_PULL        2UL

#define CNF_OUTPUT_PUSH_PULL       0UL
#define CNF_OUTPUT_OPEN_DRAIN      1UL
#define CNF_OUTPUT_ALTF_PUSH_PULL  2UL
#define CNF_OUTPUT_ALTF_OPEN_DRAIN 3UL

#define PULL_DOWN                  0UL
#define PULL_UP                    1UL
#define PULL_DISABLE               2UL

// BITS OPERATIONS

#define GPIO_SET_BIT(port,bit) port|=1UL<<bit
#define GPIO_CLR_BIT(port,bit) port|=1UL<<(bit+16)
#define GPIO_GET_BIT(port,bit) port&(1UL<<bit) /* boolean result */

extern unsigned char gpio_conflict_flag;

void gpio_init (unsigned char port, unsigned char pin, unsigned long mode, unsigned long cnf, unsigned long pull);

#endif
