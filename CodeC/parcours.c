#include "include/parcours.h"

//Sum the consumption of the data to the station which has the same id
void parcoursRefresh(tree** head, Data a) {
    if (*head != NULL) {
        if ((*head)->a.id < a.id){
            parcoursRefresh(&((*head)->fd), a);
        } else if ((*head)->a.id > a.id){
            parcoursRefresh(&((*head)->fg), a);
        } else {
            (*head)->a.consumption += a.consumption;
        }
    }
} 

//Create an Avl which sort the Node by production
tree* parcoursSortProduction(tree* head, tree* tmp, int* h){
    if (tmp != NULL && h != NULL){
        head = parcoursSortProduction(head, tmp->fg, h);
        head = sortByProduction(head, tmp->a, h);
        head = parcoursSortProduction(head, tmp->fd, h);
    }
    return head;
}

//Create an Avl which sort the Node by absolute value (production - consumption)
tree* parcoursSortAbs(tree* head, tree* tmp, int* h){
    if (tmp != NULL && h != NULL){
        head = parcoursSortAbs(head, tmp->fg, h);
        head = sortByAbs(head, tmp->a, h);
        head = parcoursSortAbs(head, tmp->fd, h);
    }
    return head;
}
