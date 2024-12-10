#include "include/type_avl.h"
#include "include/create_avl.h"
#include "include/fonction_utile.h"

FILE* transformerFichier(FILE* fichier){
    if (fichier == NULL){
        exit(1);
    }
    FILE* out = fopen("../tmp/tmp.txt", "w");
    if (out == NULL){
        exit(1);
    }
    char line[256];
    while (fgets(line, sizeof(line), fichier)) {
        // Remplacer chaque '-' par '0'.
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] == '-') {
                line[i] = '0';
            }
        }
        // Écrire la line modifiée dans le fichier de sortie.
        fputs(line, out);
    }
    fclose (fichier);
    fclose (out);
    out = fopen("../tmp/tmp.txt", "r");
    if (out == NULL){
        exit(1);
    }
    return out;
}

void ensembleDonne(FILE* fichier, int* hStation, int* hConso, tree** stationTree, tree** consoTree, char* type) {
    if (fichier == NULL) {
        exit(1);
    }
    FILE *out = transformerFichier(fichier);
    char line2[256];
    Data* tmp = NULL;
    tmp = init();
    if (tmp == NULL){
        exit(1);
    }
    int i = 0;
    sscanf(line2, "%lu;%lu;%lu;%lu;%lu;%lu;%lu;%lu;",
           &tmp->Powerplant, &tmp->hv_b, &tmp->hv_a, &tmp->lv, &tmp->entreprise, &tmp->particuliers, &tmp->production, &tmp->consommation);
    addTree(stationTree, consoTree, *tmp, hStation, hConso, type, tmp,  &i);
    Data b;
    tree *head = NULL;
    fgets(line2, sizeof(line2), out);
    while (fgets(line2, sizeof(line2), out) != NULL) {
        sscanf(line2, "%lu;%lu;%lu;%lu;%lu;%lu;%lu;%lu;",
               &b.Powerplant, &b.hv_b, &b.hv_a, &b.lv, &b.entreprise, &b.particuliers, &b.production, &b.consommation);
        addTree(stationTree, consoTree, b, hStation, hConso, type, tmp, &i);
    }
    printf("\n\n\n\n");
    fclose(out);
}