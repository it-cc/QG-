#include "UART_SendString.h"

void UART_SendChar(char c) 
{
    SBUF = c;      
    while (!TI);   
    TI = 0;        
}


void UART_SendString(const char *str) 
{
    while (*str) 
		{
        UART_SendChar(*str++);
    }
}