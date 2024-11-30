#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
#include "include/creer_avl.h"
#include "include/parcours.h"
#include "include/type_avl.h"
#include "include/affichage.h"
#include "include/creerDonnees.h"
#include "include/fonction_utile.h"
*/


int main(int argc, char* argv[]){

    int ph = 0;
    int* h = &ph;

    if (argc != 2){
        printf("not enough argument");
        exit(1);
    }


    FILE* fichier = fopen(argv[1], "r");
    if (fichier == NULL){
        printf("argument 1 file is empty");
        exit(1);
    }
    //arbre* tete = NULL;


    FILE* out = fopen("../tmp/out.txt", "w");
    if (out == NULL){
        printf("can't open file");
        exit(1);
    }

/*
    tete = ensembleDonne(fichier, h);

    parcoursInfixe(tete);

    if (estAVL(tete)) {
        printf("\nL'arbre est un AVL.\n");
    } else {
        printf("\nL'arbre n'est PAS un AVL.\n");
    }*/


    int a = 0;
    while ( a != 1){
        scanf("%d", &a);
    }

    //freeAvl(tete);

    return 0;
}