#include "include/type_avl.h"
#include "include/creer_avl.h"
#include "include/fonction_utile.h"

FILE* transformerFichier(FILE* fichier){
    if (fichier == NULL){
        exit(1);
    }
    FILE* out = fopen("../tmp/tmp.txt", "w");
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
    out = fopen("../tmp/tmp.txt", "r");
    if (out == NULL){
        exit(1);
    }
    return out;
}

void ensembleDonne(FILE* fichier, int* hStation, int* hConso, arbre** stationTree, arbre** consoTree, char* type) {
    if (fichier == NULL) {
        exit(1);
    }
    FILE *out = transformerFichier(fichier);
    char ligne2[256];
    donnees* tmp = NULL;
    tmp = init();if (tmp == NULL){
        exit(1);
    }
    sscanf(ligne2, "%lu;%lu;%lu;%lu;%lu;%lu;%lu;%lu;",
           &tmp->Powerplant, &tmp->hv_b, &tmp->hv_a, &tmp->lv, &tmp->entreprise, &tmp->particuliers, &tmp->production, &tmp->consommation);
    addTree(stationTree, consoTree, *tmp, hStation, hConso, type, tmp);
    donnees b;
    arbre *tete = NULL;
    fgets(ligne2, sizeof(ligne2), out);
    while (fgets(ligne2, sizeof(ligne2), out) != NULL) {
        sscanf(ligne2, "%lu;%lu;%lu;%lu;%lu;%lu;%lu;%lu;",
               &b.Powerplant, &b.hv_b, &b.hv_a, &b.lv, &b.entreprise, &b.particuliers, &b.production, &b.consommation);
        addTree(stationTree, consoTree, b, hStation, hConso, type, tmp);
    }
    printf("\n\n\n\n");
    fclose(out);
}