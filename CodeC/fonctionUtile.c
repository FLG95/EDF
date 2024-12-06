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

int comparaisonData(donnees a, donnees b){
   if (a.hv_b != b.hv_b){
        return a.hv_b - b.hv_b;
    } else if (a.hv_a != b.hv_a){
        return a.hv_a - b.hv_a;
    } else if (a.lv != b.lv){
        return a.lv - b.lv;
    }
    return 0;
}

long long int somme(long unsigned a, long long int b){
    return a + b;
}
int estLv(donnees a){
    if (a.lv != 0 && a.consommation == 0){
        return 1;
    } else {
        return 0;
    }
    return 0;
}
int estHvb(donnees a){
    if (a.hv_b != 0 && a.hv_a == 0 && a.lv == 0 && a.production != 0){
        return 1;
    } else {
        return 0;
    }
    return 0;
}
int estHva(donnees a){
    if (a.hv_a != 0 && a.lv == 0 && a.production != 0){
        return 1;
    } else {
        return 0;
    }
    return 0;
}

void nbNoeud(int* i, arbre* tete){
    if (tete != NULL){
        *i = *i+1;
        nbNoeud(i, tete->fg);
        nbNoeud(i, tete->fd);
    }
}

donnees* init(){
    donnees* tmp = NULL;
    tmp = malloc(sizeof(donnees));
    if (tmp == NULL){
        exit(1);
    }
    tmp->lv = 0;
    tmp->hv_a = 0;
    tmp->hv_b = 0;
    tmp->consommation = 0;
    tmp->id = 1;
    tmp->particuliers = 0;
    tmp->entreprise = 0;
    tmp->Powerplant = 0;
    tmp->production = 0;
    return tmp;
}
char* addCharToChar(char* origin, char* toAdd){
    if (origin == NULL || toAdd == NULL){
        exit(1);
    }
    char* tmp = NULL;
    int newSize = strlen(origin) + strlen(toAdd) + 1;
    tmp = malloc((newSize * sizeof(char)));
    strcpy(tmp, origin);
    strcat(tmp, toAdd);
    return tmp;
}