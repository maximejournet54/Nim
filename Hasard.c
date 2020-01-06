#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"

int main()
{
    int nbh; /* nombre généré au hasard*/
    srand(time(NULL)); 
    nbh=rand()%(VMAX-VMIN) +VMIN; /* génère nombre pseudo-aléatoire compris entre VMIN et VMAX (5 et 30)*/
    /* à enlever*/ printf("nbh=: %d", nbh); /* à enlever*/
    return 0;
}
/* cette fonction sert à générer un nombre pour la fonction Coup_Ordi_Hasard*/ 