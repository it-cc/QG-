#include "Timer0_Init.h"

void Timer0_Init() 
{
    TMOD |= 0x01;  
    TH0 = (65536 - 10000) / 256;  
    TL0 = (65536 - 10000) % 256;
    ET0 = 1;  
    EA = 1;   
    TR0 = 1;  
}