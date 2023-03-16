#include "headers/getch.h"
#include <stdio.h>
#include "headers/MaE.h"

int main()
{
    char car;
    MaE_Init();
    while(1) {
        printf("Entrez une commande \n");
        car = getch();
        switch (car) {
            case 'q':
                MaE_Touche_q();
                break;
            case 'd':
                MaE_Touche_d();
                break;
            case 'z':
                MaE_Touche_z();
                break;
            case 's':
                MaE_Touche_s();
                break;
            default:
                break;
        }
    }
}


