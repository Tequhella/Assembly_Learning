/*
 * Led_clignotement_C.c
 *
 * Created: 14/03/2022 09:31:47
 * Author : Tequhella
 */ 

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

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = (1 << PB0 | 1 << PB1 | 1 << PB2);
    /* Replace with your application code */
    while (1) 
    {
		PORTB =  (1 << PB0);
		_delay_ms(200);
		PORTB = ~(1 << PB0);
		PORTB =  (1 << PB1);
		_delay_ms(200);
		PORTB = ~(1 << PB1);
		PORTB =  (1 << PB2);
		_delay_ms(200);
		PORTB = ~(1 << PB2);
    }
	return (0);
}

