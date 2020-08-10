#include <LPC21xx.H>
#include"canRecv.h"

void init_can_rx(void)
{
	PINSEL1=0x00040000;
	C1MOD=0x00000001;
	C1BTR=0x001C001D;
	C1IER=0x00000001;
	VICVectCntl0=0x0000003A;
	//VICVectAddr0=(unsigned)CAN1IRQ;
	VICIntEnable=0x04000000;
	AFMR=0x00000001;
	//StandardFilter0=0x20012002;
	//StandardFilter1=0x20032004;
	//GroupStdFilter0=0x2009200F;
	//GroupStdFilter1=0x20112020;
	//IndividualExtFilter0=0x40010000;
	//IndividualExtFilter1=0x40020000;
	//GroupExtFilter0=0x40030000;
	//GroupExtFilter1=0x40040000;
	SFF_sa=0x0;
	SFF_GRP_sa=0x00000010;
	EFF_sa=0x00000018;
	EFF_GRP_sa=0x00000020;
	ENDofTable=0x00000028;
	AFMR=0x00000000;
	C1MOD=0x00000000;
}
void init_serial(void)
{
	PINSEL0 |= 0x00050000;
	U1LCR=0x00000083;
	U1DLL=0x000000C2;
	U1LCR=0x00000003;
}

void init_led(void)
{
	IODIR1=0x00FF0000;
}

void CAN1IRQ(void)__irq
{
	unsigned int i=0,j=0,val=C1RDA,DataLen;
	DataLen=((C1RFS>>16)& 0x0000000F);
	if (DataLen >4)
	{
		i=4;
		j=DataLen-i;
	}
	else
		i=DataLen;
	for(i;i>0;i--)
	{
		while(!(U1LSR & 0x00000020));
		U1THR=(val & 0x000000FF);
		IOSET1=val<<16;
		IOCLR1=val<<16;
		val=val>>8;
	}
	if(C1RDB != 0)
	{
		val=C1RDB;
		for(j;j>0;j--)
	{
		while(!(U1LSR & 0x00000020));
		U1THR=(val & 0x000000FF);
		IOSET1=val<<16;
		IOCLR1=val<<16;
		val=val>>8;
	}
	}
	C1CMR=0x00000004;
	VICVectAddr=0x00000000;
}
