#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jeu.h"
#include "fonctions.c"


/* problèmes à résoudre: nb cases bannies générées=-1, normalement impossible*/
int main ()
{
    /* début du jeu */
    int nlig, ncol, nban, niveau, i, j, next, null=0, verif=1, grille, p;
    pion.ilig=1;
	pion.icol=1;
    srand((unsigned int)time(NULL));
    Parametres(&nlig, &ncol, &nban, &niveau, &next, verif); 
    while (verif==1) /* s'éxécute si les paramètres sont corrects */
    {
        ban=Hasard_Ban(nban,&nlig,&ncol);
        printf("%d %d %d %d %d",nlig,ncol,niveau,next,nban);
	    for(i=0;i<nban;i++)
        {
		printf("\n %d : ligne", ban.tab[i].ilig);
		printf("\n %d : colonne", ban.tab[i].icol);		
	    }
	    printf("\n position pion : (%d,%d)\n",pion.ilig,pion.icol);
        grille=Affiche_Grille(pion,ban,nlig,ncol,nban);
        Calcul_Nimbers(nim,nlig,ncol,nban,ban);
    while(1)
	{
		if(next%2==0)
		{
			pion=Coup_Joueur(pion,nban,ban,nlig,ncol);
		}
		else
		{
			if(niveau==1)
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
		if(pion.ilig==nlig && pion.icol==ncol)
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
