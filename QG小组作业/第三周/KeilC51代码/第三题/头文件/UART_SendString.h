#ifndef UART_INIT
#define UART_INIT

#include <reg51.h>

void UART_SendChar(char c);

void UART_SendString(const char *str);

#endif