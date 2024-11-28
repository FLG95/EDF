#include <stdio.h>
#include <stdlib.h>

#include "include/creer_avl.h"
#include "include/parcours.h"
#include "include/type_avl.h"
#include "include/affichage.h"



int main(int argc, char* argv[]){


    if (argc != 2){
        exit(1);
    }
    FILE* fichier = fopen(argv[1], "r");

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

    //printf("%s", argv[0]);
    char buffer[1024]; // Tampon pour stocker chaque ligne
    while (fgets(buffer, sizeof(buffer), fichier)) {
        printf("%s", buffer);
    }
    printf("\n1\n");
    fclose(fichier);
    return 0;
}