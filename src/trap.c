//
// Created by buryhugo on 10/03/23.
//

#include "../headers/trap.h"

struct Trap_t {
    Coordinates coordinates;
};

Trap * trap_initialisation(void) {
    Trap * this = NULL; // Initialise à NULL
    this = malloc(sizeof(Trap)); // Alloue dynamiquement un Trap
    if (this == NULL) {
        // Gestion de l'erreur d'allocation mémoire
        return NULL;
    }
    // Choix aléatoire des coordonnées du trésor
    this->coordinates = coordinates_generate_coords(); // Génère les coordonnées du trap avec la fonction coordinates_generate_coords
    return this;
}

bool trap_found(Trap *traps[], Coordinates coordinates){
    // Vérification de la présence d'un trap à une certaine position
    for (int i = 0; i<NB_TRAPS; i++) {
        Coordinates coordinates_trap;
        trap_get_pos(traps[i], &coordinates_trap); // Récupérer la position du trap
        if (coordinates_trap.x == coordinates.x && coordinates_trap.y == coordinates.y){
            return true; // Retourne vrai si un trap est trouvé à cette position
        }
    }
    return false; // Retourne faux si aucun trap n'est trouvé à cette position
}

void trap_get_pos(Trap *this, Coordinates *coordinates) {
    *coordinates = this->coordinates; // Récupère les coordonnées du trap
}
