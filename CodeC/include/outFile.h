#ifndef outFile
#define outFile

#include <stdio.h>
#include <stdlib.h>

#include "type_avl.h"
#include "fonction_utile.h"

void write10sup(tree* head, int* h, FILE* fichier, char* arg1, char* arg2);
void write10less(tree* head, int* h, FILE* fichier);
void centerWrite10(tree* head, char* arg1, char* arg2);
void writeAllData(tree* head, FILE* fichier, int* h, char* arg1, char* arg2);
void centerWrite(tree* head, char* arg2, char* arg3);

#endif //OutFile