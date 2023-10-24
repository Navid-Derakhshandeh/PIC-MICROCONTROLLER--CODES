#include<p18f4550.h>
#include <delays.h>
#include <stdio.h>
#include <stdlib.h>


#pragma LVP=OFF
#pragma FOSC=HS
#pragma WDT=0FF

void main(void)
{
	TRISAbits.TRISA4=1;
	    TRISBbits.TRISB0=0;
	T0CON=0x68;
	TMR0L=0;

while(1)
{
	do
	{
		T0CONbits.TMR0ON=1;
		PORTBbits.RB0=TMR0L;
	}
	while(INTCONbits.TMR0IF==0);
	T0CONbits.TMR0ON=0;
	INTCONbits.TMR0IF=0;
}
}