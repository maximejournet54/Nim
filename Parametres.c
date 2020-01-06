#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "jeu.h"
#define MAX(nlig,ncol) ((nlig)>(ncol)? (nlig):(ncol)) /* fonction maximum entre nlig et ncol*/



int main ()
{
    int nlig, ncol, niveau, next, nban;
    printf("Parametres du jeu: \n");
    printf("nombre de lignes : \n");
    scanf("%d", &nlig);
    printf("nombre de colonnes : \n");
    scanf("%d", &ncol);
    if (((nlig)<(VMIN)) || ((nlig)>(VMAX)))
    {
        printf("nombre de lignes saisies incorrect \n");
    }
    else if ((ncol<(VMIN)) || ((ncol)>(VMAX)))
    {
        printf("nombre de colonnes saisies incorrect \n");
    }
    srand(time(NULL));
    if (((rand()%VMAX+0)<(MAX(nlig,ncol))))
    {
        nban=rand()%VMAX+0; /* entre 0 et VMAX*/
    }
    printf("nombre de cases bannies generees : %d \n", nban);  
    printf("niveau de 1 a 4: ");
    scanf("%d", &niveau);
    printf("qui commence la partie? \n");
    printf("ordinateur (1) ou le joueur (2) : ");
    scanf("%d", &next);
    printf("\nC'est parti ! \n");
    Affiche_Grille(nlig, ncol);
    return 0;
}

int Parametres(int nlig, int ncol) /* ne s'execute pas si main mis dans la fonction*/
{

}

