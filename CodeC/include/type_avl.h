#ifndef TYPE_AVL
#define TYPE_AVL

#include <stdint.h>
typedef struct Data{
    int id;
    long unsigned Powerplant;
    long unsigned hv_b;
    long unsigned hv_a;
    long unsigned lv;
    long unsigned entreprise;
    long unsigned particuliers;
    long unsigned consommation;
    long unsigned production;
} Data;
typedef struct tree {
    Data a;
    struct tree* fd;
    struct tree* fg;
    int balance;
} tree;

#endif //TYPE_AVL