/*
 * 1_PORTD_5_LED.c
 *
 * Created: 09-05-2026 01:42:37
 * Author : athul
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	//set PORTD Pin 5 as output
	DDRD |= (1 << PD5); //config PORTD pin 5 as output
	while (1)
	{
		//led on
		PORTD |= (1 << PD5); //turn on the led connect to pd5
		_delay_ms(3000); //delay 3 second while on
		
		//led off
		PORTD &= ~(1 << PD5); // trun off the led
		_delay_ms(5000); // delay 5 second while off
	}
	
	return 0;
}


