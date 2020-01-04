#include <stdio.h>
#include "jeu.h"

int main ()
{
    int i, j;
    for (i=0; i<=VMAX-1; i++) 
    {
        for (j=0; j<=VMAX-1; j++)  /* problème: le dernier caractère du tableau est "-" et pas "|" */ 
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