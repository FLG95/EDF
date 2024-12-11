#include "include/create_avl.h"
#include "include/fonction_utile.h"

//Create node for a tree
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

//Make a simple left rotation for the stability of the tree
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

//Make a simple right rotation for the stability of the tree
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

//Make a double left rotation for the stability of the tree
tree* doubleLeftRotation(tree* head) {
    if (head == NULL || head->fd == NULL){
        return NULL;
    }
    head->fd = RightRotation(head->fd);
    return leftRotation(head);
}

//Make a double right rotation for the stability of the tree
tree* doubleRightRotation(tree* head) {
    if (head == NULL || head->fg == NULL){
        return NULL;
    }
    head->fg = leftRotation(head->fg);
    return RightRotation(head);
}

//Balance the tree for the stability of the avl
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

//Insert Data in a tree
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

//Add data to a tree
void addTree(tree** stationTree, Data b, int* hStation, char* station, Data* tmp, int* i){
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

//Sort a tree by absolute value between production and consumption
tree* sortByAbs(tree* head, Data tmp, int* h) {
    if (head == NULL) {
        *h = 1;
        return create(tmp);
    } else if (absoluteValue(head->a.production, head->a.consumption) > absoluteValue(tmp.production, tmp.consumption)) {
        head->fg = sortByAbs(head->fg, tmp, h);
        *h = -*h;
    } else if (absoluteValue(head->a.production, head->a.consumption) < absoluteValue(tmp.production, tmp.consumption)) {
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
        if (head == NULL){
            exit(1);
        }
        if (head->balance == 0) {
            *h = 0;
        } else {
            *h = 1;
        }
    }
    return head;
}

//Sort a tree by production
tree* sortByProduction(tree* head, Data tmp, int* h) {
    if (head == NULL) {
        *h = 1;
        return create(tmp);
    }
    if (head->a.consumption > tmp.consumption) {
        head->fg = sortByProduction(head->fg, tmp, h);
        *h = -*h;
    } else if (head->a.consumption < tmp.consumption) {
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
        if (head == NULL){
            exit(1);
        }
        if (head->balance == 0) {
            *h = 0;
        } else {
            *h = 1;
        }
    }
    return head;
}