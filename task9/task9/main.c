#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(TIMER0_OVF_vect)
{
	PORTD ^= (1<<PD1);
}

ISR(TIMER0_COMPA_vect)
{
	PORTD ^= (1<<PD1);
}

void loop()
{

}

void setup()
{
	DDRD |= (1<<PD1);
	PORTD &= ~(1<<PD1);
	
	TCCR0B = 0x01;
	//TIMSK0 = 3;
	TIMSK0 |= (1<<OCIE0A)|(1<<TOIE0);
	
	OCR0A = 200;
	
	sei();
}

uint8_t keep_going = 1;

int main(void)
{
  setup();
  while(1) loop();
  
}

