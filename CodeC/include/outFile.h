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
 * This function write in a file the 10 data which are the most on the right of the AVL
 */
void write10sup(tree* head, int* h, FILE* fichier);

/**
 * @param head
 * @param h
 * @param fichier
 * This function write in a file the 10 data which are the most on the left of the AVL
 */
void write10less(tree* head, int* h, FILE* fichier);

/**
 * @param fichier
 * @param arg1
 * @param arg2
 * This function put documentation on the top of the file
 */
void addHighDocumentation(FILE* fichier, char* arg1, char* arg2);

/**
 * @param head
 * @param arg1
 * @param arg2
 * This function create a file for the 20 data
 */
void centerWrite10(tree* head, char* arg1, char* arg2);

/**
 * @param head
 * @param fichier
 * @param h
 * @param arg1
 * @param arg2
 * This function write all the nodes of an avl in a file
 */
void writeAllData(tree* head, FILE* fichier, int* h, char* arg1, char* arg2);

/**
 * @param head
 * @param arg2
 * @param arg3
 * @param arg4
 * This function create the file to write all the nodes of the stationTree
 */
void centerWrite(tree* head, char* arg2, char* arg3, char* arg4);

#endif //OutFile