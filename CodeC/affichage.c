#include <stdio.h>
#include <stdlib.h>

#include "include/affichage.h"

void traiter(arbre* tete){
    if (tete != NULL){
        printf("%d\n", tete->nb);
    }
}