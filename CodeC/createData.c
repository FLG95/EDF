#include "include/createData.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"

/**
 * @param fichier
 * Transform the "-" of the file by "0"
 */
void transformerFichier(FILE* fichier, int pipe_write) {

    if (fichier == NULL) {
        exit(30);
    }

    char line[256];
    while (fgets(line, sizeof(line), fichier) != NULL) {
        // Remplacer chaque '-' par '0'.
        for (int i = 0; i < strlen(line); i++) {
            if (line[i] == '-') {
                line[i] = '0';
            }

        }

        // Écrire la line modifiée dans le fichier de sortie.
        ssize_t bytes_written = write(pipe_write, line, strlen(line));
        if (bytes_written == -1) {
            perror("Erreur d'écriture dans le pipe");
            close(pipe_write); // S'assurer de fermer proprement
            exit(EXIT_FAILURE);
        }
    }
    close(pipe_write);
}

/**
 * @param fichier
 * @param hStation
 * @param stationTree
 * @param type
 * Take data of a File and add it to a tree
 */
void ensembleDonne(int* hStation, tree** stationTree, char* type, int pipe_read) {

    if (hStation == NULL || type == NULL) {
        exit(30);
    }

    FILE* pipe_stream = fdopen(pipe_read, "r");
    if(pipe_stream == NULL){
        exit(100);
    }

    char line[256];
    Data* tmp = NULL;
    tmp = init();
    if (tmp == NULL){
        exit(30);
    }
    int i = 0;
    sscanf(line, "%lu;%lu;%lu;%lu;%lu;%lu;%lu;%lu;",
           &tmp->Powerplant, &tmp->hv_b, &tmp->hv_a, &tmp->lv, &tmp->company, &tmp->consumer, &tmp->production, &tmp->consumption);
    addTree(stationTree, *tmp, hStation, type, tmp,  &i);
    Data b;
    fgets(line, sizeof(line), pipe_stream);
    while (fgets(line, sizeof(line), pipe_stream) != NULL) {
        sscanf(line, "%lu;%lu;%lu;%lu;%lu;%lu;%lu;%lu;",
               &b.Powerplant, &b.hv_b, &b.hv_a, &b.lv, &b.company, &b.consumer, &b.production, &b.consumption);
        addTree(stationTree, b, hStation, type, tmp, &i);
    }
    free(tmp);
}