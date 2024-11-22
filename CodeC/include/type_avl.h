#ifndef TYPE_AVL
#define TYPE_AVL

typedef struct arbre {
    int nb;
    struct arbre* fd;
    struct arbre* fg;
    int equilibre;
} arbre;
typedef struct file {
    arbre* actuel;
    struct file* suivant;
} file;

#endif //TYPE_AVL