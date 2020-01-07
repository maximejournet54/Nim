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
int Parametres(int, int);
int T_Tab_Case[900]; /* taille= 30*30, contiendra toutes les cases voisines*/
int pion(T_Case);
int Saisir_Entier(int, int); /* erreur compilation */
void Lire_Entier(int, int, int*);
int Affiche_Grille(int, int); 
int ban[30];  /* taille= max nban , contient toutes les cases bannies*/
int Coup_Ordi_Hasard();
int Coup_Ordi_Gagnant(int, int);
int Hasard_Ban(int, int, int);
int Hasard(int);

#endif