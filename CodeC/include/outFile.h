#ifndef outFile
#define outFile

#include <stdio.h>
#include <stdlib.h>

#include "type_avl.h"

void write10sup(arbre* tete, int* h, FILE* fichier);
void write10less(arbre* tete, int* h, FILE* fichier);
void centerWrite(arbre* tete);

#endif //OutFile