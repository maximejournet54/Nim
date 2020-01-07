#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jeu.h"
#define MAX(nlig,ncol) ((nlig)>(ncol)? (nlig):(ncol)) /* fonction maximum entre nlig et ncol*/



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

int Hasard(int nbh)
{
    srand(time(NULL)); 
    nbh=rand()%(VMAX-VMIN) +VMIN; /* génère nombre pseudo-aléatoire compris entre VMIN et VMAX (5 et 30)*/
    /* à enlever*/ printf("nbh=: %d", nbh); /* à enlever*/
    return 0;
}
/* cette fonction sert à générer un nombre pour la fonction Coup_Ordi_Hasard*/ 

int Parametres(int nlig, int ncol) /* ne s'execute pas si main mis dans la fonction*/
{
    int niveau, next, nban;
    printf("Parametres du jeu: \n");
    printf("nombre de lignes : \n");
    scanf("%d", &nlig);
    printf("nombre de colonnes : \n");
    scanf("%d", &ncol);
    if (((nlig)<(VMIN)) || ((nlig)>(VMAX)))
    {
        printf("nombre de lignes saisies incorrect \n");
    }
    else if ((ncol<(VMIN)) || ((ncol)>(VMAX)))
    {
        printf("nombre de colonnes saisies incorrect \n");
    }
    srand(time(NULL));
    if (((rand()%VMAX+0)<(MAX(nlig,ncol))))
    {
        nban=rand()%VMAX+0; /* entre 0 et VMAX*/
    }
    printf("nombre de cases bannies generees : %d \n", nban);  
    printf("niveau de 1 a 4: ");
    scanf("%d", &niveau);
    printf("qui commence la partie? \n");
    printf("ordinateur (1) ou le joueur (2) : ");
    scanf("%d", &next);
    printf("\nC'est parti ! \n");
    Affiche_Grille(nlig, ncol);
}

int Saisir_Entier(int VMIN, int VMAX)

{
    int n;
    do
    {
        scanf("%d", &n);
    } while ((n<VMIN) || (n>VMAX));
    return n;
}

void Lire_Entier(int VMIN, int VMAX, int *n)

{
    do
    {
         scanf("%d", &n);
    } while (((*n)<VMIN) || ((*n)>VMAX)));
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