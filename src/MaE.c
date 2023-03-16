
#include "../headers/MaE.h"

/***DEF des types de la machine à état***/

typedef enum {  INIT_ETAT, ACQUISITION_ETAT,
                DEP_GAUCHE_ETAT, DEP_DROITE_ETAT, DEP_HAUT_ETAT,DEP_BAS_ETAT,
                VERIF_VICTOIRE_ETAT, NB_ETAT} etat_t;

typedef enum {  key_q, key_d, key_z, key_s,
                next, not_valid, win, lose, NB_ENTREE} entree_t;

typedef enum {  NOP_A=0, dep_G_A, dep_D_A, dep_H_A, dep_B_A,
                VerifVictoire_A, QUITTE_A } action_t;

/***Table de transition de la machine a etat***/
typedef struct {
    etat_t etat_destination;
    action_t action;
} transition_t;

static transition_t tab_transition [NB_ETAT][NB_ENTREE] =
{
    //Initialisation
    [INIT_ETAT][NOP_A]                   = {ACQUISITION_ETAT, NOP_A},
    //Acquisition clavier et vérification de la validité du déplacement
    [ACQUISITION_ETAT][key_q]            = {DEP_GAUCHE_ETAT, dep_G_A},
    [DEP_GAUCHE_ETAT][not_valid]         = {ACQUISITION_ETAT, NOP_A},
    [ACQUISITION_ETAT][key_d]            = {DEP_DROITE_ETAT, dep_D_A},
    [DEP_DROITE_ETAT][not_valid]         = {ACQUISITION_ETAT, NOP_A},
    [ACQUISITION_ETAT][key_z]            = {DEP_HAUT_ETAT, dep_H_A},
    [DEP_HAUT_ETAT][not_valid]           = {ACQUISITION_ETAT, NOP_A},
    [ACQUISITION_ETAT][key_s]            = {DEP_BAS_ETAT, dep_B_A},
    [DEP_BAS_ETAT][not_valid]            = {ACQUISITION_ETAT, NOP_A},
    //Vérification Win/Lose
    [DEP_GAUCHE_ETAT][next]              = {VERIF_VICTOIRE_ETAT, VerifVictoire_A},
    [DEP_DROITE_ETAT][next]              = {VERIF_VICTOIRE_ETAT, VerifVictoire_A},
    [DEP_HAUT_ETAT][next]                = {VERIF_VICTOIRE_ETAT, VerifVictoire_A},
    [DEP_BAS_ETAT][next]                 = {VERIF_VICTOIRE_ETAT, VerifVictoire_A},
    //Win
    [VERIF_VICTOIRE_ETAT][win]           = {INIT_ETAT, QUITTE_A},
    //Lose
    [VERIF_VICTOIRE_ETAT][lose]          = {ACQUISITION_ETAT, NOP_A},
};

/***Variables Locales***/
static etat_t etat_courant;
static int current_player; //Joueur actuel
int nb_treasures_to_found;
Trap *traps[NB_TRAPS]; // Tableau des traps
Player *players[NB_PLAYERS]; //Tableau des joueurs
Treasure *treasures[NB_TREASURES]; //Tableau des trésors

/***Fonction Privee***/
static void run_MaE(entree_t commande);
static void performAction(action_t action);
static void deplacement(Player *player, char direction);

/***Fonctions interfaces (1 fonction = 1 entree clavier)***/
void MaE_Touche_q()
{
    run_MaE(key_q);
}
void MaE_Touche_d()
{
    run_MaE(key_d);
}
void MaE_Touche_z()
{
    run_MaE(key_z);
}
void MaE_Touche_s()
{
    run_MaE(key_s);
}
void MaE_Init()
{
    etat_courant = ACQUISITION_ETAT;
    nb_treasures_to_found = NB_TREASURES;
    //Initialisations
    map_initialisation();

    //Initialisation des traps
    for (int i = 0; i < NB_TRAPS; i++) {
        traps[i] = trap_initialisation(); // Créer un nouveau trap

        Coordinates coordinates_trap;
        trap_get_pos(traps[i],&coordinates_trap);
        map_set_case(coordinates_trap, "X");
    }
    //Initialisation des joueurs
    for (int i = 0; i < NB_PLAYERS; i++) {
        players[i] = player_initialisation(); // Créer un nouveau joueur
        Coordinates coordinates_player;
        player_get_pos(players[i], &coordinates_player); // Récupérer la position du joueur
        // Convertir le numéro du joueur en caractère et le passer à map_set_case
        char player_number_char = '0' + i + 1; // +1 pour avoir le numéro du joueur à partir de 1
        char player_number_str[2] = {player_number_char, '\0'}; // Créer une chaîne de caractères pour stocker le numéro du joueur
        //Rafraichissement de l'affichage
        map_set_case(coordinates_player, player_number_str); // Mettre à jour la carte avec la position du joueur
    }
    current_player = 0;

    //Initialisation des trésors
    for (int i = 0; i < NB_TREASURES; i++) {
        treasures[i] = treasure_initialisation(); // Créer un nouveau treasure

        Coordinates coordinates_treasure;
        treasure_get_pos(treasures[i],&coordinates_treasure);
        map_set_case(coordinates_treasure, "T");
    }

    //Initialisation de l'affichage de la carte
    map_print();
    printf("Au tour du joueur %d\n", current_player + 1);
}

