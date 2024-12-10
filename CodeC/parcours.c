

#include "include/parcours.h"

file* createFile(tree* a) {
    file* new = malloc(sizeof(file));
    if (new == NULL) {
        fprintf(stderr, "Erreur: allocation mémoire échouée pour la file.\n");
        exit(EXIT_FAILURE);
    }
    new->actuel = a;
    new->suivant = NULL;
    return new;
}

file* enfiler(file* f, tree* head) {
    file* new = createFile(head);
    if (f == NULL) {
        return new;
    }
    file* tmp = f;
    while (tmp->suivant != NULL) {
        tmp = tmp->suivant;
    }
    tmp->suivant = new;
    return f;
}

tree* defiler(file** f) {
    if (*f == NULL) return NULL;

    file* tmp = *f;
    tree* actual = tmp->actuel;
    *f = tmp->suivant;
    free(tmp);
    return actual;
}

void parcoursLargeur(tree* head) {
    if (head == NULL) return;

    file* f = enfiler(NULL, head);
    while (f != NULL) {
        tree* actual = defiler(&f);
        if (actual != NULL) {
            traiter(head);
            if (actual->fg != NULL) f = enfiler(f, actual->fg);
            if (actual->fd != NULL) f = enfiler(f, actual->fd);
        }
    }
    printf("\n");
}

// Affichage en profondeur
void parcoursInfixe(tree* head) {
    if (head != NULL) {
        traiter(head);
        parcoursInfixe(head->fg);
        parcoursInfixe(head->fd);
    }
}

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
