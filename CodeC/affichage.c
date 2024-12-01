#include "include/affichage.h"

void traiter(arbre* tete){
    if (tete != NULL){
        printf("%lu %lu %lu %lu %lu %lu %lu %lu\n",
               tete->a.Powerplant, tete->a.hv_b, tete->a.hv_a, tete->a.lv, tete->a.entreprise, tete->a.particuliers, tete->a.production, tete->a.consommation);
    }
}