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
void parcoursInfixe(arbre* tete);
void parcoursRefresh(arbre** tete, donnees a);
void parcoursSort(arbre** tete, arbre* tmp);
#endif //PARCOURS_H