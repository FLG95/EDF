#include <stdbool.h>

typedef struct arbre {
    int nb;
    struct arbre* fd;
    struct arbre* fg;
    int equilibre;
} arbre;

typedef struct file {
    arbre* actuel;
    struct file* suivant;
} file;

int min(int a, int b);
int max(int a, int b);
arbre* creer(int a);
arbre* rotationGauche(arbre* tete);
arbre* rotationDroite(arbre* tete);
arbre* doubleRotationGauche(arbre* tete);
arbre* doubleRotationDroite(arbre* tete);
arbre* equilibrage(arbre* tete);
arbre* inserer(arbre* tete, int a, int* h);
file* creerFile(arbre* a);
file* enfiler(file* f, arbre* tete);
arbre* defiler(file** f);
void parcoursLargeur(arbre* tete);
void afficher(arbre* tete);
int hauteur(arbre* tete);
bool estAVL(arbre* tete);