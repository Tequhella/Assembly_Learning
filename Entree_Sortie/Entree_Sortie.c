/*
 * EntreeSortie.c
 *
 * Created: 14/03/2022 11:20:38
 * Author : Tequhella
 */ 

#include <avr/io.h>


int main(void)
{
	DDRB  |= (1 << DDB0);
	PORTB |= (1 << PB1);
    
    while (1)
    {
		if (PINB & (1 << PB1))
			PORTB &= ~(1 << PB0);
		else
			PORTB |= (1 << PB0);
    }
}

