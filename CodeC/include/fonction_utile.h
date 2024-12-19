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
 * Determinate the minimum between the two value in parameter
 */
int min(int a, int b);

/**
 * @param a
 * @param b
 * Determinate the maximum between the two value in parameter
 */
int max(int a, int b);

/**
 * @param head
 * Free the memory
 */
void freeAvl(tree* head);

/**
* @param a
* Check if the Data in parameter is a lv station
*/
int isLv(Data a);

/**
* @param a
* Check if the Data in parameter is a hvb station
*/
int isHvb(Data a);

/**
* @param a
* Check if the Data in parameter is a hva station
*/
int isHva(Data a);

/**
* @param i
* @param head
* Determinate the number of nodes in an avl
*/
void nbNodes(long long unsigned* i, tree* head);

/**
* Initialize the data
*/
Data* init();

/**
* @param origin
* @param toAdd
* Add two char* into one char*
*/
char* addCharToChar(char* origin, char* toAdd);

/**
* @param i
* Determinate the absolute value between the two value in parameter
*/

#endif //FONCTION_UTILE

