#include<p18f4550.h>
#include <delays.h>
#include <stdio.h>
#include <stdlib.h>

#pragma LVP=OFF
#pragma FOSC=HS
#pragma WDT=0FF

void main(void)
{
	TRISB = 0;
	RCSTA = 0x90;
	SPBRG=15;
	while(1)
	{
		while(PIR1bits.RCIF==0);
		PORTB=RCREG;
	}
}