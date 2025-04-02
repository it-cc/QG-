#include <reg51.h>
#include "UART_Init.h"
#include "Timer0_Init.h"
#include "UART_SendString.h"

unsigned int count = 0;


void main() 
{
    Timer0_Init();  
    UART_Init();    
    while (1);
}

void Timer0_ISR() interrupt 1 
{
    TH0 = (65536 - 10000) / 256;  
    TL0 = (65536 - 10000) % 256;
    count++;
    if (count >= 100) 
		{  
        count = 0;
        UART_SendString("Hello, World!\r\n");  
    }
}