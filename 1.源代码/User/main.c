#include "stm32f10x.h"                  // Device header
#include "gizwits_product.h"
#include "oled.h"
#include "menu.h"
#include "dht11.h"
#include "motor.h"
#include "key.h"
#include "buzzer.h"
#include "flash.h"
#include "usart.h"
#include "sys.h"
#include "usb.h"
#include "tim3.h"
#include "tim2.h"
#include "iwdg.h"

#define FLASH_START_ADDR	0x0801f000	//写入的起始地址

u8 Menu = 1;	//菜单变量

u8 SetNum = 1;	

u8 Temp_value;	//温度阈值变量
u8 Humi_value;	//湿度阈值变量

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	OLED_Init();
	DHT11_UserConfig();
	MOTOR_UserConfig();
	 
	uart1_init(115200);
	
	GENERAL_TIM_Init();
	 
	
	while (1)
	{
		IWDG_ReloadCounter(); //重新加载计数值 喂狗

		switch(Menu)
			{
				case 1:
					Menu1();	//显示菜单1
				
					/*判断电机启动标志位是否为1*/
					if(Curtain_ON_Flag == 1)
					{
						MOTOR_Direction_Angle(1,0,180,1);	//顺时针电机旋转 180度
						MOTOR_STOP();	//电机停止
						Curtain_ON_Flag = 0;
					}
					
					/*判断电机关闭标志位是否为1*/
					if(Curtain_OFF_Flag == 1)
					{
						MOTOR_Direction_Angle(0,0,180,1);	//逆时针电机旋转 180度
						MOTOR_STOP();	//电机停止
						Curtain_OFF_Flag = 0;
					}
					break;
					
			 
					
				default : break;
		}
		 
	}
}
 
