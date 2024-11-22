#include "stdio.h"
#include "creer_avl.h"



int main(int argc, char* argv[]){

    int a = 0;

    arbre* tete = NULL;
    int ph;
    int* h = &ph;

    for (int i = 1; i < 150000000; i++){
        tete = inserer(tete, i, h);
        printf("%11d\n", i);
    }

    afficher(tete);
    if (estAVL(tete)) {
        printf("\nL'arbre est un AVL.\n");
    } else {
        printf("\nL'arbre n'est PAS un AVL.\n");
    }
    return 0;

}