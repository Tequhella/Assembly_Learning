;
; Entree_Sortie.asm
;
; Created: 05/03/2022 23:20:33
; Author : Tequhella
;

start:
	sbi	DDRB, DDB0	; Pin 0 définit en tant que sortie
	sbi	PORTB, PORTB1	; Résistance de tirage activé

; Boucle principale
boucle:
	sbic	PINB, PINB1	; Vérifie si l'état du pin 1 est à  0
	rcall	ledOFF		; Appelle de la sous routine ledOFF
	rcall	ledON		; Appelle de la sous routine ledON
	rjmp	boucle		; Retour de boucle

; Sous-routine ledOFF : Désactive la LED
ledOFF:
	sbic	PORTB, PORTB0	; Si la led est éteinte, ignorer l'instruction extinction
	cbi	PORTB, PORTB0	; Eteindre la led
	rjmp	boucle		; Retour dans la boucle

; Sous-routine ledON : Active la LED
ledON:
	sbis	PORTB, PORTB0	; Si la led est allumé, ignorer l'instruction d'allumage
	sbi	PORTB, PORTB0	; Allume la led
	ret			; retour dans la boucle
