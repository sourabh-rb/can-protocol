#include <LPC21xx.h>
#include"mycan.h"
int main()
{
	init_can_tx();
	init_A2D();
	init_led();
	while(1)
	{
		can_tx();
	}
 
}

