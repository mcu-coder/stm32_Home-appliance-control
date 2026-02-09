#include "menu.h"

u8 Humi,Temp;

void Menu1(void)
{
	//显示“温度：  C”
	OLED_ShowChinese(1,1,0);
	OLED_ShowChinese(1,2,1);
	OLED_ShowChar(1,5,':');
	OLED_ShowChar(1,8,'C');
	
	//显示“湿度:   %”
	OLED_ShowChinese(1,5,2);
	OLED_ShowChinese(1,6,3);
	OLED_ShowChar(1,13,':');	
	OLED_ShowChar(1,16,'%');
	
	//显示“灯光状态：”
	OLED_ShowChinese(2,1,4);
	OLED_ShowChinese(2,2,5);
	OLED_ShowChinese(2,3,10);
	OLED_ShowChinese(2,4,11);
	OLED_ShowChar(2,9,':');

	//显示“风扇状态：”
	OLED_ShowChinese(3,1,6);
	OLED_ShowChinese(3,2,7);
	OLED_ShowChinese(3,3,10);
	OLED_ShowChinese(3,4,11);
	OLED_ShowChar(3,9,':');
	
	//显示“窗帘状态：”
	OLED_ShowChinese(4,1,8);
	OLED_ShowChinese(4,2,9);
	OLED_ShowChinese(4,3,10);
	OLED_ShowChinese(4,4,11);
	OLED_ShowChar(4,9,':');
	
	//显示 DHT11温湿度数据
	DHT11_Read_Data(&Humi,&Temp);
	OLED_ShowNum(1,6,Temp,2);
	OLED_ShowNum(1,14,Humi,2);

	if(!LEDFlag)
	{
		OLED_ShowString(2,11,"OFF");
	}
	else
	{	
		OLED_ShowString(2,11,"ON");	
	}

	if(!FanFlag)
	{
		OLED_ShowString(3,11,"OFF");
	}
	else
	{
		OLED_ShowString(3,11,"ON");	
	}

	if(!CurtainFlag)
	{	
		OLED_ShowString(4,11,"OFF");
	}
	else
	{
		OLED_ShowString(4,11,"ON");
	}
}

void Menu2(void)
{
	//显示“系统阈值调节：”
	OLED_ShowChinese(1,1,12);
	OLED_ShowChinese(1,2,13);
	OLED_ShowChinese(1,3,14);
	OLED_ShowChinese(1,4,15);
	OLED_ShowChinese(1,5,16);
	OLED_ShowChinese(1,6,17);
	OLED_ShowChar(1,13,':');
	
	//显示“温度：”
	OLED_ShowChinese(2,2,0);
	OLED_ShowChinese(2,3,1);
	OLED_ShowChar(2,7,':');
	
	//显示“湿度:”
	OLED_ShowChinese(3,2,2);
	OLED_ShowChinese(3,3,3);
	OLED_ShowChar(3,7,':');
		
}

void OLED_Option(u8 num)
{
	switch(num)
	{
		case 1:	OLED_ShowChar(3,1,' ');OLED_ShowChar(2,1,'>');break;
		case 2:	OLED_ShowChar(2,1,' ');OLED_ShowChar(3,1,'>');break;
		default: break;
	}
}
