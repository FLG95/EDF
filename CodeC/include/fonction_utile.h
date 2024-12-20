#ifndef FONCTION_UTILE
#define FONCTION_UTILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "type_avl.h"
#include "create_avl.h"

/**
 * @param a
 * @param b
 * This function determinate the minimum between the two value in parameter
 */
int min(int a, int b);

/**
 * @param a
 * @param b
 * This function determinate the maximum between the two value in parameter
 */
int max(int a, int b);

/**
 * @param head
 * This function free the memory of an AVL
 */
void freeAvl(tree* head);

/**
 * @param a
 * This function check if the Data in parameter is a lv station
 */
int isLv(Data a);

/**
 * @param a
 * This function check if the Data in parameter is a hvb station
 */
int isHvb(Data a);

/**
 * @param a
 * This function check if the Data in parameter is a hva station
 */
int isHva(Data a);

/**
 * @param i
 * @param head
 * This function determinate the number of node(s) in an avl
 */
void nbNodes(long long int * i, tree* head);

/**
 * @param origin
 * @param toAdd
 * This function add two char* into one char*
 */
char* addCharToChar(char* origin, char* toAdd);

#endif //FONCTION_UTILE