/*
 * Led_Declin.c
 *
 * Créé	  : 22/03/2022 10:48:07
 * Auteur : Tequhella
 */ 

#include <avr/io.h>
#include <util/delay.h>

// ATtiny25

#define PWM_MAX 255

void init_pwm(void)
{
	// Set PWM output pin to output
	DDRB |= (1 << DDB0);
	
	// Set PWM mode
	TCCR0A |= (1 << COM0A1) | (1 << WGM00);
	
	// Set prescaler to 64
	TCCR0B = (1<<CS01) | (1<<CS00);
}

int main(void)
{
	init_pwm();

	uint8_t intensitee = 0;
	uint8_t dir = 0;

	while(1)
	{
		/* Une boucle qui va de 0 à 255 puis de 255 à 0. */
		if (dir == 0)
		{
			intensitee++;
			OCR0A = intensitee;
			/* Vérifier si l'intensité est égale à l'intensité maximale. Si c'est le cas, cela change la
			direction du déclin. */
			if (intensitee == PWM_MAX)
			{
				dir = 1;
			}
		}
		else
		{
			intensitee--;
			OCR0A = intensitee;
			if (intensitee == 0)
			{
				dir = 0;
			}
		}
	}
}
