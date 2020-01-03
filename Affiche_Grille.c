#include <stdio.h>
#include "jeu.h"

int main ()
{
    int nlig, ncol, i, j;
    for (nlig=0; nlig<=VMAX-1; i++) 
    {
        for (ncol=0; ncol<=VMAX-1; j++)  /* remplacer 5 par VMAX-1  et i et j par nlig et ncol */ 
        {  
            {
                printf("|");
                printf("-");
            }    
        }
        printf("\n");
    }
    return 0;
}