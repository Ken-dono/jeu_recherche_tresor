C_FILES :=$(wildcard ./src/*.c)
H_FILES :=$(wildcard ./headers/*.h)
U_C_FILES :=$(wildcard ./utils/*.c)
U_H_FILES :=$(wildcard ./utils/*.h)
MAIN_FILES :=$(wildcard ./*.c)
.SILENT: all

all:
	gcc $(MAIN_FILES) $(C_FILES) $(H_FILES) $(U_C_FILES) $(U_H_FILES) -o ./jeu_recherche_tresor_exe
