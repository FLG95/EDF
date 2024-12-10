#ifndef PARCOURS_H
#define PARCOURS_H
#include <stdio.h>

#include "type_avl.h"
#include "affichage.h"
#include "fonction_utile.h"



file* createFile(tree* a);
file* enfiler(file* f, tree* head);
tree* defiler(file** f);

void parcoursLargeur(tree* head);
void parcoursInfixe(tree* head);
void parcoursRefresh(tree** head, Data a);
tree* parcoursSortProduction(tree* head, tree* tmp, int* h);
tree* parcoursSortAbs(tree* head, tree* tmp, int* h);

#endif //PARCOURS_H