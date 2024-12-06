#ifndef creerDonnees
#define creerDonnees

#include <stdio.h>
#include <stdlib.h>

#include "type_avl.h"
#include "fonction_utile.h"

FILE* transformerFichier(FILE* fichier);
void ensembleDonne(FILE* fichier, int* hStation, int* hConso, arbre** stationTree, arbre** consoTree, char* type);


#endif //CreerDonnees