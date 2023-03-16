//
// Created by buryhugo on 11/03/23.
//

#ifndef JEU_INCREMENT_3_COORDINATES_H
#define JEU_INCREMENT_3_COORDINATES_H

#include "../config.h"
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct {
    int x;
    int y;
}Coordinates;

Coordinates coordinates_generate_coords(void);

#endif //JEU_INCREMENT_3_COORDINATES_H
