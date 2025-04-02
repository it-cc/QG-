#include "UART_Init.h"

void UART_Init() 
{
    TMOD |= 0x20;  
    TH1 = 0xFD;    
    TL1 = 0xFD;
    SCON = 0x50;   
    TR1 = 1;       
    ES = 1;        
    EA = 1;        
}