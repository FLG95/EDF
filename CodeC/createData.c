#include "include/type_avl.h"
#include "include/create_avl.h"
#include "include/fonction_utile.h"


//Transform the "-" of the file by "0"
FILE* transformerFichier(FILE* fichier){
    if (fichier == NULL){
        exit(1);
    }
    FILE* new_file = fopen("../tmp/tmp.txt", "w");
    if (new_file == NULL){
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
        fputs(line, new_file);
    }
    fclose (fichier);
    fclose (new_file);
    new_file = fopen("../tmp/tmp.txt", "r");
    if (new_file == NULL){
        exit(1);
    }
    return new_file;
}

//Take data of a File and add it to a tree
void ensembleDonne(FILE* fichier, int* hStation, tree** stationTree, char* type) {
    if (fichier == NULL || hStation == NULL && type == NULL) {
        exit(1);
    }
    FILE *new_file = transformerFichier(fichier);
    char line2[256];
    Data* tmp = NULL;
    tmp = init();
    if (tmp == NULL){
        exit(1);
    }
    int i = 0;
    sscanf(line2, "%lu;%lu;%lu;%lu;%lu;%lu;%lu;%lu;",
           &tmp->Powerplant, &tmp->hv_b, &tmp->hv_a, &tmp->lv, &tmp->entreprise, &tmp->particuliers, &tmp->production, &tmp->consumption);
    addTree(stationTree, *tmp, hStation, type, tmp,  &i);
    Data b;
    tree *head = NULL;
    fgets(line2, sizeof(line2), new_file);
    while (fgets(line2, sizeof(line2), new_file) != NULL) {
        sscanf(line2, "%lu;%lu;%lu;%lu;%lu;%lu;%lu;%lu;",
               &b.Powerplant, &b.hv_b, &b.hv_a, &b.lv, &b.entreprise, &b.particuliers, &b.production, &b.consumption);
        addTree(stationTree, b, hStation, type, tmp, &i);
    }
    printf("\n\n\n\n");
    fclose(new_file);
}