#ifndef outFile
#define outFile

#include <stdio.h>
#include <stdlib.h>

#include "type_avl.h"
#include "fonction_utile.h"

/**
 * @param head
 * @param h
 * @param fichier
 * @param arg1
 * @param arg2
 * Write in a file 10 data
 */
void write10sup(tree* head, int* h, FILE* fichier, char* arg1, char* arg2);

/**
 * @param head
 * @param h
 * @param fichier
 * Write in a file 10 data
 */
void write10less(tree* head, int* h, FILE* fichier);

/**
 * @param head
 * @param arg1
 * @param arg2
 * Write in a file 20 data and create the file to write that
 */
void centerWrite10(tree* head, char* arg1, char* arg2);

/**
 * @param head
 * @param fichier
 * @param h
 * @param arg1
 * @param arg2
 * Write all the nodes of an avl in a file
 */
void writeAllData(tree* head, FILE* fichier, int* h, char* arg1, char* arg2);

/**
 * @param head
 * @param arg2
 * @param arg3
 * Create the file to write all the nodes of an avl
 */
void centerWrite(tree* head, char* arg2, char* arg3);

#endif //OutFile