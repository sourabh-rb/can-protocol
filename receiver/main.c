#include <LPC21xx.h>
#include"mycan1.h"
int main()
{
	init_can_rx();
	init_serial();
	init_led();
	while(1);
 
}

