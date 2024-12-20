#include "include/create_avl.h"

/**
 * @param a
 * This function create a node for a tree
 */
tree* create(Data a) {
    tree* new = malloc(sizeof(tree));
    if (new == NULL) {
        exit(40);
    }
    new->a = a;
    new->fd = NULL;
    new->fg = NULL;
    new->balance = 0;
    return new;
}

/**
 * @param head
 * This function make a simple left rotation for the stability of the tree
 */
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

/**
 * @param head
 * This function make a simple right rotation for the stability of the tree
 */
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

/**
 * @param head
 * This function make a double left rotation for the stability of the tree
 */
tree* doubleLeftRotation(tree* head) {
    if (head == NULL || head->fd == NULL){
        return head;
    }
    head->fd = RightRotation(head->fd);
    return leftRotation(head);
}

/**
 * @param head
 * This function make a double right rotation for the stability of the tree
 */
tree* doubleRightRotation(tree* head) {
    if (head == NULL || head->fg == NULL){
        return NULL;
    }
    head->fg = leftRotation(head->fg);
    return RightRotation(head);
}

/**
 * @param head
 * This function balance the tree for the stability of the avl
 */
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

/**
 * @param head
 * @param a
 * @param h
 * This function insert station in the stationTree (AVL)
 */
tree* insertStation(tree* head, Data a, int* h) {
    if (h == NULL){
        exit(40);
    }
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

/**
 * @param head
 * @param a
 * @param h
 * This function insert consumers in the consoTree (AVL)
 */
tree* insertConso(tree* head, Data a, int* h) {
    if (h == NULL){
        exit(40);
    }
    if (head == NULL) {
        *h = 1;
        return create(a);
    }
    if (a.id < head->a.production) {
        head->fg = insertConso(head->fg, a, h);
        *h = -*h;
    } else if (head->a.production < a.id) {
        head->fd = insertConso(head->fd, a, h);
    } else {
        if (a.id < head->a.consumption) {
            head->fg = insertConso(head->fg, a, h);
            *h = -*h;
        } else if (head->a.consumption < a.id) {
            head->fd = insertConso(head->fd, a, h);
        } else {
            *h = 0;
            return head;
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

/**
 * @param stationTree
 * @param b
 * @param hStation
 * @param station
 * @param i
 * This function insert consumers and station in their tree
 */
void addTree(tree** stationTree, tree** consoTree, Data b, int* hStation, int* hConso, char* stationType, int* i){
    if (hStation == NULL || stationType == NULL){
        exit(40);
    }
    //if stationType is equal to lv, we put station in the stationTree, and we put the consumers in the consoTree
    if (strcmp(stationType, "lv") == 0) {
        if (isLv(b)) {
            b.id = b.lv;
            *stationTree = insertStation(*stationTree, b, hStation);
        } else {
            b.id = b.lv;
            *consoTree = insertConso(*consoTree, b, hConso);
        }
    }
    //if stationType is equal to hvb, we put station in the stationTree, and we put the consumers in the consoTree
    if (strcmp(stationType, "hvb") == 0){
        if (isHvb(b) == 1){
            b.id = b.hv_b;
            *stationTree = insertStation(*stationTree, b, hStation);
        } else {
            b.id = b.hv_b;
            *consoTree = insertConso(*consoTree, b, hConso);
        }
    }
    //if stationType is equal to hva, we put station in the stationTree, and we put the consumers in the consoTree
    if (strcmp(stationType, "hva") == 0){
        if (isHva(b) == 1){
            b.id = b.hv_a;
            *stationTree = insertStation(*stationTree, b, hStation);
        } else {
            b.id = b.hv_a;
            *consoTree = insertConso(*consoTree, b, hConso);
        }
    }
}

/**
 * @param head
 * @param tmp
 * @param h
 * This function sort the data by consumption in an AVL
 */
tree* sortByConsumption(tree* head, Data tmp, int* h) {
    if (h == NULL){
        exit(40);
    }
    if (head == NULL) {
        *h = 1;
        return create(tmp);
    } else if (head->a.consumption > tmp.consumption){
        head->fg = sortByConsumption(head->fg, tmp, h);
        *h = -*h;
    } else if (head->a.consumption < tmp.consumption){
        head->fd = sortByConsumption(head->fd, tmp, h);
    } else {
        if (head->a.id > tmp.id){
            head->fg = sortByConsumption(head->fg, tmp, h);
            *h = -*h;
        } else if (head->a.id < tmp.id){
            head->fd = sortByConsumption(head->fd, tmp, h);
        } else {
            *h = 0;
        }
    }
    if (*h != 0) {
        head->balance += *h;
        head = balancing(head);
        if (head == NULL){
            exit(40);
        }
        if (head->balance == 0) {
            *h = 0;
        } else {
            *h = 1;
        }
    }
    return head;
}

/**
 * @param head
 * @param tmp
 * @param h
 * This function sort the data by production in an AVL
 */
tree* sortByProduction(tree* head, Data tmp, int* h) {
    if (h == NULL){
        exit(40);
    }
    if (head == NULL) {
        *h = 1;
        return create(tmp);
    }
    if (head->a.production > tmp.production) {
        head->fg = sortByProduction(head->fg, tmp, h);
        *h = -*h;
    } else if (head->a.production < tmp.production) {
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
            exit(40);
        }
        if (head->balance == 0) {
            *h = 0;
        } else {
            *h = 1;
        }
    }
    return head;
}