#include <stdio.h>
#include <time.h>
#include "max.c"

int main ()
{
    int nlig, ncol, niveau, next, nban;
    srand((unsigned int)time(NULL));
    printf("saisir le nombre de lignes");
    scanf("%d", &nlig);
    printf("saisir le nombre de colonnes");
    scanf("%d", &ncol);
    printf("saisir le niveau de difficulté");
    scanf("%d", &niveau);
    printf("saisir qui commence la partie: 1=ordinateur, 2=joueur");
    scanf("%d", &next);
    if(rand()<Max(nlig,ncol))   nban=srand();
}

