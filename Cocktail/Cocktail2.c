/**
 * @file main.c
 * @author Lilian CHARDON (lilian.chardon@gmail.com)
 * @brief Programme simulant un automate servant des cocktails.
 * @version 0.1
 * @date 2022-04-08
 * 
 * Matériel utilisé : ATtiny25
 */

#include <avr/io.h>
#include <util/delay.h>

/**
 * Configuration du port B, pin 1 en tant qu'entrée et pin 0 en tant que sortie.
 */
void config_portB()
{
    DDRB  |= (1 << DDB0);
    PORTB |= (1 << PB1);
}

/**
 * Fonction qui fait clignoter la LED 2 fois.
 */
void clignotement()
{
    PORTB |= (1 << PB0);
    _delay_ms(300);
    PORTB &= ~(1 << PB0);
    _delay_ms(300);
    PORTB |= (1 << PB0);
    _delay_ms(300);
    PORTB &= ~(1 << PB0);
}

int main(void)
{
    config_portB();
    clignotement();

    unsigned long int temps = 0;
	uint8_t v = 0;

    while (1) 
    {
        /*
        * Si le bouton est appuyé, on enregistre le temps passé depuis le début du programme. 
        */
        if (!(PINB & (1 << PB1)) && v == 0)
        {
			v++;
            clignotement();
        }
        if (v == 1) 
        {
			temps++;
			_delay_ms(1);
			
			if (!(PINB & (1 << PB1)))
			{
				clignotement();
				
				/*
				* Selon le temps enregistré, il allume la LED après un delay de temps - 3 secondes.
				*/
				if (temps > 3000)
				{
					temps -= 3000;
					while (temps > 0)
					{
						_delay_ms(1);
						temps--;
					}
					PORTB |= (1 << PB0);
					while (temps < 3000)
					{
						_delay_ms(1);
						temps++;
					}
					PORTB &= ~(1 << PB0);
				}
			}
        } 
    }

    return 0;
}