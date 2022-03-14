;
; Entree_Sortie.asm
;
; Created: 05/03/2022 23:20:33
; Author : Tequhella
;

start:
	sbi		DDRB, DDB0		; Pin 0 définit en tant que sortie
	sbi		PORTB, PORTB1	; Résistance de tirage activé

boucle:
	in		r17, PINB		; Registre 17 prend la valeur définit de l'entrée
	sbr		r16, (1 << PB1) ; Registre 16 prend la valeur obtenue en entrée
	and		r16, r17		; Comparaison entre r16 et r17
	brbc	SREG_Z, ledOFF	; Si la comparaison est vraie, alors on entre dans la sous routine ledOFF
	sbis	PORTB, PORTB0	; Sinon, allumer la led si elle est éteinte
	sbi		PORTB, PORTB0	; Allume la led
	rjmp	boucle			; Retour de boucle

ledOFF:
	sbic	PORTB, PORTB0	; Si la led est éteinte, ignorer l'instruction suivante
	cbi		PORTB, PORTB0	; Eteindre la led
	rjmp	boucle			; Retour dans la boucle