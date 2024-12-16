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
    long unsigned Powerplant;
    long unsigned hv_b;
    long unsigned hv_a;
    long unsigned lv;
    long unsigned company;
    long unsigned consumer;
    long unsigned consumption;
    long unsigned production;
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