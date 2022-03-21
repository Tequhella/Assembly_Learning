/*
 * 4Entrées_1Sortie.c
 *
 * Créé	  : 21/03/2022 12:28:19
 * Auteur : Tequhella
 */ 

#include <avr/io.h>


int main(void)
{
    /* Met le registre DDRB à 1 à la position du bit DDB0. */
	DDRB  |= (1 << DDB0);
	/* Définit comme entrées les ports 1, 2, 3 et 4. */
	PORTB |= (1 << PB1) | (1 << PB2) | (1 << PB3) | (1 << PB4);

	while (1) 
    {
		/* L'instruction if vérifie l'état des broches du port B. Si toutes les broches sont basses, la
		broche 0 du port B est définie sur haut. Si l'une des broches est haute, la broche 0 du port B est
		réglée sur bas. */
		if (!(PINB & (1 << PB1)) &&
			!(PINB & (1 << PB2)) &&
			!(PINB & (1 << PB3)) &&		/* Mettre le bit à la position PB0 à 1. */
			!(PINB & (1 << PB4))) /*--->*/ PORTB |= (1 << PB0);
		else
			/* Effacement du bit à la position PB0. */
			PORTB &= ~(1 << PB0);
    }
}

