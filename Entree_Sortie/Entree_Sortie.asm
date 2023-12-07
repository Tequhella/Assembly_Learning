;
; Entree_Sortie.asm
;
; Created: 05/03/2022 23:20:33
; Author : Tequhella
;

.DEVICE ATTiny25

.equ PORTB = 0x18
.equ DDRB = 0x17
.equ PINB = 0x16

.equ PORTB0 = 0
.equ PORTB1 = 1
.equ DDB0 = 0
.equ PINB1 = 1

start:
    sbi	DDRB, DDB0	    ; Pin 0 définit en tant que sortie
    sbi	PORTB, PORTB1	; Résistance de tirage activé

; Boucle principale
boucle:
    sbic	PINB, PINB1	; Vérifie si l'état du pin 1 est à  0
    rcall	ledON		; Appelle de la sous routine ledON
    sbis	PINB, PINB1	; Vérifie si l'état du pin 1 est à  1
    rcall	ledOFF		; Appelle de la sous routine ledOFF
    rjmp	boucle		; Retour de boucle

; Sous-routine ledOFF : Désactive la LED
ledOFF:
    cbi	    PORTB, PORTB0	; Eteindre la led
    ret			            ; retour dans la boucle

; Sous-routine ledON : Active la LED
ledON:
    sbi	    PORTB, PORTB0	; Allume la led
    ret			            ; retour dans la boucle
