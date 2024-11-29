#ifndef TYPE_AVL
#define TYPE_AVL

#include <stdint.h>
typedef struct donnees{
    uint64_t Powerplant;
    uint64_t hv_b;
    uint64_t hv_a;
    uint64_t lv;
    uint64_t entreprise;
    uint64_t particuliers;
    uint64_t consommation;
    uint64_t production;
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