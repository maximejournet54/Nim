#ifndef JEU
#define JEU

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
int Saisir_Entier(int bi);
void Lire_Entier(int bi, int *n);
int Affiche_Grille(); /* a faire et completer*/


#endif