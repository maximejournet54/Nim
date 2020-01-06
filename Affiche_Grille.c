#include <stdio.h>
#include "jeu.h"

int main()
{
    return 0;
}

int Affiche_Grille(int nlig, int ncol)
{
int i, j;
    for (i=0; i<=nlig-1; i++) 
    {
        for (j=0; j<=ncol-1; j++)  /* problème: le dernier caractère du tableau est "-" et pas "|" */ 
        {  
            {   
                printf("|"); /* code ASCII pour cases */
                printf("-");
            }    
        }
        printf("|");
        printf("\n");
    }
}