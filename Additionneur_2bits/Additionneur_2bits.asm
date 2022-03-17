;
; Additionneur_2bits.asm
;
; Created: 14/03/2022 22:22:17
; Author : Tequhella
;

; ====================================
;                ATtiny
;               25/45/85
;              +--------+
;        PB5 --+ o  Vcc +------------
;		 PB3 --+        +-- PB2
;        PB4 --+        +-- PB1
;  ------------+ GND    +-- PB0
;              +--------+
; ====================================

start:
    sbr		r16, (1 << DDB0) | (1 << DDB1)
	out		DDRB, r16						; Port 0 et 1 définit en tant que sortie
	sbi		PORTB, PORTB3					; Port 3 définit en tant qu'entrée

boucle:
	clr		r16					; Registre 16 vidé
	clr		r18					; Registre 18 vidé
	sbr		r17, (1 << PORTB3)
	in		r18, PINB			; Registre 18 prend la valeur définit de PINB
	sbr		r16, (1 << PB3)
	and		r16, r18			; Comparaison entre les registres 16 et 18
	brbs	SREG_Z, increm		; Si égal, alors appeler à la sous routine increm
	cpi		r17, 0x0B			; Comparaison du registre 19 après incrémentation, avec la valeur 0x03
	breq	renitR19			; Si égal, alors appeler à la sous routine renitR19
	out		PORTB, r17			; LED ON selon le résultat de l'incrémentation
	rcall	boucle

increm:
	inc		r17			; Incrémentation du registre 19
	rcall	tempo		; Appel de la sous routine delay
	rcall	boucle

renitR19:
	subi	r17, 0x03	; Soustraction du registre 19 avec la valeur 0x03
	rcall	boucle

tempo:
	ldi		r20, 0xff
tempo2:
	ldi		r21, 0xff
tempo3:
	dec		r21				; Décrémentation du registre 21
	brbc	SREG_Z, tempo3	; Si le registre 21 n'est pas à 0x00, alors retour à la sous routine tempo3
	dec		r20				; Décrémentation du registre 20
	brbc	SREG_Z,	tempo2	; Si le registre 20 n'est pas à 0x00, alors retour à la sous routine tempo2
	ret