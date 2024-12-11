#ifndef FONCTION_UTILE
#define FONCTION_UTILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "type_avl.h"
#include "create_avl.h"

int min(int a, int b);
int max(int a, int b);
void freeAvl(tree* head);
int isLv(Data a);
int isHvb(Data a);
int isHva(Data a);
void nbNodes(long long unsigned* i, tree* head);
Data* init();
char* addCharToChar(char* origin, char* toAdd);
int absoluteValue(long unsigned i, long unsigned j);

#endif //FONCTION_UTILE

