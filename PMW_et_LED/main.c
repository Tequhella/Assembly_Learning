/*
 * TP_IOT.c
 *
 * Créé	  : 22/03/2022 10:48:07
 * Auteur : Tequhella
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/*
 * Config ATtiny25 permettant le déclin progressif de la LED en PWM fast mode.
 */
void config_timer_0(void)
{
	TCCR0A |= (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);
	TCCR0B |= (1 << CS01);
	TIMSK  |= (1 << TOIE0);
	OCR0A  = 0;
	sei();
}

int main(void)
{
	DDRB |= (1 << DDB0);
	while (1)
	{
		// Déclin progressif de la LED.
		OCR0A += 1;
		_delay_ms(100);
		// Si OCR0A est égal à 255, retour à 0
		if (OCR0A == 255) /*--->*/ OCR0A = 0;
	}

	return 0;
}