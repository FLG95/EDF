#ifndef PARCOURS_H
#define PARCOURS_H
#include <stdio.h>

#include "type_avl.h"
#include "fonction_utile.h"

/**
 * @param head
 * @param tmp
 * @param h
 * This function create an Avl which sort the Node by production
 */
tree* parcoursSortProduction(tree* head, tree* tmp, int* h);

/**
 * @param head
 * @param tmp
 * @param h
 * This function create an Avl which sort the Node by Consumption
 */
tree* parcoursSortConsumption(tree* head, tree* tmp, int* h);

/**
 * @param a
 * @param stationTree
 * This function make the sum of the consumption of the consumers an add it to the respective station
 */
void addConsumptionToStation(Data a, tree** stationTree);

/**
 * @param consoTree
 * @param stationTree
 * This function make an in-order traversal to call the function which make the sum of the consumption and add it to the station
 */
void parcoursInfixeSum(tree* consoTree, tree** stationTree);
#endif //PARCOURS_H