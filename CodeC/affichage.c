#include "include/affichage.h"

void traiter(tree* head){
    if (head != NULL){
        printf("%lu %lu %lu %lu %lu %lu %lu %lu\n",
               head->a.Powerplant, head->a.hv_b, head->a.hv_a, head->a.lv, head->a.entreprise, head->a.particuliers, head->a.production, head->a.consommation);
    }
}