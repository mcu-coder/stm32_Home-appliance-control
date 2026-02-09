#ifndef _UART_H
#define _UART_H

#include <stdio.h>
#include <stm32f10x.h>


extern uint8_t rxd_cnt;
extern uint8_t rxd_flag;//接收完成标志
extern uint8_t rxd_buf[];
extern uint8_t rxd_index;
extern uint8_t uart_start_timer;
void uart_init(void);
void send_byte(uint8_t byte);
void send_string(uint8_t *str);
void send_buf(uint8_t *buf,uint16_t len);
void send_pack(void);
//uint8_t get_recv_flag(void);
#endif
