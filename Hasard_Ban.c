#include <stdio.h>
#include "jeu.h"

int main()
{
    return 0;
}

int Hasard_Ban(int i, int j, int nbanh)
{
    int nban, nlig, ncol;
    srand(time(NULL));
    nbanh= rand()%nban+1;
    nbanh=ban[30];
    if (((i=1)&&(j=1)) || ((i=nlig)&&(j=ncol)))
    {
        return 0; /* case de départ et puit ne peuvent pas être bannis*/ 
    }
    if (/* condition */) /* case non bannie doit être accessible depuis la case de départ*/
    {
        /* code */  
    }
    if (/* condition */) /* pion ne doit pas être bloqué dans une case autre que le puit*/ 
    {
        /* */
    }
}