#ifndef PARCOURS_H
#define PARCOURS_H
#include <stdio.h>

#include "type_avl.h"
#include "affichage.h"
#include "fonction_utile.h"



file* creerFile(arbre* a);
file* enfiler(file* f, arbre* tete);
arbre* defiler(file** f);

void parcoursLargeur(arbre* tete);
void parcoursInfixe(arbre* tete, long long int* b);
void recuperer10inf(int* compteur, arbre** tab, arbre* tete);
void recuperer10sup(int* compteur, arbre** tab, arbre* tete);
#endif //PARCOURS_H