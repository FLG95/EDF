

#include "include/parcours.h"

file* creerFile(arbre* a) {
    file* new = malloc(sizeof(file));
    if (new == NULL) {
        fprintf(stderr, "Erreur: allocation mémoire échouée pour la file.\n");
        exit(EXIT_FAILURE);
    }
    new->actuel = a;
    new->suivant = NULL;
    return new;
}

file* enfiler(file* f, arbre* tete) {
    file* new = creerFile(tete);
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

arbre* defiler(file** f) {
    if (*f == NULL) return NULL;

    file* tmp = *f;
    arbre* courant = tmp->actuel;
    *f = tmp->suivant;
    free(tmp);
    return courant;
}

void parcoursLargeur(arbre* tete) {
    if (tete == NULL) return;

    file* f = enfiler(NULL, tete);
    while (f != NULL) {
        arbre* courant = defiler(&f);
        if (courant != NULL) {
            traiter(tete);
            if (courant->fg != NULL) f = enfiler(f, courant->fg);
            if (courant->fd != NULL) f = enfiler(f, courant->fd);
        }
    }
    printf("\n");
}

// Affichage en profondeur
void parcoursInfixe(arbre* tete) {
    if (tete != NULL) {
        traiter(tete);
        parcoursInfixe(tete->fg);
        /*if (tete->a.consommation != 0){
            *somme_conso += somme(tete->a.consommation, *somme_conso);
        }*/

        parcoursInfixe(tete->fd);
    }
}

void parcoursRefresh(arbre** tete, donnees a){
    if (*tete != NULL){
        if ((*tete)->a.id < a.id){
            parcoursRefresh(&((*tete)->fd), a);
        } else if ((*tete)->a.id > a.id) {
            parcoursRefresh(&((*tete)->fg), a);
        } else {
            (*tete)->a.consommation += a.consommation;
        }
    }
}
