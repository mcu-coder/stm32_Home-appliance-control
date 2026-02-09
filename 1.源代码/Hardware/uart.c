#include "uart.h"

void uart_init(void)
{
	USART_InitTypeDef USART_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//使能端口时钟 TXD RXD GPIO PA2 PA3
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA  | RCC_APB2Periph_AFIO, ENABLE);
	//使能串口1时钟 APB2
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE); 
	
	// 配置RXD引脚 PA10 浮空输入模式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	// 配置TXD引脚 PA9 复用推挽输出模式
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	USART_InitStructure.USART_BaudRate = 115200;//波特率设置
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//8位数据位
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一位停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无校验
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无需硬件流控
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;//UART模式选择  全双工，既可以发送也可以接收

	//初始化 UART1
	USART_Init(USART1, &USART_InitStructure);
	
	//使能串口工作
	USART_Cmd(USART1, ENABLE);
}

void send_byte(uint8_t byte)
{
	USART_SendData(USART1, byte);
	//等待USART1 发送完成
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
}

void send_string(uint8_t *str)
{
	while(*str != '\0')
	{
		send_byte(*str++);
	}

}

void send_buf(uint8_t *buf,uint16_t len)
{
	uint16_t i;
	for(i = 0; i < len; i++)
	{
		send_byte(buf[i]);
	}
}

int fputc(int ch, FILE *f) 
{
	send_byte(ch);
	return(ch);
}
