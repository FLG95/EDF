#include "include/create_avl.h"
#include "include/fonction_utile.h"

//fonction pour créer un noeud dans l'tree
tree* create(Data a) {
    tree* new = malloc(sizeof(tree));
    if (new == NULL) {
        exit(1);
    }
    new->a = a;
    new->fd = NULL;
    new->fg = NULL;
    new->balance = 0;
    return new;
}

//fonction pour faire une double rotation gauche dans l'tree
tree* leftRotation(tree* head) {
    if (head == NULL || head->fd == NULL) {
        return head;
    }
    tree* pivot = head->fd;
    head->fd = pivot->fg;
    pivot->fg = head;

    // Mise à jour des factors d'équilibre
    head->balance = head->balance - 1 - max(0, pivot->balance);
    pivot->balance = pivot->balance - 1 + min(0, head->balance);

    return pivot;
}

tree* RightRotation(tree* head) {
    if (head == NULL || head->fg == NULL) {
        return head;
    }
    tree* pivot = head->fg;
    head->fg = pivot->fd;
    pivot->fd = head;

    // Mise à jour des factors d'équilibre
    head->balance = head->balance + 1 - min(0, pivot->balance);
    pivot->balance = pivot->balance + 1 + max(0, head->balance);

    return pivot;
}

//fonction pour faire une double rotation gauche dans l'tree
tree* doubleLeftRotation(tree* head) {
    if (head == NULL || head->fd == NULL){
        return NULL;
    }
    head->fd = RightRotation(head->fd);
    return leftRotation(head);
}
//fonction pour faire une double rotation droite dans l'tree
tree* doubleRightRotation(tree* head) {
    if (head == NULL || head->fg == NULL){
        return NULL;
    }
    head->fg = leftRotation(head->fg);
    return RightRotation(head);
}

//fonction pour équilibrer l'tree
tree* balancing(tree* head) {

    if (head->balance >= 2) {
        if (head->fd != NULL && head->fd->balance >= 0) {
            return leftRotation(head);
        } else {
            return doubleLeftRotation(head);
        }
    } else if (head->balance <= -2) {
        if (head->fg != NULL && head->fg->balance <= 0) {
            return RightRotation(head);
        } else {
            return doubleRightRotation(head);
        }
    }
    return head;
}

//fonction pour insérer un élément dans l'tree
tree* insertStation(tree* head, Data a, int* h) {
    if (head == NULL) {
        *h = 1;
        return create(a);
    }
    if (a.id < head->a.id) {
        head->fg = insertStation(head->fg, a, h);
        *h = -*h;
    } else if (head->a.id < a.id) {
        head->fd = insertStation(head->fd, a, h);
    } else {
        *h = 0;
        return head;
    }
    if (*h != 0) {
        head->balance += *h;
        head = balancing(head);
        if (head->balance == 0) {
            *h = 0;
        } else {
            *h = 1;
        }
    }
    return head;
}


//fonction pour calculer la hauter de l'tree
int height(tree* head) {
    if (head == NULL){
        return 0;
    }
    return 1 + max(height(head->fg), height(head->fd));
}
//fonction pour déterminer si l'tree est bien un AVL
bool isAVL(tree* head) {
    if (head == NULL){
        return true;
    }

    int heightG = height(head->fg);
    int heightD = height(head->fd);

    int factor = heightG - heightD;
    if (factor < -1 || factor > 1){
        return false;
    }
    return isAVL(head->fg) && isAVL(head->fd);
}

void addTree(tree** stationTree, tree** consoTree, Data b, int* hStation, int* hConso, char* station, Data* tmp, int* i){
    if (station == NULL){
        exit(1);
    }
    if (strcmp(station, "lv") == 0) {
        if (isLv(b)) {
            b.id = b.lv;
            *tmp = b;
            *stationTree = insertStation(*stationTree, b, hStation);
        } else {
            b.id = b.lv;
            if (tmp->id == b.id) {
                parcoursRefresh(stationTree, b);
            }
        }
    }
    if (strcmp(station, "hvb") == 0){
        if (isHvb(b) == 1){
            b.id = b.hv_b;
            *tmp = b;
            *stationTree = insertStation(*stationTree, b, hStation);
        } else {
            b.id = b.hv_b;
            if (tmp->id == b.id){
                parcoursRefresh(stationTree, b);
            }
        }
    }
    if (strcmp(station, "hva") == 0){
        if (isHva(b) == 1){
            b.id = b.hv_a;
            *tmp = b;
            *stationTree = insertStation(*stationTree, b, hStation);
        } else {
            b.id = b.hv_a;
            if (tmp->id == b.id){
                parcoursRefresh(stationTree, b);
            }
        }
    }
}
tree* sortByAbs(tree* head, Data tmp, int* h) {
    if (head == NULL) {
        *h = 1;
        return create(tmp);
    } else if (absoluteValue(head->a.production, head->a.consommation) > absoluteValue(tmp.production, tmp.consommation)) {
        head->fg = sortByAbs(head->fg, tmp, h);
        *h = -*h;
    } else if (absoluteValue(head->a.production, head->a.consommation) < absoluteValue(tmp.production, tmp.consommation)) {
        head->fd = sortByAbs(head->fd, tmp, h);
    } else {
        if (head->a.id > tmp.id){
            head->fg = sortByAbs(head->fg, tmp, h);
            *h = -*h;
        } else if (head->a.id < tmp.id){
            head->fd = sortByAbs(head->fd, tmp, h);
        } else {
            *h = 0;
        }
    }
    if (*h != 0) {
        head->balance += *h;
        head = balancing(head);
        if (head->balance == 0) {
            *h = 0;
        } else {
            *h = 1;
        }
    }
    return head;
}
tree* sortByProduction(tree* head, Data tmp, int* h) {
    if (head == NULL) {
        *h = 1;
        return create(tmp);
    }
    if (head->a.consommation > tmp.consommation) {
        head->fg = sortByProduction(head->fg, tmp, h);
        *h = -*h;
    } else if (head->a.consommation < tmp.consommation) {
        head->fd = sortByProduction(head->fd, tmp, h);
    } else {
        if (head->a.id > tmp.id){
            head->fg = sortByProduction(head->fg, tmp, h);
            *h = -*h;
        } else if (head->a.id < tmp.id){
            head->fd = sortByProduction(head->fd, tmp, h);
        } else {
            *h = 0;
        }
    }
    if (*h != 0) {
        head->balance += *h;
        head = balancing(head);
        if (head->balance == 0) {
            *h = 0;
        } else {
            *h = 1;
        }
    }
    return head;
}