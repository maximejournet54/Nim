#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "jeu.h"

int Affiche_Grille(struct T_Case pion, struct T_Tab_Case ban, int nlig, int ncol, int nban) /* affiche la grille de jeu à chaque tour*/
{
    int i,j,k;
	char l1[50]="  ";
	char col[10]="";
	char lig[50]="";
	char car='-';
	char cases[10]="";
	char test[50]="";
	for(i=1; i<=ncol; i++)
	{
		sprintf(col,"  %d",i);
		strcat(l1,col);

	}
	printf("%s\n",l1);
	for(j=1; j<=nlig; j++)
	{
		sprintf(lig,"%d  ",j);
		for(i=1; i<=ncol; i++)
		{
			if(nban==0)
			{
				if((pion.ilig==j)&&(pion.icol==i))
					car='0';
				else
					car='-';
			}
			else{
				for(k=0;k<nban;k++)
				{
					if((ban.tab[k].ilig==j)&&(ban.tab[k].ilig==i))
					{
						car='X';
						break;
					}
					else if((pion.ilig==j)&&(pion.ilig==i))
						car='0';
					else
						car='-';
				}
			}
			
			sprintf(cases,"|%c|",car);
			strcat(test,cases);
		}
		strcat(lig,test);
		printf("%s\n",lig);
		sprintf(test,"");
	}
	return 0;
}

struct T_Tab_Case Hasard_Ban(int nban, int *nlig, int *ncol) /* génère pseudo-aléatoirement les cases bannies, compris entre 1 et nban*/
{
    int lig, col, i, j, bannissable;
    struct T_Tab_Case tab_cases_bannies;
    for (i=0; i<=nban; i++)
    {
        do
        {
            lig=rand()%Max(nlig,ncol)+1;
			col=rand()%Max(nlig,ncol)+1;
			bannissable=1;
            for (j=0; j<nban; j++)
            {
                if((tab_cases_bannies.tab[j].ilig==lig)&&(tab_cases_bannies.tab[j].ilig==col))
				{
					bannissable=0;
					break;
				}
				else if((tab_cases_bannies.tab[j].ilig==lig+1)&&(tab_cases_bannies.tab[j].icol==col-1))
				{
					bannissable=0;
					break;
				}
				else if((tab_cases_bannies.tab[j].ilig==lig-1)&&(tab_cases_bannies.tab[j].icol==col+1))
					{
						bannissable=0;
						break;
					}
            }
            
        } while ((lig==1 && col<*ncol) || (col==1 && lig<*nlig) ||(lig==*nlig && col>1) || (col==*ncol && lig>1));
        tab_cases_bannies.tab[i].ilig=lig;
	    tab_cases_bannies.tab[i].icol=col;
    }
    return tab_cases_bannies;
}

int Parametres(int *nlig, int *ncol, int *nban, int *niveau, int *next, int verif) /* demande et saisit les paramètres de jeu */
{
    printf("Parametres du jeu: \n");
    printf("nombre de lignes : \n");
    *nlig=Lire_Entier(VMIN, VMAX);
    if (((*nlig)<(VMIN)) || ((*nlig)>(VMAX)))
    {
        printf("nombre de lignes saisies incorrect \n");
        verif=0;
        return 0;
    }
    printf("nombre de colonnes : \n");
    *ncol=Lire_Entier(VMIN, VMAX);
    if ((*ncol<(VMIN)) || ((*ncol)>(VMAX)))
    {
        printf("nombre de colonnes saisies incorrect \n");
        verif=0;
        return 0;
    }
    verif=1;
    *nban=rand()%(Max(nlig,ncol)+1); /* génère pseudo-aléatoirement un nombre de cases bannies, compris entre 1 et Max(nlig,ncol) */
    printf("nombre de cases bannies generees : %d \n", *nban);  
    printf("niveau de 1 a 4: ");
    *niveau=Lire_Entier(1,4);
    printf("qui commence la partie? \nordinateur (1) ou le joueur (2) : ");
    *next=Lire_Entier(1,2);
    printf("\nC'est parti ! \n");
}


int Lire_Entier(int bi, int bs) // lit un entier compris entre 5 et 30 */
{
    int n;
    do
    {
        scanf("%d", &n);
    } while ((n<bi) || (n>bs));
    return n;
}

int Max(int *nlig, int *ncol) /* donne le maximum entre nlig et ncol*/
{
    if (*nlig>*ncol)
    {
    return *nlig;
    }
	else
    {
        return *ncol;
    }
}

struct T_Case Coup_Ordi_Gagnant(struct T_Case pion, int nban, struct T_Tab_Case ban, int nlig, int ncol, int nim[][VMAX])
 /* génère le coup gagnant de l'ordi */
{
    int nb_vois=0, i=0, choix;
    struct T_Tab_Case vois;
    Voisines(pion,&nb_vois,&vois,nban,ban,nlig,ncol);
    choix=rand()%nb_vois;
    for (i=0; i<nb_vois; i++)
    {
        if (nim[vois.tab[i].ilig-1][vois.tab[i].icol-1]==0)
        {
            choix =i;
            break;
        }
    }
    pion.ilig=vois.tab[choix].ilig;
    pion.icol=vois.tab[choix].icol;
    printf("L'ordinateur deplace le pion en (%d,%d) \n", vois.tab[choix].ilig, vois.tab[choix].icol);
    return pion;
}

