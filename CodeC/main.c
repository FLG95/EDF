#include <stdio.h>
#include <stdlib.h>

#include "include/creer_avl.h"
#include "include/parcours.h"
#include "include/type_avl.h"
#include "include/affichage.h"



int main(int argc, char* argv[]){

    int a = 0;

    arbre* tete = NULL;
    int ph;
    int* h = &ph;

    for (int i = 1; i < 10; i++){
        tete = inserer(tete, i, h);
        printf("%11d\n", i);
    }

    parcoursInfixe(tete);
    if (estAVL(tete)) {
        printf("\nL'arbre est un AVL.\n");
    } else {
        printf("\nL'arbre n'est PAS un AVL.\n");
    }
    freeAvl(tete);
    return 0;
}