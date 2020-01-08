#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jeu.h"
#include "fonctions.c"

int main ()
{
    /* fonction Lire_Entier + Saisir_Entier 
    int N, K, i, nlig, ncol;
    printf("saisir un entier >0: ");
    N=saisir_entier(1);
    printf("saisir un entier compris entre 1 et %d", N);
    K=Saisir_Entier(1,N);
    for (i=K; i<=N; i=i+K)
    {
        printf("%d", i);
    }
    Lire_Entier(1);
    */

    /* début du jeu */
    int nlig, ncol, i, j, next;
    Parametres(nlig, ncol);
    Calcul_Nimbers();
    Affiche_Grille(nlig, ncol); /* grille ne s'affiche pas*/ 
    if (next==1)
    {
        Coup_Ordi_Gagnant(i, j);
        Coup_Ordi();
    }
    else
    {
        Coup_Joueur();
    }
   
    /* fin du jeu */ 
    return 0; 
}
