#include <stdio.h>
#include "jeu.h"

int main ()
{
    /* fonction Lire_Entier + Saisir_Entier */
    int N, K, i;
    printf("saisir un entier >0: ");
    N=saisir_entier(1);
    printf("saisir un entier compris entre 1 et %d", N);
    K=Saisir_Entier(1,N);
    for (i=K; i<=N; i=i+K)
    {
        printf("%d", i);
    }
    Lire_Entier(1,N,&K);
    /* fonction Lire_Entier + Saisir_Entier */
    return 0;

}
