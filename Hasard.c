#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"

int main()
{
    int nbh; /* valeurs données et nombre généré au hasard*/
    srand(time(NULL)); 
    nbh=rand()%VMAX+VMIN; /* entre VMIN et VMAX*/
    /* à enlever*/ printf("nbh=: %d", nbh); /* à enlever*/
    return 0;
}
/* cette fonction sert à générer un nombre pour la fonction Coup_Ordi_Hasard*/ 