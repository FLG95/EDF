#ifndef create_AVL_H
#define create_AVL_H
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "type_avl.h"
#include "parcours.h"
#include "fonction_utile.h"

/**
 * @param a
 * Create node for a tree
 */
tree* create(Data a);

/**
 * @param head
 * Make a simple left rotation for the stability of the tree
 */
tree* leftRotation(tree* head);

/**
 * @param head
 * Make a simple right rotation for the stability of the tree
 */
tree* RightRotation(tree* head);

/**
 * @param head
 * Make a double left rotation for the stability of the tree
 */
tree* doubleLeftRotation(tree* head);

/**
 * @param head
 * Make a double right rotation for the stability of the tree
 */
tree* doubleRightRotation(tree* head);

/**
 * @param head
 * Balance the tree for the stability of the avl
 */
tree* balancing(tree* head);

/**
 * @param head
 * @param a
 * @param h
 * Insert Data in a tree
 */
tree* insertStation(tree* head, Data a, int* h);

/**
 * @param stationTree
 * @param b
 * @param hStation
 * @param station
 * @param tmp
 * @param i
 * Add data to a tree
 */
void addTree(tree** stationTree, Data b, int* hStation, char* station, Data* tmp, int* i);

/**
 * @param head
 * @param tmp
 * @param h
 * Sort a tree by absolute value between production and consumption
 */
tree* sortByAbs(tree* out, Data tmp, int* h);

/**
 * @param head
 * @param tmp
 * @param h
 * Sort a tree by production
 */
tree* sortByProduction(tree* out, Data tmp, int* h);


#endif //create_AVL