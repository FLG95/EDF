#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

#include "include/creer_avl.h"



// Fonctions utilitaires
int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

arbre* creer(int a) {
    arbre* new = malloc(sizeof(arbre));
    if (new == NULL) {
        fprintf(stderr, "Erreur: allocation mémoire échouée.\n");
        exit(EXIT_FAILURE);
    }
    new->nb = a;
    new->fd = NULL;
    new->fg = NULL;
    new->equilibre = 0;
    return new;
}

// Rotations
arbre* rotationGauche(arbre* tete) {
    arbre* pivot = tete->fd;
    tete->fd = pivot->fg;
    pivot->fg = tete;

    int eq_a = tete->equilibre;
    int eq_p = pivot->equilibre;

    tete->equilibre = eq_a - max(eq_p, 0) - 1;
    pivot->equilibre = min(min(eq_a - 2, eq_a + eq_p - 2), eq_p - 1);

    return pivot;
}

arbre* rotationDroite(arbre* tete) {
    arbre* pivot = tete->fg;
    tete->fg = pivot->fd;
    pivot->fd = tete;

    int eq_a = tete->equilibre;
    int eq_p = pivot->equilibre;

    tete->equilibre = eq_a - max(eq_p, 0) + 1;
    pivot->equilibre = min(min(eq_a + 2, eq_a + eq_p + 2), eq_p + 1);

    return pivot;
}

arbre* doubleRotationGauche(arbre* tete) {
    tete->fd = rotationDroite(tete->fd);
    return rotationGauche(tete);
}

arbre* doubleRotationDroite(arbre* tete) {
    tete->fg = rotationGauche(tete->fg);
    return rotationDroite(tete);
}

arbre* equilibrage(arbre* tete) {
    if (tete->equilibre >= 2) {
        if (tete->fd != NULL && tete->fd->equilibre >= 0) {
            return rotationGauche(tete);
        } else {
            return doubleRotationGauche(tete);
        }
    } else if (tete->equilibre < -2) {
        if (tete->fg != NULL && tete->fg->equilibre <= 0) {
            return rotationDroite(tete);
        } else {
            return doubleRotationDroite(tete);
        }
    }
    return tete;
}

// Insertion dans l'arbre AVL
arbre* inserer(arbre* tete, int a, int* h) {
    if (tete == NULL) {
        *h = 1;
        return creer(a);
    } else if (a > tete->nb) {
        tete->fd = inserer(tete->fd, a, h);
    } else if (a < tete->nb) {
        tete->fg = inserer(tete->fg, a, h);
        *h = -*h;
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

// Parcours en largeur


int hauteur(arbre* tete) {
    if (tete == NULL) return 0;
    return 1 + max(hauteur(tete->fg), hauteur(tete->fd));
}
bool estAVL(arbre* tete) {
    if (tete == NULL) return true;

    int hauteurG = hauteur(tete->fg);
    int hauteurD = hauteur(tete->fd);

    int facteur = hauteurG - hauteurD;
    if (facteur < -1 || facteur > 1) return false;

    return estAVL(tete->fg) && estAVL(tete->fd);
}

void freeAvl(arbre* tete){
    if (tete == NULL){
        return;
    }
    freeAvl(tete->fg);
    freeAvl(tete->fd);

    free(tete);
}