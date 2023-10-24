#include<p18f4550.h>
#include <delays.h>
#include <stdio.h>
#include <stdlib.h>
#define Bit PORTBbits.RB5
#define BT PORTDbits.RD0

#pragma LVP=OFF
#pragma FOSC=HS
#pragma WDT=0FF

void TimeDelay(void);

void main(void)
{
		unsigned char x,y;
	TRISBbits.TRISB5 = 0;
	TRISDbits.TRISD0 = 1;
	TRISDbits.TRISD1 = 0;
	while(1)
	{
		if(BT==1)
		{
			Bit^=1;
			for(x=0;x<250;x++)
		  	  for(y=0;y<78;y++)
			TimeDelay();
			PORTDbits.RD1 =0;
		}
		else
		{
			PORTDbits.RD1 =1;
		}
	}
}
void TimeDelay()
{
	T0CON=0x45;
	TMR0L=-1;
	T0CONbits.TMR0ON=1;
	T0CONbits.TMR0ON=0;
	INTCONbits.TMR0IF=0;
}