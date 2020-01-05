#include <stdio.h>
#include "jeu.h"

int main ()
{
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
    return 0;
}

int Saisir_Entier(int bi, int bs)

{
    int n;
    do
    {
        scanf("%d", &n);
    } while ((n<bi) || (n>bs));
    return n;
}

void Lire_Entier(int bi, int bs, int *n)

{
    do scanf("%d", n);
    while (((*n)<bi) || ((*n)>bs)));
}
/* erreur de compilation */