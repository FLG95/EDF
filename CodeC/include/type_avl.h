#ifndef TYPE_AVL
#define TYPE_AVL
typedef struct donnees{
    int Powerplant;
    int hv_b;
    int hv_a;
    int lv;
    int entreprise;
    int particuliers;
    int consommation;
    int production;
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