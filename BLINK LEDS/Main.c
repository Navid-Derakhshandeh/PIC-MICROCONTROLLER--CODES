#include<p18f4550.h>
#include <delays.h>
#include <stdio.h>
#include <stdlib.h>



#pragma LVP=OFF
#pragma FOSC=HS
#pragma WDT=0FF

void Delay(unsigned int);

void main(void)
{
	TRISB =0;
	TRISA =0;
	TRISD =0;
	TRISCbits.TRISC0 =0;
	TRISCbits.TRISC1 =0;
	while(1)
	{
		PORTB = 0x55;
		PORTA = 0xFF;
		PORTD = 0x55;
		LATCbits.LATC0=1;
		PORTCbits.RC1=1;
		Delay(50);
		PORTB = 0xAA;
		PORTA = 0x00;
		PORTD = 0xAA;
		LATCbits.LATC0=0;
		PORTCbits.RC1=0;
		Delay(50);
	}
}
void Delay(unsigned int Time)
{
	unsigned int a; unsigned char b;
	for(a=0;a<Time;a++)
	  for(b=0;b<165;b++);
}
