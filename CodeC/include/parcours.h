#ifndef PARCOURS_H
#define PARCOURS_H
#include <stdio.h>

#include "type_avl.h"
#include "fonction_utile.h"

/**
 * @param head
 * @param a
 * Sum the consumption of the data to the station which has the same id
 */
void parcoursRefresh(tree** head, Data a);

/**
 * @param head
 * @param tmp
 * @param h
 * Create an Avl which sort the Node by production
 */
tree* parcoursSortProduction(tree* head, tree* tmp, int* h);

/**
 * @param head
 * @param tmp
 * @param h
 * Create an Avl which sort the Node by absolute value (production - consumption)
 */
tree* parcoursSortAbs(tree* head, tree* tmp, int* h);

#endif //PARCOURS_H