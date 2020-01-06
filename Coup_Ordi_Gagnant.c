#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"

int main ()
{
    return 0;
}

int Coup_Ordi_Gagnant(int i, int j)
{
    int nlig, ncol;
    do
    {
        if ((i+1) == 0) /* 0 si nimber=0, utiliser booleen pour nimber*/ 
    {
        i=i+1;
    }
    else if ((i+2) == 0)
    {
            i=i+2;
    }
    if ((j+1) == 0)
    {
        j=j+1;
    }
    else if ((j+2) == 0)
    {
        j=j+2;
    }
    else
    {
        Coup_Ordi_Hasard();
    }
    } while ((i!=nlig) && (j!=ncol));
}