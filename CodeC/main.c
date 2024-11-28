#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/creer_avl.h"
#include "include/parcours.h"
#include "include/type_avl.h"
#include "include/affichage.h"
#include "include/creerDonnees.h"



int main(int argc, char* argv[]){


    if (argc != 2){
        exit(1);
    }
    FILE* fichier = fopen(argv[1], "r");
    if (fichier == NULL){
        exit(1);
    }
    int a = 0;

    arbre* tete = NULL;
    int ph = 0;
    int* h = &ph;

    for (int i = 1; i < 10; i++){
        tete = inserer(tete, i, h);
        //printf("%11d\n", i);
    }

    parcoursInfixe(tete);
    if (estAVL(tete)) {
        printf("\nL'arbre est un AVL.\n");
    } else {
        printf("\nL'arbre n'est PAS un AVL.\n");
    }
    freeAvl(tete);

    FILE* out = fopen("../tmp/out.txt", "w");
    if (out == NULL){
        exit(1);
    }


    printf("\n1\n");

    ensembleDonne(fichier);


    return 0;
}