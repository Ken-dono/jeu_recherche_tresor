//
// Created by buryhugo on 11/03/23.
//

#include "divers.h"

static bool time_srand_reset = false;

int get_random_number(){
    // Initialisation de la fonction de génération de nombres aléatoires
    if (time_srand_reset == false) {
        srand(time(NULL));
        time_srand_reset = true;
    }
    return rand();
}