#ifndef CREER_AVL_H
#define CREER_AVL_H
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "type_avl.h"
#include "parcours.h"





int min(int a, int b);
int max(int a, int b);
arbre* creer(donnees a);
arbre* rotationGauche(arbre* tete);
arbre* rotationDroite(arbre* tete);
arbre* doubleRotationGauche(arbre* tete);
arbre* doubleRotationDroite(arbre* tete);
arbre* equilibrage(arbre* tete);
arbre* insererStation(arbre* tete, donnees a, int* h);
arbre* insererConso(arbre* tete, donnees a, int* h);
void freeAvl(arbre* tete);
int hauteur(arbre* tete);
bool estAVL(arbre* tete);
void addTree(arbre** stationTree, arbre** consoTree, donnees b, int* hStation, int* hConso, char* station, donnees* tmp);

#endif //CREER_AVL