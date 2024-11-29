#include "include/fonction_utile.h"
#include "include/type_avl.h"


//fonction pour déterminer le minimum
int min(int a, int b) {
    return (a < b) ? a : b;
}

//fonction pour déterminer le maximun
int max(int a, int b) {
    return (a > b) ? a : b;
}
//fonction pour libérer la mémoire de l'arbre
void freeAvl(arbre* tete) {
    if (tete == NULL) {
        return;
    }
    freeAvl(tete->fg);
    freeAvl(tete->fd);
    free(tete);
}