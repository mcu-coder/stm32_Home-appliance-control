#ifndef	__USB_H
#define __USB_H

#include "stm32f10x.h"                  // Device header

#define USB1		GPIO_Pin_12
#define USB2		GPIO_Pin_13

void USB_Init(void);
void USB_ON(u8 num);
void USB_OFF(u8 num);
#endif
