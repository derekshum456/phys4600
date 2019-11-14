#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

uint8_t keep_going = 1;

void loop()
{
	PORTD |= (1 << PD1);
	_delay_ms(100);
	PORTD &= ~(1 << PD1);
	_delay_ms(100);
}

void setup()
{

}

void timer()
{
	TCNTO = 0;
	TCCROB = (1 << CS00 | 1 << CS02);
	
	while(1)
		{
		while(TFIRO & 1) == 0); // delay the program43w4
		}
}

int main()
{
	setup();
	
	
	while(keep_going) loop();
	
	return 0;
}

