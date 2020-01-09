#ifndef JEU
#define JEU
#define VMIN 5
#define VMAX 30


typedef struct T_Case T_Case;
struct T_Case
{
    int i, j;
};

/* prototype des différentes fonctions*/
int T_Tab_Case[900]; /* taille= 30*30, contiendra toutes les cases voisines*/
int pion(T_Case);
int ban[900];  /* taille= max nban , contient toutes les cases bannies*/
int nim[VMAX][VMAX]; /* table contenant les coordonnées des nimbers*/
int vois[900]; /* table qui stocke les coordonnées des cases voisines */
int Parametres(int, int, int);
int Saisir_Entier(); 
void Lire_Entier(int*);
int Affiche_Grille(int, int); /* affiche la grille de jeu à chaque tour*/
int Coup_Ordi_Hasard(); /* génère pseudo-aléatoirement le coup de l'ordi si le coup n'est pas gagnant */ 
int Coup_Ordi_Gagnant(int, int, int); /* génère le coup gagnant de l'ordi */
int Coup_Ordi();    /* texte affiché à chaque tour de l'ordi */ 
int Coup_Joueur(); /* texte affiché à chaque tour du joueur */ 
int Calcul_Nimbers(int, int, int);   /* remplit la grille au début de partie par des 0 et des 1 */
int Hasard_Ban(int [], int); /* génère pseudo-aléatoirement les cases bannies, compris entre 1 et nban*/
int Hasard(); /* génère un nombre pseudo-aléatoire  pour la fonction Coup_Ordi_Hasard*/ 

#endif