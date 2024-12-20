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
 * This function create a node for a tree
 */
tree* create(Data a);

/**
 * @param head
 * This function make a simple left rotation for the stability of the tree
 */
tree* leftRotation(tree* head);

/**
 * @param head
 * This function make a simple right rotation for the stability of the tree
 */
tree* RightRotation(tree* head);

/**
 * @param head
 * This function make a double left rotation for the stability of the tree
 */
tree* doubleLeftRotation(tree* head);

/**
 * @param head
 * This function make a double right rotation for the stability of the tree
 */
tree* doubleRightRotation(tree* head);

/**
 * @param head
 * This function balance the tree for the stability of the avl
 */
tree* balancing(tree* head);

/**
 * @param head
 * @param a
 * @param h
 * This function insert station in the stationTree (AVL)
 */
tree* insertStation(tree* head, Data a, int* h);

/**
 * @param head
 * @param a
 * @param h
 * This function insert consumers in the consoTree (AVL)
 */
tree* insertConso(tree* head, Data a, int* h);

/**
 * @param stationTree
 * @param b
 * @param hStation
 * @param station
 * @param i
 * This function insert consumers and station in their tree
 */
void addTree(tree** stationTree, tree** consoTree, Data b, int* hStation, int* hConso, char* stationType, int* i);

/**
 * @param head
 * @param tmp
 * @param h
 * This function sort the data by consumption in an AVL
 */
tree* sortByConsumption(tree* head, Data tmp, int* h);

/**
 * @param head
 * @param tmp
 * @param h
 * This function sort the data by production in an AVL
 */
tree* sortByProduction(tree* head, Data tmp, int* h);

#endif //create_AVL_H