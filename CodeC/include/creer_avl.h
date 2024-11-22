
#ifndef CREER_AVL_H
#define CREER_AVL_H
#include <stdbool.h>

#include "type_avl.h"





int min(int a, int b);
int max(int a, int b);
arbre* creer(int a);
arbre* rotationGauche(arbre* tete);
arbre* rotationDroite(arbre* tete);
arbre* doubleRotationGauche(arbre* tete);
arbre* doubleRotationDroite(arbre* tete);
arbre* equilibrage(arbre* tete);
arbre* inserer(arbre* tete, int a, int* h);

int hauteur(arbre* tete);
bool estAVL(arbre* tete);

#endif //CREER_AVL