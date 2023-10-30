#include<p18f4550.h>
#include <delays.h>
#include <stdio.h>
#include <stdlib.h>


#pragma LVP=OFF
#pragma FOSC=HS
#pragma WDT=0FF

void main(void)
{
	TRISD=1;
	TRISB=0;
	while(1)
	{
		PORTB=PORTD;
	}
}