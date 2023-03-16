//
// Created by buryhugo on 03/03/23.
//
#include <stdint.h> // uint8_t
#include <stdlib.h>
#include <stdbool.h>
#include "../utils/coordinates.h"
#include "../config.h"

typedef struct Player_t Player;

Player *  player_initialisation(void);
void player_get_pos(Player *this, Coordinates *coordinates) ;
void player_get_life_points(Player *this, int *life_points);
bool player_hit_trap(Player *this);
bool player_mouvement(Player *this, char direction);
void player_treasure_found(Player *this);
void player_get_treasures_found(Player *this, int *treasures_found);
bool player_is_eliminated(Player *this);
