//
// Created by buryhugo on 11/03/23.
//
#include "coordinates.h"
#include "divers.h"

// La taille de la variable statique est définie ici
#define MAX_COORDS NB_TRAPS + NB_TREASURES + NB_PLAYERS
static Coordinates already_attributed_coords[MAX_COORDS];

Coordinates coordinates_generate_coords(void) {
    int x = get_random_number();
    int y = get_random_number();

    Coordinates coordinates;
    coordinates.x = x % LIGNE;
    coordinates.y = y % COLONNE;

    for (int i = 0; i < MAX_COORDS; ++i) {
        // Vérifie si les coordonnées sont déjà attribuées
        if(already_attributed_coords[i].x == coordinates.x && already_attributed_coords[i].y == coordinates.y){
            // Si oui, génère de nouvelles coordonnées
            coordinates = coordinates_generate_coords();
            // Et sort de la boucle
            break;
        }else if(i == MAX_COORDS - 1){
            // Si on est à la fin de la boucle et que les coordonnées n'ont pas été trouvées,
            // on les ajoute au tableau des coordonnées attribuées et on retourne ces coordonnées
            already_attributed_coords[i] = coordinates;
            return coordinates;
        }
    }
    // On retourne les coordonnées générées
    return coordinates;
}
