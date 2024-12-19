#ifndef TYPE_AVL
#define TYPE_AVL

#include <stdint.h>

/**
 * structure for the data in the code
 * id of the station
 * hvb station
 * hva station
 * lv station
 * company
 * consumer
 * consumption
 * praduciton
 */
typedef struct Data{
    int id;
    long long int Powerplant;
    long long int hv_b;
    long long int hv_a;
    long long int lv;
    long long int company;
    long long int consumer;
    long long int consumption;
    long long int production;
} Data;

/**
 * structure for the AVL tree
 * data
 * fd
 * fg
 * balance
 */
typedef struct tree {
    Data a;
    struct tree* fd;
    struct tree* fg;
    int balance;
} tree;

#endif //TYPE_AVL