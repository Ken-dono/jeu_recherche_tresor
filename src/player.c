//
// Created by buryhugo on 03/03/23.
//

#include "../headers/player.h"

// Définition d'une structure pour représenter le joueur
struct Player_t{
    Coordinates coordinates;
    int life_points;
    int treasures_found;
    bool is_eliminated;
} ;

// Fonction d'initialisation du joueur
Player *  player_initialisation(void){
    Player * this = NULL; // Initialise à NULL
    this = malloc(sizeof(Player)); // Alloue dynamiquement un Trap
    if (this == NULL) {
        // Gestion de l'erreur d'allocation mémoire
        return NULL;
    }
    // Choix aléatoire des coordonnées du trésor
    this->coordinates = coordinates_generate_coords(); // Génère les coordonnées du trap avec la fonction coordinates_generate_coords
    this->life_points = MAX_PV_PLAYER;
    this->treasures_found = 0;
    this->is_eliminated = false;
    return this;
}

// Fonction pour récupérer les coordonnées du joueur
void player_get_pos(Player *this, Coordinates *coordinates) {
    *coordinates = this->coordinates; // Récupère les coordonnées du trap
}

// Fonction pour récupérer les points de vie du joueur
void player_get_life_points(Player *this, int *life_points){
    *life_points = this->life_points; // On assigne les points de vie du joueur à l'adresse fournie
}

// Fonction pour récupérer les trésors trouvés du joueur
void player_get_treasures_found(Player *this, int *treasures_found){
    *treasures_found = this->treasures_found; // On assigne les trésors trouvés du joueur à l'adresse fournie
}

// Fonction pour savoir si un player est éliminé
bool player_is_eliminated(Player *this){
    return this->is_eliminated;
}

// Fonction pour faire perdre des points de vie au joueur quand il tombe dans un piège
bool player_hit_trap(Player *this){
    if (this->life_points - HP_LOSS_TRAP > 0){ // Si le joueur peut perdre des points de vie sans mourir
        this->life_points = this->life_points - HP_LOSS_TRAP; // On lui retire les points de vie
        return true;
    } else{
        this->is_eliminated = true;
        return false;
    }
}

void player_treasure_found(Player *this) {
    this->treasures_found++; // Incrémente le nombre de trésors trouvés par le joueur
}


// Fonction pour déplacer le joueur
bool player_mouvement(Player *this, char direction){
    switch (direction) {
        // Si la direction est 'z', on déplace le joueur vers le haut s'il n'est pas sur la première ligne
        case 'z':
            if (this->coordinates.x > 0) {
                this->coordinates.x --;
                return true;
            } else  {
                return false;
            }
            // Si la direction est 's', on déplace le joueur vers le bas s'il n'est pas sur la dernière ligne
        case 's':
            if (this->coordinates.x  < LIGNE - 1) {
                this->coordinates.x ++;
                return true;
            }else  {
                return false;
            }
            // Si la direction est 'q', on déplace le joueur vers la gauche s'il n'est pas sur la première colonne
        case 'q':
            if (this->coordinates.y > 0) {
                this->coordinates.y--;
                return true;
            }else  {
                return false;
            }
            // Si la direction est 'd', on déplace le joueur vers la droite s'il n'est pas sur la dernière colonne
        case 'd':
            if (this->coordinates.y < COLONNE - 1) {
                this->coordinates.y++;
                return true;
            }else  {
                return false;
            }
            // Si la direction est invalide, on retourne false
        default:
            return false;
    }
}