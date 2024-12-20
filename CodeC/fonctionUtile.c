#include "include/fonction_utile.h"

/**
 * @param a
 * @param b
 * This function determinate the minimum between the two value in parameter
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
 * This function determinate the maximum between the two value in parameter
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
 * @param head
 * This function free the memory of an AVL
 */
void freeAvl(tree* head) {
    if (head != NULL) {
        freeAvl(head->fg);
        freeAvl(head->fd);
        free(head);
    }
}

/**
 * @param a
 * This function check if the Data in parameter is a lv station
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
 * This function check if the Data in parameter is a hvb station
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
 * This function check if the Data in parameter is a hva station
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
 * This function determinate the number of node(s) in an avl
 */
void nbNodes(long long int * i, tree* head){
    if (head != NULL && i != NULL){
        *i = *i+1;
        nbNodes(i, head->fg);
        nbNodes(i, head->fd);
    }
}

/**
 * @param origin
 * @param toAdd
 * This function add two char* into one char*
 */
char* addCharToChar(char* origin, char* toAdd){
    if (origin == NULL || toAdd == NULL){
        exit(70);
    }
    char* tmp = NULL;
    int newSize = strlen(origin) + 1 + strlen(toAdd) + 1 ;
    tmp = malloc((newSize * sizeof(char)));
    if (tmp == NULL){
        exit(70);
    }
    strcpy(tmp, origin);
    strcat(tmp, toAdd);
    return tmp;
}