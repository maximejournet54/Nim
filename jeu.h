#ifndef JEU
#define JEU
#define VMIN 5
#define VMAX 30



struct T_case
{
    int i, j;
};

typedef struct T_case T_Case;

/* prototype des différentes fonctions*/
void max(int nlig, int ncol);
int Parametres(int nlig, int ncol);
int T_Tab_Case[]; /* taille du tableau a verifier*/
int pion(T_Case);
int Saisir_Entier(int, int); /* erreur compilation */
void Lire_Entier(int, int, int*);
int Affiche_Grille(); /* à completer*/

#endif