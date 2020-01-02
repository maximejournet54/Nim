#include <stdio.h>

int main ()
{
    int N;
    printf("saisir un entier >0: ");
    N=saisir_entier(1);
    Lire_Entier(1, &N);
    return 0;
}

int Saisir_Entier(int bi)

{
    int n;
    do
    {
        scanf("%d", &n);
    } while (n<bi);
    return n;
}

void Lire_Entier(int bi, int *n)

{
    do scanf("%d", n);
    while (n<bi);
}
