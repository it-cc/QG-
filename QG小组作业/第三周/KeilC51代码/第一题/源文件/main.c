#include"reg51.h"
#include "InitTimer.h"

unsigned int count=0;
unsigned char led_pos = 0;
sbit P2_0=P2^0;

void LED()
{
		P2 = ~(0x01 << led_pos); 
    led_pos++;
    if (led_pos >= 8) 
		{
        led_pos = 0;
    }
}


int main()
{
	P2_0=0;
	initTimer();
	while(1)
	{
		
	}
	
	return 0;
}

void timer_interrupt() interrupt 1
{
	TH0=(65536-1000)/256;
	TL0=(65536-1000)%256;
	count++;
	if (count >= 1000)
	{ 
			count = 0;
			//LED();
			P2_0=~P2_0;
	}
}