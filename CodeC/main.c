#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/creerDonnees.h"



#include "include/creer_avl.h"
#include "include/parcours.h"
#include "include/type_avl.h"
#include "include/affichage.h"
#include "include/creerDonnees.h"
#include "include/fonction_utile.h"
#include "include/outFile.h"



int main(int argc, char* argv[]){
    int hStation = 0;
    int hConso = 0;
    arbre* stationTree = NULL;
    arbre* consoTree = NULL;
    if (strcmp(argv[2], "hva") != 0 && strcmp(argv[2], "hvb") && strcmp(argv[2], "lv")){
        exit(1);
    }
    char* type = argv[2];


    if (argc != 4){
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
    //parcoursInfixe(stationTree);

    if (estAVL(stationTree)) {
        printf("\nL'arbre est un AVL.\n");
    } else {
        printf("\nL'arbre n'est PAS un AVL.\n");
    }
    //parcoursInfixe(consoTree);
    //parcoursLargeur(tete);


    long long unsigned  i = 0;
    nbNoeud(&i, stationTree);
    printf("%llu\n\n", i);
    long long unsigned j = 0;
    nbNoeud(&i, consoTree);
    printf("%llu\n\n", i);

    //parcoursInfixe(consoTree);
    arbre* stationTreeSortProduction = NULL;
    arbre* stationTreeSortAbs = NULL;
    int h_abs = 0;
    int h_Prod = 0;
    stationTreeSortAbs = parcoursSortAbs(stationTreeSortAbs, stationTree, &h_abs);

    stationTreeSortProduction = parcoursSortProduction(stationTreeSortProduction, stationTree, &h_Prod);
    printf("HELLO\n");


    if (estAVL(stationTreeSortProduction)) {
        printf("\nL'arbre est un AVL.\n");
    } else {
        printf("\nL'arbre n'est PAS un AVL.\n");
    }
    i = 0;
    nbNoeud(&i, stationTreeSortProduction);
    printf("%llu\n\n", i);
    if (estAVL(stationTreeSortAbs)) {
        printf("\nL'arbre est un AVL.\n");
    } else {
        printf("\nL'arbre n'est PAS un AVL.\n");
    }



    i = 0;
    nbNoeud(&i, stationTreeSortAbs);
    printf("%llu\n\n", i);

    if (stationTreeSortProduction == NULL || stationTreeSortAbs == NULL){
        exit(1);
    }


    centerWrite(stationTreeSortProduction, argv[2], argv[3]);
    if (strcmp(argv[2], "lv") == 0 && strcmp(argv[3], "all") == 0){
        centerWrite10(stationTreeSortAbs, argv[2], argv[3]);
    }

    freeAvl(consoTree);
    freeAvl(stationTree);
    return 0;
}