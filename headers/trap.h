//
// Created by buryhugo on 10/03/23.
//

#ifndef JEU_INCREMENT_3_TRAP_H
#define JEU_INCREMENT_3_TRAP_H

#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "../config.h"
#include "../utils/coordinates.h"

typedef struct Trap_t Trap;

Trap* trap_initialisation(void);
bool trap_found(Trap *traps[], Coordinates coordinates);
void trap_get_pos(Trap *this, Coordinates *coordinates) ;

#endif //JEU_INCREMENT_3_TRAP_H
