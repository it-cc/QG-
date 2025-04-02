#include "InitTimer.h"

void initTimer()
{
	TMOD=0x01;
	TH0=(65536-1000)/256;
	TL0=(65536-1000)%256;
	ET0=1;
	EA=1;
	TR0=1;
}