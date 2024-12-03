#ifndef FONCTION_UTILE
#define FONCTION_UTILE

#include <stdio.h>
#include <stdlib.h>

#include "type_avl.h"

int min(int a, int b);
int max(int a, int b);
//fonction pour libérer la mémoire de l'arbre
void freeAvl(arbre* tete);
int comparaisonData(donnees a, donnees b);

#endif //FONCTION_UTILE

