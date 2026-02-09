#ifndef __TIM2_H__
#define __TIM2_H__

#include "stm32f10x.h"                  // Device header
#include "menu.h"
#include "buzzer.h"
#include "key.h"

extern u8 Menu;
extern u8 Temp_value;
extern u8 Humi_value;



void Timer2_Init(u16 Prescaler, u16 Period);

#endif
