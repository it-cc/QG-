#include <reg51.h>
#include "UART_Init.h"

unsigned char code SEG_CODE[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};



void main() 
{
    UART_Init();   
    while (1);
}


void UART_ISR() interrupt 4 
{
    if (RI) 
    {     
        unsigned char num;  
        RI = 0;   
        num = SBUF - '0';   
        if (num <= 9)       
        {
            P2 = SEG_CODE[num];  
        }
    }
}