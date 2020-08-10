#include <LPC21xx.H>
#include"mycan.h"
void init_can_tx()
{
	C1MOD=0x00000001;
	C1BTR=0x001c001D;
	C1MOD=0x00000000;
}
void init_A2D(void)
{
	VPBDIV=0x00000001;
	ADCR= 0x00270601;
	ADCR =0x01000000;
}
void init_led(void)
{
	IODIR1=0x00FF0000;
}
void can_tx(void)
{
	unsigned int val=0;
	C1TFI1= 0x00020000;
	C1TID1= 0X00000002;
	do
	{
		val= ADDR;
	}while((val & 0x80000000)==0);

	if(C1SR & 0x00000004)
	{
		IOSET1= 0x00ff0000;
		C1TDA1=val;
		C1CMR=0x00000021;
		IOCLR1=0x00ff0000;
	}
}