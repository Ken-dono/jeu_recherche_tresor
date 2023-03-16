//
// Created by buryhugo on 03/03/23.
//
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "../utils/coordinates.h"
#include "../config.h"

typedef struct Treasure_t Treasure;

Treasure* treasure_initialisation(void);
int treasure_found(Treasure *treasures[], Coordinates coordinates);
void treasure_get_pos(Treasure *this, Coordinates *coordinates);