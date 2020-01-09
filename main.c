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
    int nlig, ncol, i, j, next, null=0, verif=1;
    Parametres(nlig, ncol, verif);
    while (verif==1) /* s'éxécute si les paramètres sont corrects */
    {
        Calcul_Nimbers(nlig, ncol, null);
    if (next==1) /* si l'ordinateur commence la partie, l'ordinateur joue*/
    {
        Coup_Ordi_Gagnant(i, j, null);
        Coup_Ordi();
    }
    if(next==2) /* si le joueur commence la partie, le joueur joue */
    {
        Coup_Joueur(nlig, ncol);
    }
    return 0;     /* fin du jeu */ 
    }
}
