#include <avr/io.h>

uint8_t keep_going = 1;


void setup()
{
	DDRD |= (1<<PD5)|(1<<PD6)|(1<<PD7);
	PORTD &= ~(1<<PD5)|(1<<PD6)|(1<<PD7);
	
}

void loop()
{
	uint16_t lowbyte;
	uint16_t highbyte;

	ADCSRA |= (1<<ADSC); // starts data collection

	while(!DCSA & (1<<ADIF)); // loop until adc is complete


	lowbyte = ADCL;  // 00000000 11101101
	highbyte = ADCH; // 00000000 00000010

	uint16_t finalvalue;

	finalvalue = (highbyte << 8) | lowbyte;
	
	if(finalvalue<303)
	{
		PORTD |= (1 <<PD7); //on
		PORTD &= ~(1 <<PD6); //off
		PORTD &= ~(1 <<PD5); //off
	}
	
	if(304<finalvalue<599)
	{
		PORTD |= (1 <<PD6); //on
		PORTD &= ~(1 <<PD7); //off
		PORTD &= ~(1 <<PD5); //off
	}
	
	if(600<finalvalue)
	{
		PORTD |= (1 <<PD5); //on
		PORTD &= ~(1 <<PD7); //off
		PORTD &= ~(1 <<PD6); //off
	}

}


int main(void)
{
 setup();
 
 
 while(keep_going) loop();
 
 return 0;  
}



