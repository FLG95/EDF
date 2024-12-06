#ifndef FONCTION_UTILE
#define FONCTION_UTILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "type_avl.h"

int min(int a, int b);
int max(int a, int b);
//fonction pour libérer la mémoire de l'arbre
void freeAvl(arbre* tete);
int comparaisonData(donnees a, donnees b);
long long int somme(long unsigned a, long long int b);
int estLv(donnees a);
int estHvb(donnees a);
int estHva(donnees a);
void nbNoeud(int* i, arbre* tete);
donnees* init();
char* addCharToChar(char* origin, char* toAdd);

#endif //FONCTION_UTILE

