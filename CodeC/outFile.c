#include "include/outFile.h"
void write10sup(arbre* tete, int* h, FILE* fichier){

    if (tete != NULL && *h < 10) {
        write10sup(tete->fd, h, fichier);
        if (*h == 0){
            fprintf(fichier, "PowerPlant:hvb:hva:lv:entreprise:particulier:production:consommation\n");
        }
        if (*h < 10) {
            *h = *h + 1;
            fprintf(fichier, "%lu:%lu:%lu:%lu:%lu:%lu:%lu:%lu\n",
                    tete->a.Powerplant, tete->a.hv_b, tete->a.hv_a,
                    tete->a.lv, tete->a.entreprise, tete->a.particuliers,
                    tete->a.production, tete->a.consommation);
        }
        write10sup(tete->fg, h, fichier);
    }
}
void write10less(arbre* tete, int* h, FILE* fichier){

    if (tete != NULL && *h < 10) {
        // Parcours du sous-arbre gauche
        write10less(tete->fg, h, fichier);
        if (*h == 0){
            fprintf(fichier, "PowerPlant:hvb:hva:lv:entreprise:particulier:production:consommation\n");
        }
        if (*h < 10) {
            *h = *h + 1;
            fprintf(fichier, "%lu:%lu:%lu:%lu:%lu:%lu:%lu:%lu\n",
                    tete->a.Powerplant, tete->a.hv_b, tete->a.hv_a,
                    tete->a.lv, tete->a.entreprise, tete->a.particuliers,
                    tete->a.production, tete->a.consommation);
        }
        write10less(tete->fd, h, fichier);
    }
}

void centerWrite10(arbre* tete){
    if (tete == NULL){
        exit(1);
    }
    int h_sup = 0;
    int h_inf = 0;
    FILE* fichier_sup = fopen("../tmp/data_sup.txt", "w");
    FILE* fichier_inf = fopen("../tmp/data_inf.txt", "w");
    if (fichier_inf == NULL || fichier_sup == NULL){
        exit(1);
    }
    write10sup(tete ,&h_sup, fichier_sup);
    write10less(tete, &h_inf, fichier_inf);
    fclose(fichier_sup);
    fclose(fichier_inf);
}


void writeAllData(arbre* tete, FILE* fichier, int* h, char* arg1, char* arg2){
    if (tete != NULL ){
        if (*h == 0){
            *h = *h + 1;
            fprintf(fichier, "Station %s : Capacité : Consommation %s\n", arg1, arg2);
        }
        writeAllData(tete->fg, fichier, h, arg1, arg2);
        fprintf(fichier, "%d:%lu:%lu\n",
        tete->a.id, tete->a.production, tete->a.consommation);
        writeAllData(tete->fd, fichier, h, arg1, arg2);
    }
}
void centerWrite(arbre* tete, char* arg2, char* arg3){
    if (tete == NULL){
        exit(1);
    }
    int h = 0;
    char* underscore = "_";
    char* destination = addCharToChar("../tmp/", arg2);
    destination = addCharToChar(destination, underscore);
    destination = addCharToChar(destination, arg3);
    destination = addCharToChar(destination, ".csv");
    FILE* fichierAll = fopen(destination, "w");
    if (fichierAll == NULL){
        exit(1);
    }

    writeAllData(tete, fichierAll, &h, arg2, arg3);
    fclose(fichierAll);
}