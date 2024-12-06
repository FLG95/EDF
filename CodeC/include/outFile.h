#ifndef outFile
#define outFile

#include <stdio.h>
#include <stdlib.h>

#include "type_avl.h"
#include "fonction_utile.h"

void write10sup(arbre* tete, int* h, FILE* fichier);
void write10less(arbre* tete, int* h, FILE* fichier);
void centerWrite10(arbre* tete);
void writeAllData(arbre* tete, FILE* fichier, int* h, char* arg1, char* arg2);
void centerWrite(arbre* tete, char* arg2, char* arg3);

#endif //OutFile