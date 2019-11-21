#include <avr/io.h>

#include <avr/interrupt.h>

void loop()
{
	
}

void setup()
{
	DDRD |= (1<<PD5); //output 1
	DDRD |= (1<<PD6); //output 2 one with led

	
	TCCR0A |= (1<<COM0A0)| (1<<COM0A1);
	TCCR0A |= (1<<WGM01) | (1<<WGM00);
	TCCR0B |= (1<<CS00);
	
	
	
	
	
	
	
	OCR0A = 200;
	
	//sei();
}

uint8_t keep_going = 1;

int main(void)
{
	setup();
	while(1) loop();
	
}

