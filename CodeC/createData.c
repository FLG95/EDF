#include "include/createData.h"
/**
 * @param fichier
 * Transform the "-" of the file by "0"
 */
FILE* transformerFichier(FILE* fichier){
    if (fichier == NULL){
        exit(30);
    }
    FILE* new_file = fopen("../tmp/tmp.txt", "w");
    if (new_file == NULL){
        exit(30);
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


/**
 * @param fichier
 * @param hStation
 * @param stationTree
 * @param type
 * Take data of a File and add it to a tree
 */
void ensembleDonne(FILE* fichier, int* hStation, tree** stationTree, char* type) {
    if (fichier == NULL || hStation == NULL && type == NULL) {
        exit(30);
    }
    FILE *new_file = transformerFichier(fichier);
    char line2[256];
    Data* tmp = NULL;
    tmp = init();
    if (tmp == NULL){
        exit(30);
    }
    int i = 0;
    sscanf(line2, "%lli;%lli;%lli;%lli;%lli;%lli;%lli;%lli;",
           &tmp->Powerplant, &tmp->hv_b, &tmp->hv_a, &tmp->lv, &tmp->company, &tmp->consumer, &tmp->production, &tmp->consumption);
    addTree(stationTree, *tmp, hStation, type, tmp,  &i);
    Data b;
    tree *head = NULL;
    fgets(line2, sizeof(line2), new_file);
    while (fgets(line2, sizeof(line2), new_file) != NULL) {
        sscanf(line2, "%lli;%lli;%lli;%lli;%lli;%lli;%lli;%lli;",
               &b.Powerplant, &b.hv_b, &b.hv_a, &b.lv, &b.company, &b.consumer, &b.production, &b.consumption);
        addTree(stationTree, b, hStation, type, tmp, &i);
    }
    free(tmp);
    fclose(new_file);
}