#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/creerDonnees.h"



#include "../CodeC/include/creer_avl.h"
#include "../CodeC/include/parcours.h"
#include "../CodeC/include/type_avl.h"
#include "../CodeC/include/affichage.h"
#include "../CodeC/include/creerDonnees.h"
#include "../CodeC/include/fonction_utile.h"



int main(int argc, char* argv[]){
    int hStation = 0;
    int hConso = 0;
    arbre* stationTree = NULL;
    arbre* consoTree = NULL;
    char* type = "hvb";


    if (argc != 2){
        printf("ERROR : not enough argument");
        exit(1);
    }

    FILE* fichier = fopen(argv[1], "r");
    if (fichier == NULL){
        printf("ERROR : argument 1 file is empty");
        exit(1);
    }



/*
    FILE* out = fopen("../tmp/out.txt", "w");
    if (out == NULL){
        printf("ERROR : can't open file");
        exit(1);
    }

*/

    ensembleDonne(fichier, &hStation, &hConso, &stationTree, &consoTree, type);
    parcoursInfixe(stationTree);
    //parcoursLargeur(tete);

    if (estAVL(stationTree)) {
        printf("\nL'arbre est un AVL.\n");
    } else {
        printf("\nL'arbre n'est PAS un AVL.\n");
    }
   /* parcoursInfixe(consoTree);
    //parcoursLargeur(tete);

    if (estAVL(consoTree)) {
        printf("\nL'arbre est un AVL.\n");
    } else {
        printf("\nL'arbre n'est PAS un AVL.\n");
    }*/
    int i = 0;
    nbNoeud(&i, stationTree);

    printf("%d\n\n", i);

    freeAvl(consoTree);
    freeAvl(stationTree);

    return 0;
}