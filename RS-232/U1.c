#include<p18f4550.h>
#include <delays.h>
#include <stdio.h>
#include <stdlib.h>


#pragma LVP=OFF
#pragma FOSC=HS
#pragma WDT=0FF

void Tx(unsigned char);

void main(void)
{

	TXSTA = 0x20;
	SPBRG = 15;
	TXSTAbits.TXEN = 1;
	RCSTAbits.SPEN = 1;
	while(1)
	{
		Tx('N');
		Tx('D');
	}
}
void Tx(unsigned char c)
{
	while(PIR1bits.TXIF==0);
	TXREG=c;
}