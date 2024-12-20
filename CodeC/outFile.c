#include "include/outFile.h"

/**
 * @param head
 * @param h
 * @param fichier
 * This function write in a file the 10 data which are the most on the right of the AVL
 */
void write10sup(tree* head, int* h, FILE* fichier){
    if (head != NULL && h != NULL && fichier != NULL && *h < 10) {
        write10sup(head->fd, h, fichier);
        if (*h < 10) {
            *h = *h + 1;
            fprintf(fichier, "%d:%lli:%lli\n",
                    head->a.id, head->a.production, head->a.consumption);
        }
        write10sup(head->fg, h, fichier);
    }
}

/**
 * @param head
 * @param h
 * @param fichier
 * This function write in a file the 10 data which are the most on the left of the AVL
 */
void write10less(tree* head, int* h, FILE* fichier){
    long long int i = 0;

    if (head != NULL && h != NULL && fichier != NULL && *h < 10) {
        write10less(head->fg, h, fichier);
        if (*h < 10) {
            *h = *h + 1;
            fprintf(fichier, "%d:%lli:%lli\n",
                    head->a.id, head->a.production, head->a.consumption);
        }
        write10less(head->fd, h, fichier);
    }
}

/**
 * @param fichier
 * @param arg1
 * @param arg2
 * This function put documentation on the top of the file
 */
void addHighDocumentation(FILE* fichier, char* arg1, char* arg2){
    if (fichier == NULL || arg1 == NULL || arg2 == NULL){
        exit(70);
    }
    fprintf(fichier, "Station %s : Capacity : consumption (%s)\n", arg1, arg2);
}

/**
 * @param head
 * @param arg1
 * @param arg2
 * This function create a file for the 20 data
 */
void centerWrite10(tree* head, char* arg1, char* arg2) {
    if (head == NULL && arg1 == NULL && arg2 == NULL) {
        exit(50);
    }
    int h_sup = 0;
    int h_inf = 0;
    long long int i = 0;
    nbNodes(&i, head);
    FILE *fichier = fopen("../tmp/lv_all_minmax_temp.csv", "w");
    if (fichier == NULL) {
        exit(70);
    }
    addHighDocumentation(fichier, arg1, arg2);
    if (i <= 10) {
        write10less(head, &h_sup, fichier);
    } else if (i < 20 && i > 10) {
        h_sup = 20 - i;
        write10less(head, &h_inf, fichier);
        write10sup(head, &h_sup, fichier);
    } else {
        write10less(head, &h_inf, fichier);
        write10sup(head, &h_sup, fichier);
    }
    fclose(fichier);
}

/**
 * @param head
 * @param fichier
 * @param h
 * @param arg1
 * @param arg2
 * This function write all the nodes of an avl in a file
 */
void writeAllData(tree* head, FILE* fichier, int* h, char* arg1, char* arg2){
    if (head != NULL && fichier != NULL && h != NULL && arg1 != NULL && arg2 != NULL){
        if (*h == 0){
            *h = *h + 1;
            fprintf(fichier, "Station %s : Capacity : consumption (%s)\n", arg1, arg2);
        }
        writeAllData(head->fg, fichier, h, arg1, arg2);
        fprintf(fichier, "%d:%lli:%lli\n",
                head->a.id, head->a.production, head->a.consumption);
        writeAllData(head->fd, fichier, h, arg1, arg2);
    }
}


/**
 * @param head
 * @param arg2
 * @param arg3
 * @param arg4
 * This function create the file to write all the nodes of the stationTree
 */
void centerWrite(tree* head, char* arg2, char* arg3, char* arg4){
    if (head == NULL || arg2 == NULL || arg3 == NULL){
        exit(50);
    }
    int h = 0;
    char* destination = NULL;
    destination = addCharToChar("../results/", arg2);
    if (destination == NULL){
        exit(30);
    }
    destination = addCharToChar(destination, "_");
    if (destination == NULL){
        exit(30);
    }
    destination = addCharToChar(destination, arg3);
    if (destination == NULL){
        exit(30);
    }
    if (arg4 != NULL){
        destination = addCharToChar(destination, "_");
        destination = addCharToChar(destination, arg4);
    }
    destination = addCharToChar(destination, ".csv");
    FILE* fichierAll = fopen(destination, "w");
    if (fichierAll == NULL){
        exit(70);
    }

    writeAllData(head, fichierAll, &h, arg2, arg3);
    fclose(fichierAll);
    free(destination);
    destination = NULL;
}