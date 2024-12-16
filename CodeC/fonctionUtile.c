#include "include/fonction_utile.h"

/**
 * @param a
 * @param b
 * Determinate the minimum between the two value in parameter
 */
int min(int a, int b) {
    if (a < b){
        return a;
    } else {
        return b;
    }
    return 0;
}

/**
 * @param a
 * @param b
 * Determinate the maximum between the two value in parameter
 */
int max(int a, int b) {
    if (a < b){
        return b;
    } else {
        return a;
    }
    return 0;
}

/**
 * @param i
 * @param j
 * Determinate the absolute value between the two value in parameter
 */
int absoluteValue(long unsigned i, long unsigned j){
    long long int tmp = i - j;
    if (tmp < 0){
        return -tmp;
    } else {
        return tmp;
    }
}

/**
 * @param head
 * Free the memory
 */
void freeAvl(tree* head) {
    if (head == NULL) {
        return;
    }
    freeAvl(head->fg);
    freeAvl(head->fd);
    free(head);
}

/**
 * @param a
 * Check if the Data in parameter is a lv station
 */
int isLv(Data a){
    if (a.lv != 0 && a.consumption == 0){
        return 1;
    } else {
        return 0;
    }
    return 0;
}

/**
 * @param a
 * Check if the Data in parameter is a hvb station
 */
int isHvb(Data a){
    if (a.hv_b != 0 && a.hv_a == 0 && a.lv == 0 && a.production != 0){
        return 1;
    } else {
        return 0;
    }
    return 0;
}

/**
 * @param a
 * Check if the Data in parameter is a hva station
 */
int isHva(Data a){
    if (a.hv_a != 0 && a.lv == 0 && a.production != 0){
        return 1;
    } else {
        return 0;
    }
    return 0;
}

/**
 * @param i
 * @param head
 * Determinate the number of nodes in an avl
 */
void nbNodes(long long unsigned * i, tree* head){
    if (head != NULL && i != NULL){
        *i = *i+1;
        nbNodes(i, head->fg);
        nbNodes(i, head->fd);
    }
}

/**
 * Initialize the data
 */
Data* init(){
    Data* tmp = NULL;
    tmp = malloc(sizeof(Data));
    if (tmp == NULL){
        exit(30);
    }
    tmp->lv = 0;
    tmp->hv_a = 0;
    tmp->hv_b = 0;
    tmp->consumption = 0;
    tmp->id = 1;
    tmp->consumer = 0;
    tmp->company = 0;
    tmp->Powerplant = 0;
    tmp->production = 0;
    return tmp;
}

/**
 * @param origin
 * @param toAdd
 * Add two char* into one char*
 */
char* addCharToChar(char* origin, char* toAdd){
    if (origin == NULL || toAdd == NULL){
        exit(1);
    }
    char* tmp = NULL;
    int newSize = strlen(origin) + strlen(toAdd) + 1;
    tmp = malloc((newSize * sizeof(char)));
    strcpy(tmp, origin);
    strcat(tmp, toAdd);
    return tmp;
}