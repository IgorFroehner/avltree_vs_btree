#include "btree.h"

typedef struct node {
    int size;
    int *keys;
    struct node** children;
    struct node* father; 
} node;

struct btree {
    node *root;
    int order;
    int cont;
};

static node *node_create(btree *t){
    int max = t->order*2;
    node *n = malloc(sizeof(node));

    n->father = NULL;
    n->keys = malloc(sizeof(int) * (max+1));
    n->children = malloc(sizeof(node)*(max+2));
    n->size = 0;

    for (int i=0; i<max+2; i++) n->children[i] = NULL;

    return n;
}

btree *btree_create(int order) {
    btree *res = malloc(sizeof(btree));
    res->order = order;
    res->cont = 0;
    res->root = node_create(res);
    return res;
}

static void node_delete(node *n, int order){
    if (n){
        int max = order*2;
        for (int i=0; i<max+2; i++) {
            node_delete(n->children[i], order);
            free(n->children[i]);
        }

        free(n->children);
        free(n->keys);
        if (n->father) free(n->father);
    }
}

void btree_delete(btree *t) {
    node_delete(t->root, t->order);
}

static int binary_search(node *n, int key, btree *t) {
    int start = 0, end = n->size-1, mid;
    while (start <= end) {
        
        t->cont++;

        mid = (start+end)/2;
        if (n->keys[mid]==key) return mid;
        if (n->keys[mid]>key) end = mid-1;
        else start = mid+1;
    }
    return start;
}

static node *findNode(btree *t, int key) {
    node *n = t->root;

    while (n) {

        t->cont++;

        int i = binary_search(n, key, t);

        if (n->children[i]==NULL) return n;
        n = n->children[i];
    }

    return NULL;
}

static void addKeyNode(node *n, node *new, int key, btree *t) {
    int i = binary_search(n, key, t);

    for (int j=n->size-1; j>=i; j--){

        t->cont++;

        n->keys[j+1] = n->keys[j];
        n->keys[j+2] = n->keys[j+1];
    }

    n->keys[i] = key;
    n->children[i+1] = new;
    n->size++;
}

static int overflow(btree *t, node *n) {
    return n->size > t->order*2;
}

static node *splitNode(btree *t, node* n){
    int mid = n->size/2;
    node *new = node_create(t);
    new->father = n->father;

    for (int i=mid+1; i<n->size; i++) {
        
        t->cont++;

        new->children[new->size] = n->children[i];
        new->keys[new->size] = n->keys[i];
        if (n->children[n->size] != NULL) new->children[new->size]->father = new;
        new->size++;
    }

    new->children[new->size] = n->children[n->size];
    if (new->children[n->size] != NULL) new->children[new->size]->father = new;
    n->size = mid;
    return new;
}

static void addKeyRecursive(btree *t, node *n, node *new, int key){
    addKeyNode(n, new, key, t);
    t->cont++;

    if (overflow(t, n)) {
        int promoted = n->keys[t->order];
        node *new = splitNode(t, n);

        if (n->father == NULL) {
            
            t->cont++;

            node *father = node_create(t);
            father->children[0] = n;
            addKeyNode(father, new, promoted, t);

            n->father = father;
            new->father = father;
            t->root = father;
        }else
            addKeyRecursive(t, n->father, new, promoted);
    }
}

int btree_iterations(btree *t){
    return t->cont;
}

void btree_insert(btree *t, int k){
    node *n = findNode(t, k);

    addKeyRecursive(t, n, NULL, k);
}

static void node_print(node *n){
    if (n) {
        for (int i = 0; i<n->size; i++) {
            node_print(n->children[i]);
            printf("%d ", n->keys[i]);
        }
        node_print(n->children[n->size]);
    }
}

void btree_print(btree *t){
    node_print(t->root);
}


// do professor deu 61