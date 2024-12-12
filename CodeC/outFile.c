#include "include/outFile.h"

//Write in a file 10 data
void write10sup(tree* head, int* h, FILE* fichier, char* arg1, char* arg2){
    if (head != NULL && h != NULL && fichier != NULL && arg1 != NULL && arg2 != NULL && *h < 10) {
        write10sup(head->fd, h, fichier, arg1, arg2);
        if (*h == 0){
            fprintf(fichier, "Station %s : Capacity : consumption %s\n", arg1, arg2);
        }
        if (*h < 10) {
            *h = *h + 1;
            fprintf(fichier, "%d:%lu:%lu\n",
                    head->a.id, head->a.production, head->a.consumption);
        }
        write10sup(head->fg, h, fichier, arg1, arg2);
    }
}

//Write in a file 10 data
void write10less(tree* head, int* h, FILE* fichier){
    long long unsigned i = 0;

    if (head != NULL && h != NULL && fichier != NULL && *h < 10) {
        write10less(head->fg, h, fichier);
        if (*h < 10) {
            *h = *h + 1;
            fprintf(fichier, "%d:%lu:%lu\n",
                    head->a.id, head->a.production, head->a.consumption);
        }
        write10less(head->fd, h, fichier);
    }
}

//Write in a file 20 data and create the file to write that
void centerWrite10(tree* head, char* arg1, char* arg2){
    if (head == NULL && arg1 == NULL && arg2 == NULL){
        exit(1);
    }
    int h_sup = 0;
    int h_inf = 0;
    long long unsigned i = 0;
    nbNodes(&i, head);
    FILE* fichier = fopen("../resultats/lv_minmax.csv", "w");
    if (fichier == NULL){
        exit(1);
    }
    if (i <= 10){
        write10sup(head ,&h_sup, fichier, arg1, arg2);
    } else if (i < 20 && i > 10){
        h_inf = 20 - i;
        write10sup(head ,&h_sup, fichier, arg1, arg2);
        write10less(head, &h_inf, fichier);
    } else {
        write10sup(head ,&h_sup, fichier, arg1, arg2);
        write10less(head, &h_inf, fichier);
    }
    fclose(fichier);
}

//Write all the nodes of an avl in a file
void writeAllData(tree* head, FILE* fichier, int* h, char* arg1, char* arg2){
    if (head != NULL && fichier != NULL && h != NULL && arg1 != NULL && arg2 != NULL){
        if (*h == 0){
            *h = *h + 1;
            fprintf(fichier, "Station %s : Capacity : consumption %s\n", arg1, arg2);
        }
        writeAllData(head->fg, fichier, h, arg1, arg2);
        writeAllData(head->fd, fichier, h, arg1, arg2);
        fprintf(fichier, "%d:%lu:%lu\n",
        head->a.id, head->a.production, head->a.consumption);

    }
}

//Create the file to write all the nodes of an avl
void centerWrite(tree* head, char* arg2, char* arg3){
    if (head == NULL || arg2 == NULL || arg3 == NULL){
        exit(1);
    }
    int h = 0;
    char* underscore = "_";
    char* destination = addCharToChar("../resultats/", arg2);
    destination = addCharToChar(destination, underscore);
    destination = addCharToChar(destination, arg3);
    destination = addCharToChar(destination, ".csv");
    FILE* fichierAll = fopen(destination, "w");
    if (fichierAll == NULL){
        exit(1);
    }

    writeAllData(head, fichierAll, &h, arg2, arg3);
    fclose(fichierAll);
}