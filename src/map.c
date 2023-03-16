#include <stdio.h> //printf
#include <stdint.h> // uint8_t
#include "../headers/map.h"
#include "../config.h"
#include "../utils/coordinates.h"

Map grid;

void map_initialisation(){
    grid.nb_column = COLONNE;
    grid.nb_rows = LIGNE;

    //Allocation de la mémoire
    grid.map = (char **)malloc(grid.nb_rows * sizeof(char *));
    for (int i = 0; i < grid.nb_rows; i++) {
        grid.map[i] = (char *)malloc(grid.nb_column * sizeof(char));
    }

    //Remplissage du tableau
    for(int i=0; i< grid.nb_rows; i++)
    {
        for(int j=0; j<grid.nb_column; j++)
        {
            grid.map[i][j] = ' ';
        }
    }
}
void map_print ()
{
    for(int j= 0; j<grid.nb_rows; j++)
    {
        //ligne de delimitation
        for(int i=0; i<grid.nb_column; i++)
        {
            printf("+---");
        }
        printf("+\n");
        //ligne de contenu
        for(int i=0; i<grid.nb_column; i++)
        {
            printf("| ");
            printf("%c",grid.map[j][i]); //contenu
            printf(" ");
        }
        printf("|\n");
    }
    //ligne de delimitation
    for(int i=0; i<grid.nb_column; i++)
    {
        printf("+---");
    }
    printf("+\n");
}
char map_get_case(Coordinates coordinates){
    return grid.map[coordinates.x][coordinates.y];
}
void map_set_case(Coordinates coordinates, char *caractere){
    grid.map[coordinates.x][coordinates.y] = *caractere;
}

void map_free(){
    //Liberation de la memoire pour le tableau
    for (int i = 0; i < grid.nb_rows; i++) {
        free(grid.map);
    }
    free(grid.map);
}