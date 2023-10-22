#include<p18f4550.h>
#include<stdio.h>
#include<stdlib.h>
#include<delays.h>
#define mybit PORTBbits.RB5

#pragma LVP=OFF
#pragma FOSC=HS
#pragma WDT=0FF

void main(void)
{
	TRISBbits.TRISB5 =1;
	TRISDbits.TRISD0 =0;

	while(1)
	{
		if(mybit == 1)
		   PORTDbits.RD0 = 0xFF;
		else 
		   PORTDbits.RD0 = 0x00;
	}
		
	
}
