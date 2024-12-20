#include "include/parcours.h"

/**
 * @param head
 * @param tmp
 * @param h
 * This function create an Avl which sort the Node by production
 */
tree* parcoursSortProduction(tree* head, tree* tmp, int* h){
    if (tmp != NULL && h != NULL){
        head = parcoursSortProduction(head, tmp->fg, h);
        head = sortByProduction(head, tmp->a, h);
        head = parcoursSortProduction(head, tmp->fd, h);
    }
    return head;
}

/**
 * @param head
 * @param tmp
 * @param h
 * This function create an Avl which sort the Node by Consumption
 */
tree* parcoursSortConsumption(tree* head, tree* tmp, int* h){
    if (tmp != NULL && h != NULL){
        head = parcoursSortConsumption(head, tmp->fg, h);
        head = sortByConsumption(head, tmp->a, h);
        head = parcoursSortConsumption(head, tmp->fd, h);
    }
    return head;
}

/**
 * @param a
 * @param stationTree
 * This function make the sum of the consumption of the consumers an add it to the respective station
 */
void addConsumptionToStation(Data a, tree** stationTree){
    if (*stationTree != NULL){
        if (a.id == (*stationTree)->a.id) {
            (*stationTree)->a.consumption += a.consumption;
        } else {
            if (a.id < (*stationTree)->a.id){
                addConsumptionToStation(a, &(*stationTree)->fg);
            } else {
                addConsumptionToStation(a, &(*stationTree)->fd);
            }
        }
    }
}

/**
 * @param consoTree
 * @param stationTree
 * This function make an in-order traversal to call the function which make the sum of the consumption and add it to the station
 */
void parcoursInfixeSum(tree* consoTree, tree** stationTree){
    if (consoTree != NULL && stationTree != NULL){
        addConsumptionToStation(consoTree->a, stationTree);
        parcoursInfixeSum(consoTree->fg, stationTree);
        parcoursInfixeSum(consoTree->fd, stationTree);
    }
}