//
// Created by buryhugo on 03/03/23.
//

#include "../headers/treasure.h"

struct Treasure_t{
    Coordinates coordinates;
};

Treasure * treasure_initialisation(void) {
    Treasure * this = NULL; // Initialise à NULL
    this = malloc(sizeof(Treasure)); // Alloue dynamiquement un Treasure
    if (this == NULL) {
        // Gestion de l'erreur d'allocation mémoire
        return NULL;
    }
    // Choix aléatoire des coordonnées du trésor
    this->coordinates = coordinates_generate_coords(); // Génère les coordonnées du trap avec la fonction coordinates_generate_coords
    return this;
}

int treasure_found(Treasure *treasures[], Coordinates coordinates){
    // Vérification de la présence d'un treasure à une certaine position
    for (int i = 0; i < NB_TREASURES; i++) {
        if (treasures[i] != NULL) {
            Coordinates coordinates_treasure;
            treasure_get_pos(treasures[i], &coordinates_treasure); // Récupérer la position du treasure
            if (coordinates_treasure.x == coordinates.x && coordinates_treasure.y == coordinates.y){
                return i; // Retourne l'indice du trésor trouvé à cette position
            }
        }
    }
    return -1; // Retourne -1 si aucun trésor n'est trouvé à cette position
}

void treasure_get_pos(Treasure *this, Coordinates *coordinates) {
    *coordinates = this->coordinates; // Récupère les coordonnées du treasure
}