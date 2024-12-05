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

    int ph = 0;
    int* h = &ph;
    arbre* tete = NULL;


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

    tete = ensembleDonne(fichier, h);
    long long  int somme_tot = 0;
    parcoursInfixe(tete, &somme_tot);

    if (estAVL(tete)) {
        printf("\nL'arbre est un AVL.\n");
    } else {
        printf("\nL'arbre n'est PAS un AVL.\n");
    }
printf("%lld\n", somme_tot);

    freeAvl(tete);

    return 0;
}