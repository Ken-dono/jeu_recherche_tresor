cmake_minimum_required(VERSION 3.24)
project(jeu_increment_4 C)

set(CMAKE_C_STANDARD 11)

add_executable(jeu_increment_4 main.c ./headers/map.h ./headers/player.h config.h ./headers/getch.h ./headers/MaE.h ./headers/treasure.h ./src/getch.c ./src/MaE.c ./src/map.c ./src/player.c ./src/treasure.c src/trap.c utils/coordinates.h utils/coordinates.c utils/divers.c utils/divers.h)
