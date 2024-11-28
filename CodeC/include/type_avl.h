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
    int nb;
    struct arbre* fd;
    struct arbre* fg;
    int equilibre;
} arbre;
typedef struct file {
    donnees a;
    arbre* actuel;
    struct file* suivant;
} file;
typedef struct file2 {
    donnees a;
    struct file** actuel;
    struct file* suivant;
} file2;

#endif //TYPE_AVL