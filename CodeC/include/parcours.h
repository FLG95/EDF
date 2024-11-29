#ifndef PARCOURS_H
#define PARCOURS_H
#include <stdio.h>

#include "type_avl.h"
#include "affichage.h"



file* creerFile(arbre* a);
file* enfiler(file* f, arbre* tete);
arbre* defiler(file** f);

void parcoursLargeur(arbre* tete);
void parcoursInfixe(arbre* tete);

#endif //PARCOURS_H