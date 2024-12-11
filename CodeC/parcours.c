#include "include/parcours.h"

void parcoursRefresh(tree** head, Data a) {
    if (*head != NULL) {
        if ((*head)->a.id < a.id){
            parcoursRefresh(&((*head)->fd), a);
        } else if ((*head)->a.id > a.id){
            parcoursRefresh(&((*head)->fg), a);
        } else {
            (*head)->a.consommation += a.consommation;  // Mise à jour de la consommation
        }
    }
}
tree* parcoursSortProduction(tree* head, tree* tmp, int* h){
    if (tmp != NULL){
        head = parcoursSortProduction(head, tmp->fg, h);
        head = sortByProduction(head, tmp->a, h);
        head = parcoursSortProduction(head, tmp->fd, h);
    }
    return head;
}
tree* parcoursSortAbs(tree* head, tree* tmp, int* h){
    if (tmp != NULL){
        head = parcoursSortAbs(head, tmp->fg, h);
        head = sortByAbs(head, tmp->a, h);
        head = parcoursSortAbs(head, tmp->fd, h);
    }
    return head;
}
