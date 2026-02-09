#ifndef __MENU_H
#define __MENU_H

#include "stm32f10x.h"                  // Device header
#include "oled.h"
#include "dht11.h"
#include "gizwits_product.h"

extern u8 Humi;
extern u8 Temp;

void Menu1(void);
void Menu2(void);
void OLED_Option(u8 num);
#endif
