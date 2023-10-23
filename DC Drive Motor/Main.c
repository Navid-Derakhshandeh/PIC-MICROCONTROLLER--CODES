#include<p18f4550.h>
#include <delays.h>
#include <stdio.h>
#include <stdlib.h>
#define BT PORTDbits.RD0


#pragma LVP=OFF
#pragma FOSC=HS
#pragma WDT=0FF



void main()
{
	TRISDbits.TRISD0=1;
	TRISBbits.TRISB0=0;
	TRISBbits.TRISB1=0;
	while(1)
	{
		if(BT == 0)
		{
			PORTBbits.RB0 =1;
			
		}
		else
		{
			PORTBbits.RB1 =1;
		
		}
	}
}
