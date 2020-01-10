#ifndef JEU
#define JEU
#define VMIN 5
#define VMAX 30

struct T_Case
{
    int ilig, icol,pion;
};

struct T_Tab_Case
{
    struct T_Case tab[50];
};

/* prototype des différentes fonctions*/
struct T_Tab_Case ban, vois;
struct T_Case pion;
struct T_Case case_;
int nim[VMAX][VMAX]; /* table contenant les coordonnées des nimbers*/
void Voisines(struct T_Case, int*, struct T_Tab_Case *, int, struct T_Tab_Case, int, int);
int Parametres(int*, int*, int*, int*, int*, int); 
int Lire_Entier(int, int);
int Max(int*, int*);
int Affiche_Grille(struct T_Case, struct T_Tab_Case, int, int, int); /* affiche la grille de jeu à chaque tour*/
struct T_Case Coup_Ordi_Hasard(struct T_Case,int,struct T_Tab_Case,int,int); /* génère pseudo-aléatoirement le coup de l'ordi si le coup n'est pas gagnant */ 
struct T_Case Coup_Ordi_Gagnant(struct T_Case,int,struct T_Tab_Case,int,int,int nim[][VMAX]); /* génère le coup gagnant de l'ordi */
struct T_Case  Coup_Joueur(struct T_Case, int, struct T_Tab_Case, int, int); /* texte affiché à chaque tour du joueur */ 
void Calcul_Nimbers(int nim[][VMAX], int, int, int, struct T_Tab_Case);   /* remplit la grille au début de partie par des 0 et des 1 */
struct T_Tab_Case Hasard_Ban(int, int *, int *); /* génère pseudo-aléatoirement les cases bannies, compris entre 1 et nban*/ 

#endif