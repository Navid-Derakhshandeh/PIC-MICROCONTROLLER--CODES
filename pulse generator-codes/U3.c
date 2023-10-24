#include<p18f4550.h>
#include <delays.h>
#include <stdio.h>
#include <stdlib.h>
#define BT PORTDbits.RD0

#pragma LVP=OFF
#pragma FOSC=HS
#pragma WDT=0FF

void TimeDelay(void);

void main(void)
{
	unsigned char x;
	TRISCbits.TRISC0=0;
	TRISDbits.TRISD0=1;
	TRISDbits.TRISD1=0;
	PORTCbits.RC0=1;
	while(1)
	{
		if(BT==1)
		{
			PORTDbits.RD1=0;
			PORTCbits.RC0=~PORTCbits.RC0;
			for(x=0;x<20;x++)
    			TimeDelay();
		}
		else
		{
			PORTDbits.RD1=1;
		}
	}
}
void TimeDelay()
{
	T0CON=0x0;
	TMR0H=0xFF;
	TMR0L=0xFE;
	T0CONbits.TMR0ON=1;
	while(INTCONbits.TMR0IF==0);
	T0CONbits.TMR0ON=0;
	INTCONbits.TMR0IF=0;
}