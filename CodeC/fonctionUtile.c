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

int ComparaisonData(donnees a, donnees b){
    if (a.Powerplant != b.Powerplant){
        return a.Powerplant - b.Powerplant;
    } else if (a.hv_b != b.hv_b){
        return a.hv_b - b.hv_b;
    } else if (a.hv_a != b.hv_a){
        return a.hv_a - b.hv_a;
    } else if (a.lv != b.lv){
        return a.lv - b.lv;
    } else if (a.entreprise != b.entreprise){
        return a.entreprise - b.entreprise;
    } else if (a.particuliers != b.particuliers){
        return a.particuliers - b.particuliers;
    }
    return 0;
}