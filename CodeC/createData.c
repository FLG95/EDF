#include "include/createData.h"

/**
 * @param fichier
 * This function transform the "-" of the file by "0"
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
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] == '-') {
                line[i] = '0';
            }
        }
        fputs(line, new_file);
    }
    fclose (fichier);
    fclose (new_file);
    new_file = fopen("../tmp/tmp.txt", "r");
    if (new_file == NULL){
        exit(30);
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
void ensembleDonne(FILE* fichier, int* hStation, int* hConso, tree** stationTree, tree** consoTree, char* type) {
    if (fichier == NULL || hStation == NULL || stationTree == NULL || type == NULL) {
        printf("Erreur : arguments invalides.\n");
        exit(30);
    }
    //Transform the file which has been sort by the shell. It replaces the '-' by '0'
    FILE* new_file = transformerFichier(fichier);
    if (new_file == NULL){
        exit(30);
    }
    char line[256];

    Data b;
    int i = 0;

    //Read the first line of the document
    if (fgets(line, sizeof(line), new_file) != NULL) {
        sscanf(line, "%lld;%lld;%lld;%lld;%lld;%lld;%lld;%lld;",
               &b.Powerplant, &b.hv_b, &b.hv_a, &b.lv,
               &b.company, &b.consumer, &b.production, &b.consumption);

        //Add data to the stationTree or the consoTree
        addTree(stationTree, consoTree, b, hStation, hStation, type, &i);
    }
    //Read the line of the document
    while (fgets(line, sizeof(line), new_file) != NULL) {
        sscanf(line, "%lld;%lld;%lld;%lld;%lld;%lld;%lld;%lld;",
               &b.Powerplant, &b.hv_b, &b.hv_a, &b.lv,
               &b.company, &b.consumer, &b.production, &b.consumption);
        //Add data to the stationTree or the consoTree
        addTree(stationTree, consoTree, b, hStation, hConso, type, &i);
    }
    fclose(new_file);
}