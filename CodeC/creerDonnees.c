#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/type_avl.h"

FILE* transformerFichier(FILE* fichier){
    if (fichier == NULL){
        exit(1);
    }
    FILE* out = fopen("../tmp/out.txt", "w");
    if (out == NULL){
        exit(1);
    }
    char ligne[256];
    while (fgets(ligne, sizeof(ligne), fichier)) {
        // Remplacer chaque '-' par '0'.
        for (int i = 0; i < strlen(ligne); i++) {
            if (ligne[i] == '-') {
                ligne[i] = '0';
            }
        }

        // Écrire la ligne modifiée dans le fichier de sortie.
        fputs(ligne, out);
    }
    fclose (fichier);
    fclose (out);
    out = fopen("../tmp/out.txt", "r");
    if (out == NULL){
        exit(1);
    }
    return out;
}
file2* creerChainon(donnees b){
    file2* tete = NULL;
    tete = malloc(sizeof(file2));
    if (tete == NULL){
        exit(1);
    }
    tete->actuel = tete;
    tete->suivant = NULL;
    tete->a = b;
    return tete;
}
file2* creation(file2* tete, donnees b){
    if (tete == NULL){
        return creerChainon(b);
    } else {
        file2* tmp2 = tete;
        while (tmp2->suivant != NULL){
            tmp2 = tmp2->suivant;
        }
        tmp2->suivant = creerChainon(b);
    }
    return tete;
}
void afficher(file2* tete){
    while (tete != NULL){
        printf("%d %d %d %d %d %d %d %d\n",
               tete->a.Powerplant, tete->a.hv_b, tete->a.hv_a, tete->a.lv, tete->a.entreprise, tete->a.particuliers, tete->a.production, tete->a.consommation);
        tete = tete->suivant;
    }
}
void ensembleDonne(FILE* fichier){
    if (fichier == NULL){
        exit(1);
    }
    FILE* out = transformerFichier(fichier);
    /*if (out == NULL){
        exit(1);
    }*/
    char ligne2[256];
    donnees b;
    file2* tete = NULL;
    int i = 0;
    while (fgets(ligne2, sizeof(ligne2), out) != NULL) {
        sscanf(ligne2,"%d;%d;%d;%d;%d;%d;%d;%d;" ,
               &b.Powerplant, &b.hv_b, &b.hv_a, &b.lv, &b.entreprise, &b.particuliers, &b.production, &b.consommation);
        tete = creation(tete, b);
        i++;
        printf("%d\n", i);
    }
    afficher(tete);

    printf("\n\n\n%d\n", i);
    fclose (out);
}