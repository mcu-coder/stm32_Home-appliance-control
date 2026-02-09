#include "tim2.h"                  // Device header


void Timer2_Init(u16 Prescaler, u16 Period)	//0-65535
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = Period;
	TIM_TimeBaseInitStructure.TIM_Prescaler = Prescaler;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
	
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	
	
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM2, ENABLE);
}

void TIM2_IRQHandler(void)	//2ms定时中断
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET ) 
	{
		Key_scan();

		if(KeyNum == 1 && Menu == 1)
		{
			KeyNum = 0;
			Menu = 2;
		}
		
		if(Temp_value<Temp || Humi_value<Humi)
		{
			Buzzer_ON();
		}
		else
		{
			Buzzer_OFF();
		}
			
		if(KeyNum == 44 && Menu == 1) //机智云配网按键，可以重新进行配网。
		{
			gizwitsSetMode(2);
			KeyNum = 0;
			Buzzer_ON();
			Delay_ms(300);
			Buzzer_OFF();
		}	
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);		
	}
}

