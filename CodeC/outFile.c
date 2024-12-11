#include "include/outFile.h"
void write10sup(tree* head, int* h, FILE* fichier, char* arg1, char* arg2){

    if (head != NULL && *h < 10) {
        write10sup(head->fd, h, fichier, arg1, arg2);
        if (*h == 0){
            fprintf(fichier, "Station %s : Capacity : Consommation %s\n", arg1, arg2);
        }
        if (*h < 10) {
            *h = *h + 1;
            fprintf(fichier, "%d:%lu:%lu\n",
                    head->a.id, head->a.production, head->a.consommation);
        }
        write10sup(head->fg, h, fichier, arg1, arg2);
    }
}
void write10less(tree* head, int* h, FILE* fichier){
    long long unsigned i = 0;
    if (head != NULL){

        nbNodes(&i, head);
        if (i != 1){

        }
    }
    if (head != NULL && *h < 10) {
        write10less(head->fg, h, fichier);
        if (*h < 10) {
            *h = *h + 1;
            fprintf(fichier, "%d:%lu:%lu\n",
                    head->a.id, head->a.production, head->a.consommation);
        }
        write10less(head->fd, h, fichier);
    }
}

void centerWrite10(tree* head, char* arg1, char* arg2){
    if (head == NULL){
        exit(1);
    }
    int h_sup = 0;
    int h_inf = 0;

    FILE* fichier = fopen("../resultats/lv_minmax.csv", "w");
    if (fichier == NULL){
        exit(1);
    }
    write10sup(head ,&h_sup, fichier, arg1, arg2);
    write10less(head, &h_inf, fichier);
    fclose(fichier);
}


void writeAllData(tree* head, FILE* fichier, int* h, char* arg1, char* arg2){
    if (head != NULL ){
        if (*h == 0){
            *h = *h + 1;
            fprintf(fichier, "Station %s : Capacity : Consommation %s\n", arg1, arg2);
        }
        writeAllData(head->fg, fichier, h, arg1, arg2);
        writeAllData(head->fd, fichier, h, arg1, arg2);
        fprintf(fichier, "%d:%lu:%lu\n",
        head->a.id, head->a.production, head->a.consommation);

    }
}
void centerWrite(tree* head, char* arg2, char* arg3){
    if (head == NULL){
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