#ifndef createData
#define createData

#include <stdio.h>
#include <stdlib.h>

#include "type_avl.h"
#include "fonction_utile.h"

FILE* transformerFichier(FILE* fichier);
void ensembleDonne(FILE* fichier, int* hStation, int* hConso, tree** stationTree, tree** consoTree, char* type);


#endif //createData