;
; Entree_Sortie.asm
;
; Created: 05/03/2022 23:20:33
; Author : Tequhella
;

start:
	sbi	DDRB, DDB0	; Pin 0 définit en tant que sortie
	sbi	PORTB, PORTB1	; Résistance de tirage activé

boucle:
	sbic	PINB, PINB1	; Vérifie si l'état du PIN1 est à 0
	rcall	ledOFF		; Si la comparaison est vraie, alors on entre dans la sous routine ledOFF
	sbis	PORTB, PORTB0	; Sinon, allumer la led si elle est éteinte
	sbi	PORTB, PORTB0	; Allume la led
	rjmp	boucle		; Retour de boucle

ledOFF:
	sbic	PORTB, PORTB0	; Si la led est éteinte, ignorer l'instruction suivante
	cbi	PORTB, PORTB0	; Eteindre la led
	ret			; Retour dans la boucle
