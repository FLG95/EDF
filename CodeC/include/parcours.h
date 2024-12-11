#ifndef PARCOURS_H
#define PARCOURS_H
#include <stdio.h>

#include "type_avl.h"
#include "fonction_utile.h"

void parcoursRefresh(tree** head, Data a);
tree* parcoursSortProduction(tree* head, tree* tmp, int* h);
tree* parcoursSortAbs(tree* head, tree* tmp, int* h);

#endif //PARCOURS_H