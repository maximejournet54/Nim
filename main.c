#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jeu.h"
#include "fonctions.c"


/* problèmes à résoudre: nb cases bannies générées=-1, normalement impossible*/
int main ()
{
    /* début du jeu */
    int nlig, ncol, nban, niveau, i, j, next, verif=1, grille, p; /* p=probabilité que l'ordinateur joue un coup gagnant  */
    pion.ilig=1;
	pion.icol=1;
    srand((unsigned int)time(NULL)); /* initialisation de la graine */
    Parametres(&nlig, &ncol, &nban, &niveau, &next, verif); /* saisie des paramètres de jeu */
    while (verif==1) /* s'éxécute si les paramètres saisis sont corrects */
    {
        ban=Hasard_Ban(nban,&nlig,&ncol); /* génère pseudo-aléatoirement les coordonnées des cases bannies*/
	    for(i=0;i<nban;i++)
        {
		printf("\n %d : ligne", ban.tab[i].ilig);
		printf("\n %d : colonne", ban.tab[i].icol);		
	    }
	    printf("\n position pion : (%d,%d)\n",pion.ilig,pion.icol); 
        grille=Affiche_Grille(pion,ban,nlig,ncol,nban); /*affichage de la grille de jeu */
        Calcul_Nimbers(nim,nlig,ncol,nban,ban); 
    while(1)
	{
		if(next%2==0) /* cas où le joueur commence la partie */
		{
			pion=Coup_Joueur(pion,nban,ban,nlig,ncol);
		}
		else		 /* cas où l'ordinateur commence la partie */
		{
			if(niveau==1) 	/* coup de l'ordinateur selon le niveau de difficulté*/
			{
				pion=Coup_Ordi_Hasard(pion,nban,ban,nlig,ncol);
			}
			else if(niveau==2)
			{
				p=rand()%3;
				if(p==0)
					pion=Coup_Ordi_Gagnant(pion,nban,ban,nlig,ncol,nim);
				else
					pion=Coup_Ordi_Hasard(pion,nban,ban,nlig,ncol);
			}
			else if(niveau=3)
			{
				p=rand()%3;
				if(p==0)
					pion=Coup_Ordi_Hasard(pion,nban,ban,nlig,ncol);
				else
					pion=Coup_Ordi_Gagnant(pion,nban,ban,nlig,ncol,nim);
			}
			else
				pion=Coup_Ordi_Gagnant(pion,nban,ban,nlig,ncol,nim);
		}
		grille=Affiche_Grille(pion,ban,nlig,ncol,nban);
		if(pion.ilig==nlig && pion.icol==ncol) /* fin de la partie */
		{
			if(next%2==0)
            {
				printf("C'est gagné !");
            }
			else
				printf("C'est perdu !");
            return 0; 
		}
		next++;
		}    
    /* fin du jeu */ 
    }
}
