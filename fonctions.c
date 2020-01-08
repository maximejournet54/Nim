#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jeu.h"
#define MAX(nlig,ncol) ((nlig)>(ncol)? (nlig):(ncol)) /* donne le maximum entre nlig et ncol*/



int Affiche_Grille(int nlig, int ncol) /* affiche la grille de jeu à chaque tour*/
{
int i, j;
    for (i=0; i<=nlig-1; i++) 
    {
        for (j=0; j<=ncol-1; j++)  
        {  
            {   
                printf("|"); /* code ASCII pour cases */
                printf("-");
            }    
        }
        printf("| \n");
    }
}

int Hasard_Ban(int i, int j, int nbanh) /* génère pseudo-aléatoirement les cases bannies, compris entre 1 et nban*/
{
    int nban;
    srand(time(NULL));
    nbanh= rand()%(nban-1) +1;
    nbanh=ban[30];
}
    
  

int Hasard(int nbh) /* génère un nombre pseudo-aléatoire  pour la fonction Coup_Ordi_Hasard*/ 
{
    srand(time(NULL)); 
    nbh=rand()%(VMAX-VMIN) +VMIN; /* génère nombre pseudo-aléatoire compris entre VMIN et VMAX (5 et 30)*/
}


int Parametres(int nlig, int ncol) /* demande et saisit les paramètres de jeu */
{
    int niveau, nban, next;
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
    if (((rand()%VMAX+0)<(MAX(nlig,ncol)))) /* génère pseudo-aléatoirement le nombre de cases bannies */
    {
        nban=rand()%(VMAX-0) +0; /* entre 0 et VMAX*/
    }
    printf("nombre de cases bannies generees : %d \n", nban);  
    printf("niveau de 1 a 4: ");
    scanf("%d", &niveau);
    printf("qui commence la partie? \n");
    printf("ordinateur (1) ou le joueur (2) : ");
    scanf("%d", &next);
    printf("\nC'est parti ! \n");
}

int Saisir_Entier()
{
    int n;
    do
    {
        scanf("%d", &n);
    } while ((n<VMIN) || (n>VMAX));
    return n;
}

void Lire_Entier(int *n) /* lit un entier compris entre VMIN et VMAX (5 et 30)*/
{
    do
    {
         scanf("%d", &n);
    } while (((*n)<VMIN) || ((*n)>VMAX));
}

int Coup_Ordi_Gagnant(int i, int j) /* génère le coup gagnant de l'ordi */
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

int Coup_Joueur() /* texte affiché à chaque tour du joueur */ 
{
    int pos, nb_destination; 
    printf(" \n A toi de jouer ! \n");
    /*  mettre des if selon la destination possible*/
    if (nb_destination >1)
    {
        printf("choisir la destination 1 : %d  2: %d  3: %d  4: %d \n", pos, pos, pos, pos);
    }
    else
    {
        printf("seule possibilité : %d", pos);
    }
    
    
}

int Coup_Ordi() /* texte affiché à chaque tour de l'ordi */ 
{
    int pos; /* à remplacer par les coordonnées de la case */
    printf("l'ordinateur déplace le pion en %d", pos);
}

int Coup_Ordi_Hasard() /* génère pseudo-aléatoirement le coup de l'ordi si le coup n'est pas gagnant */ 
{

}

int Calcul_Nimbers() /* remplit la grille au début de partie par des 0 et des 1 */
{

}