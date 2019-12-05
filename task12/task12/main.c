#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>


void setup()
{
SPCR |= (1<<SPE);

SPCR &=~ (1<<SPIE);

SPCR &=~ (1<<DORD);
SPCR |= (1<<MSTR);
SPCR |= (1<<CPOL);
SPCR &=~ (1<<CPHA);
SPCR &=~ (1<<SPR1);
SPCR &=~ (1<<SPR0);

//SPDR = DATA REGISTER;

DDRB |= (1<<PB3)|(1<<PB5)|(1<<PB2)|(1<<PB6); //mosi|sck|ss

}

void loop()
{
	uint8_t data;
	uint8_t datarecieved;
		
	for(data = 1;data<256; data++)
	{
		PORTB &= ~(1<<PB6); // pulls chip low

		SPDR = data;

		while(!(SPSR & (1<<SPIF)));

		datarecieved = SPDR;

		PORTB |= (1<<PB6); // set chip select high
		_delay_ms(50);
	}
}

int main(void)
{
    setup();
    
    
    while(1){ loop();}
    
    return 0;
}

