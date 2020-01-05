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
int Parametres(int , int);
int T_Tab_Case[]; /* taille du tableau a verifier*/
int pion(T_Case);
int Saisir_Entier(int, int); /* erreur compilation */
void Lire_Entier(int, int, int*);
int Affiche_Grille(); /* à completer*/
int ban[];  /* taille du tableau a verifier*/

#endif