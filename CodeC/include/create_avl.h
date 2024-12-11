#ifndef create_AVL_H
#define create_AVL_H
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "type_avl.h"
#include "parcours.h"
#include "fonction_utile.h"





tree* create(Data a);
tree* leftRotation(tree* head);
tree* RightRotation(tree* head);
tree* doubleLeftRotation(tree* head);
tree* doubleRightRotation(tree* head);
tree* balancing(tree* head);
tree* insertStation(tree* head, Data a, int* h);
int height(tree* head);
bool isAVL(tree* head);
void addTree(tree** stationTree, tree** consoTree, Data b, int* hStation, int* hConso, char* station, Data* tmp, int* i);
tree* sortByProduction(tree* out, Data tmp, int* h);
tree* sortByAbs(tree* out, Data tmp, int* h);

#endif //create_AVL