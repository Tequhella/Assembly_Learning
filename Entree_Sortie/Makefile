# Makefile pour le projet Entree_Sortie
# Peut être utilisé pour d'autres projets en modifiant les variables MCU, F_CPU et en le nom du fichier asm à compiler

MCU=attiny25			# microcontrôleur utilisé
F_CPU=8000000			# fréquence du microcontrôleur
CC=avr-gcc				# compilateur
OBJCOPY=avr-objcopy		# convertisseur de format
AVRDUDE=avrdude			# programmateur
CFLAGS=-g -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU) # options de compilation

# règle par défaut
all: Entree_Sortie.hex

# règles de compilation
Entree_Sortie.hex: Entree_Sortie.asm
	avra -o $@ $<

# règles de programmation
flash: Entree_Sortie.hex
	$(AVRDUDE) -c usbtiny -p $(MCU) -U flash:w:$<

# règles de nettoyage
clean:
	rm -f Entree_Sortie.hex Entree_Sortie.obj Entree_Sortie.cof Entree_Sortie.eep.hex Entree_Sortie.lss

# règles de phony
.PHONY: all flash clean