struct T_Case Coup_Joueur(struct T_Case pion,int nban,struct T_Tab_Case ban,int nlig,int ncol) /* texte affiché à chaque tour du joueur */ 
{
    int nb_vois=0, i, choix;
    struct T_Tab_Case vois; 
    printf("\nA toi de jouer ! \n");
    Voisines(pion,&nb_vois,&vois,nban,ban,nlig,ncol);
    if (nb_vois==1)
    {
        printf("seule possibilite : (%d,%d) \n", vois.tab[0].ilig, vois.tab[0].icol);
        scanf("%d", &choix);
        pion.ilig=vois.tab[0].ilig;
		pion.icol=vois.tab[0].icol;
    }
    else
    {
        printf("choisir la destination ");
		for(i=1; i<=nb_vois; i++)
		{
			printf("%d:(%d,%d) ",i,vois.tab[i-1].ilig,vois.tab[i-1].icol);
		}
		do
		{
			printf("\n");
			while(getchar()!='\n');
			scanf("%d",&choix);
			if((choix<1) || (choix>nb_vois))
				printf("erreur !");

				
		}while((choix<1) || (choix>nb_vois));
		
		pion.ilig=vois.tab[choix-1].ilig;
		pion.icol=vois.tab[choix-1].icol;
    }
    return pion;
}

struct T_Case Coup_Ordi_Hasard(struct T_Case pion,int nban,struct T_Tab_Case ban,int nlig,int ncol) /* génère pseudo-aléatoirement le coup de l'ordi si le coup n'est pas gagnant */ 
{
    int nb_vois=0, choix, i;
    struct T_Tab_Case vois;
    Voisines(pion,&nb_vois,&vois,nban,ban,nlig,ncol);
	choix=rand()%nb_vois;
    for (i=0; i<nb_vois; i++)
    {
        if (nim[vois.tab[i].ilig-1][vois.tab[i].icol-1]==0)
        {
            choix=i;
            break;
        }
    }
}

void Calcul_Nimbers(int nim[][VMAX],int nlig,int ncol,int nban,struct T_Tab_Case ban) /* remplit la grille au début de partie par des 0 et des 1 */
{
    int i,j,k,nimber_voisine,a,b;
	int nb_vois=0;
	for(i=0; i<nlig; i++)
	{
		for(j=0; j<ncol; j++)
		{
			nim[i][j]=3;
		}
	}
	nim[nlig-1][ncol-1]=0;
	if(nban!=0)
	{
		for(i=0; i<nban; i++)
		{
			nim[ban.tab[i].ilig-1][ban.tab[i].icol-1]=5;
		}
	}
	printf("%d",nim[nlig-1][ncol-1]);
	for(i=nlig; i>=1; i=i-1)
	{
		for(j=ncol; j>=1; j=j-1)
		{
			case_.ilig=j;
			case_.ilig=i;
			if(nim[j-1][i-1]!=5)
			{
				Voisines(case_,&nb_vois,&vois,nban,ban,nlig,ncol);
				nimber_voisine=1;
				if(nb_vois!=0)
				{

					for(k=0; k<nb_vois; k++)
					{
						a=vois.tab[k].ilig;
						b=vois.tab[k].icol;
						if(nim[a-1][b-1]==0)
						{
							nimber_voisine=0;
						}
					}
					if(nimber_voisine==1)
					{
						nim[j-1][i-1]=0;
					}
						
					else 
					{
						nim[j-1][i-1]=1;
					}
				}
			}
		}
	}
}

void Voisines(struct T_Case case_,int *nb_vois, struct T_Tab_Case *vois,int nban, struct T_Tab_Case ban,int nlig,int ncol)
{
    int i, j, k;
    int case_ban=0;
	*nb_vois=0;
    for (i=(case_.ilig)+1; i<=(case_.ilig); i++)
    {
        if (nban=!0)
        {
            for (j=0; j<=nban; j++)
            {
                if ((i==ban.tab[j].ilig)&&(case_.icol==ban.tab[j].icol))
                {
                    case_ban=1;
					break;
                }
            }
        }
        if ((case_ban==0)&&(i<=nlig))
        {
            *nb_vois=(*nb_vois)+1;
			vois->tab[*nb_vois-1].ilig=i;
			vois->tab[*nb_vois-1].icol=case_.icol;
        }
    }
    case_ban=0;
    for (k=(case_.icol)+1; k<=(case_.icol)+2; k++)
    {
        if (nban=!0)
        {
            for (j=(case_.icol)+1; j<=(case_.icol)+2; j++)
            {
                if ((k==ban.tab[j].icol)&&(case_.ilig==ban.tab[j].ilig))
                {
                    case_ban=1;
					break;
                }  
            } 
        }
        if ((case_ban==0)&&(i<=ncol))
        {
            *nb_vois=(*nb_vois)+1;
			vois->tab[*nb_vois-1].icol=i;
			vois->tab[*nb_vois-1].ilig=case_.icol;
        }
    }
}