/***Execution de la machine a etat du menu ***/
static void run_MaE(entree_t commande)
{
    transition_t tr_a_faire;
    tr_a_faire = tab_transition[etat_courant][commande];

    etat_courant = tr_a_faire.etat_destination;
    performAction(tr_a_faire.action);
}

static void deplacement(Player *player, char direction){


    if (player_is_eliminated(players[current_player])){
        system("clear");
        map_print();
        printf("Le joueur %d n'a plus de point de vie et ne peut donc pas jouer.\n", current_player +1);
        current_player = (current_player + 1) % NB_PLAYERS;
        printf("Au tour du joueur %d\n", current_player + 1);
        run_MaE(not_valid);
    } else{
        Coordinates coordinates_player;
        player_get_pos( player,&coordinates_player);
        map_set_case(coordinates_player, " ");

        if(!player_mouvement(player, direction)){
            run_MaE(not_valid);
        }
        player_get_pos( player,&coordinates_player);

        // Convertir le numéro du joueur en caractère et le passer à map_set_case
        char player_number_char = '0' + current_player + 1; // +1 pour avoir le numéro du joueur à partir de 1
        char player_number_str[2] = {player_number_char, '\0'}; // Créer une chaîne de caractères pour stocker le numéro du joueur
        map_set_case(coordinates_player, player_number_str); // Mettre à jour la carte avec la position du joueur

        //Rafraichissement de l'affichage
        system("clear");
        map_print();

        run_MaE(next);
    }
}

/***Execution des actions***/
static void performAction(action_t action)
{
    int player_life_points;
    int player_treasures_found;
    Coordinates coordinates_player;

    switch (action)
    {
    case NOP_A:
        break;
    case dep_G_A:
        deplacement(players[current_player],'q');
        break;
    case dep_D_A:
        deplacement(players[current_player],'d');
        break;
    case dep_H_A:
        deplacement(players[current_player],'z');
        break;
    case dep_B_A:
        deplacement(players[current_player],'s');
        break;
    case VerifVictoire_A:
        //Vérification trap des joueurs
        player_get_pos(players[current_player], &coordinates_player); // Récupérer la position du joueur
        if (trap_found(traps, coordinates_player)){
            player_hit_trap(players[current_player]);
        }
        // Vérification trésor des joueurs
        int treasure_index = treasure_found(treasures, coordinates_player);
        if (treasure_index != -1) {
            nb_treasures_to_found  = nb_treasures_to_found -1;
            player_treasure_found(players[current_player]);
            if (treasures[treasure_index] != NULL) {
                free(treasures[treasure_index]); // Libère la mémoire allouée au trésor
                treasures[treasure_index] = NULL; // Met à jour l'élément du tableau avec NULL
            }
            if (nb_treasures_to_found == 0) {
                run_MaE(win);
            } else {
                // Passe au joueur suivant
                current_player = (current_player + 1) % NB_PLAYERS;
                run_MaE(lose);
                printf("Vous avez trouvé un trésor ! Mais il en reste...\n");
                printf("Au tour du joueur %d\n", current_player + 1);
            }
        } else {
            // Passe au joueur suivant
            current_player = (current_player + 1) % NB_PLAYERS;
            run_MaE(lose);
            printf("Au tour du joueur %d\n", current_player + 1);
        }
        break;
    case QUITTE_A:
        system("clear");
        player_get_life_points(players[current_player], &player_life_points);
        player_get_treasures_found(players[current_player],&player_treasures_found);
        printf("Victoire ! le joueur %d a trouvé %d trésor(s) ! Il lui restait %d points de vie.\n",current_player+1, player_treasures_found,player_life_points);
        exit(0);
    default:
        break;
    }
}

