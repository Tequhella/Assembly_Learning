;
; Led_clignotement.asm
;
; Created: 05/03/2022 15:24:10
; Author : Tequhella
;


start:
	ldi		r17, (1<<DDB2)|(1<<DDB1)|(1<<DDB0)
    out		DDRB, r17
	clr		r17

boucle:
	sbi		PORTB, PORTB0	; Pin 0 : tension ON
	rcall	tempo			; Appel de la sous routine temporisation
	cbi		PORTB, PORTB0	; Pin 0 : tension OFF
	sbi		PORTB, PORTB1	; Pin 1 : tension ON
	rcall	tempo			; Appel de la sous routine temporisation
	cbi		PORTB, PORTB1	; Pin 1 : tension OFF
	sbi		PORTB, PORTB2	; Pin 2 : tension ON
	rcall	tempo			; Appel de la sous routine temporisation
	cbi		PORTB, PORTB2	; Pin 2 : tension OFF
	rcall	tempo			; Appel de la sous routine temporisation
	rjmp	boucle			; Retour de boucle

tempo:
	ldi		r16, 0xff
deltempo1:
	ldi		r17, 0xff
deltempo2:
	dec		r17					; Décrémentation du registre r17
	brbc	SREG_Z, deltempo2	; Si le flag n'est pas vidé, alors retour à la sous routine deltempo2
	dec		r16					; Décrémentation du registre r16
	brbc	SREG_Z, deltempo1	; Si le flag n'est pas vidé, alors retour à la sous routine deltempo1
	ret							; Sortie de la sous routine