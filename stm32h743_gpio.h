#ifndef _STM32H743_GPIO_H_
#define _STM32H743_GPIO_H_

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3
#define PORT_E 4
#define PORT_F 5
#define PORT_G 6
#define PORT_H 7
#define PORT_I 8
#define PORT_J 9
#define PORT_K 10

#define ALTF_0  0x0UL
#define ALTF_1  0x1UL
#define ALTF_2  0x2UL
#define ALTF_3  0x3UL
#define ALTF_4  0x4UL
#define ALTF_5  0x5UL
#define ALTF_6  0x6UL
#define ALTF_7  0x7UL
#define ALTF_8  0x8UL
#define ALTF_9  0x9UL
#define ALTF_10 0xAUL
#define ALTF_11 0xBUL
#define ALTF_12 0xCUL
#define ALTF_13 0xDUL
#define ALTF_14 0xEUL
#define ALTF_15 0xFUL
#define ALTF_RS 0xFUL

#define MODE_INPUT  0x0UL
#define MODE_OUTPUT 0x1UL
#define MODE_ALT_F  0x2UL
#define MODE_ANALOG 0x3UL
#define MODE_RESET  0x3UL

#define TYPE_PUSH_PULL  0x0UL
#define TYPE_OPEN_DRAIN 0x1UL
#define TYPE_RESET      0x1UL

#define SPEED_LOW   0x0UL
#define SPEED_MED   0x1UL
#define SPEED_HIGH  0x2UL
#define SPEED_MAX   0x3UL
#define SPEED_RESET 0x3UL

#define PULL_NO    0x0UL
#define PULL_UP    0x1UL
#define PULL_DOWN  0x2UL
#define PULL_RESET 0x3UL

extern unsigned char gpio_conflict_flag;

void gpio_init (unsigned char port, unsigned char pin, unsigned long mode, unsigned long type, unsigned long speed, unsigned long pull, unsigned long alt_func);
#endif
