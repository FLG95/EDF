#ifndef createData
#define createData

#include <stdio.h>
#include <stdlib.h>

#include "type_avl.h"
#include "fonction_utile.h"
#include "create_avl.h"

/**
 * @param fichier
 * This function transform the "-" of the file by "0"
 */
FILE* transformerFichier(FILE* fichier);

/**
 * @param fichier
 * @param hStation
 * @param stationTree
 * @param type
 * Take data of a File and add it to a tree
 */
void ensembleDonne(FILE* fichier, int* hStation, int* hConso, tree** stationTree, tree** consoTree, char* type);

#endif //createData