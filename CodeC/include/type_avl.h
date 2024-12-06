#ifndef TYPE_AVL
#define TYPE_AVL

#include <stdint.h>
typedef struct donnees{
    int id;
    long unsigned Powerplant;
    long unsigned hv_b;
    long unsigned hv_a;
    long unsigned lv;
    long unsigned entreprise;
    long unsigned particuliers;
    long unsigned consommation;
    long unsigned production;
} donnees;
typedef struct arbre {
    donnees a;
    struct arbre* fd;
    struct arbre* fg;
    int equilibre;
} arbre;
typedef struct file {
    int a;
    arbre* actuel;
    struct file* suivant;
} file;

#endif //TYPE_AVL