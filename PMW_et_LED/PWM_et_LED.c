/*
 * TP_IOT.c
 *
 * Créé	  : 22/03/2022 10:48:07
 * Auteur : Tequhella
 */ 

#include <avr/io.h>
#include <util/delay.h>

// ====================================
//                ATtiny
//               25/45/85
//              +--------+
//        PB5 --+ o  Vcc +------------
//		  PB3 --+        +-- PB2
//        PB4 --+        +-- PB1
//  ------------+ GND    +-- PB0
//              +--------+
// ====================================

void init_pwm(void)
{
	// Définition de la sortie PWM au pin 0
	DDRB |= (1 << DDB0);

	// Définition des entrées aux pins 1, 2 et 3
	PORTB |= (1 << PB1) | (1 << PB2) | (1 << PB3);
	
	// Définition du mode PWM
	TCCR0A |= (1 << COM0A1) | (1 << WGM00);
	
	// Définition du prédiviseur à 64
	TCCR0B |= (1 << CS01) | (1 << CS00);
}

int main(void)
{
	init_pwm();

	uint8_t x = 0;
	uint8_t y = 0;

	while(1)
	{
		x = !(PINB & (1 << PINB1)) ? 1 : 0;
		y = !(PINB & (1 << PINB2)) ? 2 : 0;

		x += y;

		if (!(PINB & (1 << PINB3)))
		{
			switch (x)
			{
				// OCR0A = 100%
				case 0:
					OCR0A = 255;
					break;
				// OCR0A = 20%
				case 1:
					OCR0A = 64;
					break;
				// OCR0A = 20% à fréquence 0,5 Hz
				case 2:
					OCR0A = 64;
					_delay_ms(200);
					OCR0A = 0;
					_delay_ms(200);
					break;
				// OCR0A = 80% à fréquence 0,5 Hz
				case 3:
					OCR0A = 191;
					_delay_ms(200);
					OCR0A = 0;
					_delay_ms(200);
					break;
			}
		}
		else
		{
			OCR0A = 0;
		}
	}
}
