#include "include/creer_avl.h"
#include "include/fonction_utile.h"

//fonction pour créer un noeud dans l'arbre
arbre* creer(donnees a) {
    arbre* new = malloc(sizeof(arbre));
    if (new == NULL) {
        exit(1);
    }
    new->a = a;
    new->fd = NULL;
    new->fg = NULL;
    new->equilibre = 0;
    return new;
}

//fonction pour faire une double rotation gauche dans l'arbre
arbre* rotationGauche(arbre* tete) {
    if (tete == NULL){
        return 0;
    }
    arbre* pivot = tete->fd;
    tete->fd = pivot->fg;
    pivot->fg = tete;

    tete->equilibre = tete->equilibre - 1 - max(0, pivot->equilibre);
    pivot->equilibre = pivot->equilibre - 1 + min(0, tete->equilibre);

    return pivot;
}

//fonction pour faire une rotation droite dans l'arbre
arbre* rotationDroite(arbre* tete) {
    if (tete == NULL){
        exit(1);
    }
    arbre* pivot = tete->fg;
    tete->fg = pivot->fd;
    pivot->fd = tete;

    tete->equilibre = tete->equilibre + 1 - min(0, pivot->equilibre);
    pivot->equilibre = pivot->equilibre + 1 + max(0, tete->equilibre);

    return pivot;
}

//fonction pour faire une double rotation gauche dans l'arbre
arbre* doubleRotationGauche(arbre* tete) {
    if (tete == NULL){
        exit(1);
    }
    tete->fd = rotationDroite(tete->fd);
    return rotationGauche(tete);
}

//fonction pour faire une double rotation droite dans l'arbre
arbre* doubleRotationDroite(arbre* tete) {
    if (tete == NULL){
        exit(1);
    }
    tete->fg = rotationGauche(tete->fg);
    return rotationDroite(tete);
}

//fonction pour équilibrer l'arbre
arbre* equilibrage(arbre* tete) {
    if (tete == NULL){
        exit(1);
    }
    if (tete->equilibre >= 2) {
        if (tete->fd != NULL && tete->fd->equilibre >= 0) {
            return rotationGauche(tete);
        } else {
            return doubleRotationGauche(tete);
        }
    } else if (tete->equilibre <= -2) {
        if (tete->fg != NULL && tete->fg->equilibre <= 0) {
            return rotationDroite(tete);
        } else {
            return doubleRotationDroite(tete);
        }
    }
    return tete;
}

//fonction pour insérer un élément dans l'arbre
arbre* insererStation(arbre* tete, donnees a, int* h) {
    if (tete == NULL) {
        *h = 1;
        return creer(a);
    }
    if (a.id < tete->a.id) {
        tete->fg = insererStation(tete->fg, a, h);
        *h = -*h;
    } else if (tete->a.id < a.id) {
        tete->fd = insererStation(tete->fd, a, h);
    } else {
        *h = 0;
        return tete;
    }
    if (*h != 0) {
        tete->equilibre += *h;
        tete = equilibrage(tete);
        if (tete->equilibre == 0) {
            *h = 0;
        } else {
            *h = 1;
        }
    }
    return tete;
}
arbre* insererConso(arbre* tete, donnees a, int* h) {
    if (tete == NULL) {
        *h = 1;
        return creer(a);
    }
    if (a.consommation < tete->a.consommation) {
        tete->fg = insererConso(tete->fg, a, h);
        *h = -*h;
    } else if (tete->a.consommation < a.consommation) {
        tete->fd = insererConso(tete->fd, a, h);
    } else {
        *h = 0;
        return tete;
    }
    if (*h != 0) {
        tete->equilibre += *h;
        tete = equilibrage(tete);
        if (tete->equilibre == 0) {
            *h = 0;
        } else {
            *h = 1;
        }
    }
    return tete;
}

//fonction pour calculer la hauter de l'arbre
int hauteur(arbre* tete) {
    if (tete == NULL){
        return 0;
    }
    return 1 + max(hauteur(tete->fg), hauteur(tete->fd));
}
//fonction pour déterminer si l'arbre est bien un AVL
bool estAVL(arbre* tete) {
    if (tete == NULL){
        return true;
    }

    int hauteurG = hauteur(tete->fg);
    int hauteurD = hauteur(tete->fd);

    int facteur = hauteurG - hauteurD;
    if (facteur < -1 || facteur > 1){
        return false;
    }
    return estAVL(tete->fg) && estAVL(tete->fd);
}

void addTree(arbre** stationTree, arbre** consoTree, donnees b, int* hStation, int* hConso, char* station, donnees* tmp){
    if (station == NULL){
        exit(1);
    }
    if (strcmp(station, "lv") == 0){
        if (estLv(b)){
            b.id = b.lv;
            *tmp = b;
            *stationTree = insererStation(*stationTree, b, hStation);
        } else {
            b.id = b.lv;

            if (tmp->id == b.id){
                parcoursRefresh(stationTree, b);
            }
            *consoTree = insererConso(*consoTree, b, hConso);
        }
    }
    if (strcmp(station, "hvb") == 0){
        if (estHvb(b) == 1){
            b.id = b.hv_b;
            *tmp = b;
            *stationTree = insererStation(*stationTree, b, hStation);
        } else {
            b.id = b.hv_b;
            if (tmp->id == b.id){
                parcoursRefresh(stationTree, b);
            }
            *consoTree = insererConso(*consoTree, b, hConso);
        }
    }
    if (strcmp(station, "hva") == 0){
        if (estHva(b) == 1){
            b.id = b.hv_a;
            *tmp = b;
            *stationTree = insererStation(*stationTree, b, hStation);
        } else {
            b.id = b.hv_a;
            if (tmp->id == b.id){
                parcoursRefresh(stationTree, b);
            }
            *consoTree = insererConso(*consoTree, b, hConso);
        }
    }
}


