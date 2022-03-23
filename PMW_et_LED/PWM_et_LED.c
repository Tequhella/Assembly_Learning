/*
 * TP_IOT.c
 *
 * Created: 22/03/2022 10:48:07
 * Author : Tequhella
 */ 

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	/* Met le registre DDRB à 1 à la position du bit DDB0. */
	DDRB  |= (1 << DDB0);
	/* Définit comme entrées les ports 1, 2, 3 et 4. */
	PORTB |= (1 << PB1) | (1 << PB2) | (1 << PB3) | (1 << PB4);
	TCCR0A |= (1 << WGM00) | (1 << COM0A1);
	
	int x = 0;
	int y = 0;

	while (1)
	{
		x = !(PINB & (1 << PB1)) ? 1 : 0;
		y = !(PINB & (1 << PB2)) ? 2 : 0;
		x += y;
		if (!(PINB & (1 << PB3)))
		{
			switch (x)
			{
				case 0:
					TCCR0B |= (1 << CS01);
					TCCR0B &= ~(1 << CS02) | ~(1 << CS00);
					OCR0A = 255;
					break;
				case 1:
					TCCR0B |= (1 << CS01);
					TCCR0B &= ~(1 << CS02) | ~(1 << CS00);
					OCR0A = 50;
					break;
				case 2:
					TCCR0B |= (1 << CS02) | (1 << CS00);
					TCCR0B &= ~(1 << CS01);
					OCR0A = (OCR0A == 50) ? 0 : 50;
					break;
				case 3:
					TCCR0B |= (1 << CS02) | (1 << CS00);
					TCCR0B &= ~(1 << CS01);
					OCR0A = (OCR0A == 205) ? 0 : 205;
				break;
			}
		}
		else
		{
			OCR0A = 0;
		}
	}
}

