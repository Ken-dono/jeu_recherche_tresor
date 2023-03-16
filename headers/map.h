#include <stdint.h> // uint8_t
#include <stdlib.h>
#include "../utils/coordinates.h"

typedef struct {
    char **map;
    int nb_column;
    int nb_rows;
} Map;

void map_initialisation();
void map_print ();
char map_get_case(Coordinates coordinates);
void map_set_case(Coordinates coordinates, char *caractere);
void map_free();