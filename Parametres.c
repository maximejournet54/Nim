#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "jeu.h"
#define MAX(nlig,ncol) ((nlig)>(ncol)? (nlig):(ncol))

int main ()
{
    int nlig, ncol, niveau, next, nban;
    printf("Parametres du jeu: \n");
    printf("nombre de lignes : \n");
    scanf("%d", &nlig);
    printf("nombre de colonnes : \n");
    scanf("%d", &ncol);
    printf("nombre de cases bannies generees : \n", nban);  
    /* probleme affichage nban  */
    printf("niveau de 1 a 4 \n");
    scanf("%d", &niveau);
    printf("qui commence la partie? \n ordinateur (1) ou le joueur (2) : \n");
    scanf("%d", &next);
    printf("\n C'est parti !");
    return 0;
}

int Parametres(int nlig, int ncol) /* ne s'execute pas*/
{
    int nban;
    srand(time(NULL));
    if (((nlig)<(VMIN)) && ((nlig)>(VMAX)))
    {
        printf("nombre de lignes saisies incorrect");
    }
    else if ((ncol<(VMIN)) && ((ncol)>(VMAX)))
    {
        printf("nombre de colonnes saisies incorrect");
    }
    else if (((rand())<(MAX(nlig,ncol))))
    {
        nban=rand();
    }
}
