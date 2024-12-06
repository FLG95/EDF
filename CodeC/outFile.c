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

void centerWrite(arbre* tete){
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