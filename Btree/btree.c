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

static int binarySearch(node *n, int key) {
    int start = 0, end = n->size-1, mid;
    while (start <= end) {
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
        int i = binarySearch(n, key);

        if (n->children[i]==NULL) return n;
        n = n->children[i];
    }

    return NULL;
}

static void addKeyNode(node *n, node *new, int key) {
    int i = binarySearch(n, key);

    for (int j=n->size-1; i>=i; j--){
        n->keys[j+1] = n->keys[j];
        n->keys[j+2] = n->keys[j+1];
    }

    n->keys[i] = key;
    n->children[i+1] = new;
    n->size++;
}

static int overflow (btree *t, node *n) {
    return n->size > t->order*2;
}

static node *splitNode(btree *t, node* n){
    int mid = n->size/2;
    node *new = node_create(t);
    new->father = n->father;

    for (int i=mid+1; i<n->size; i++) {
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

void btree_insert(btree *, int );
void btree_remove(btree *t, int k);

int btree_height(btree *);
int btree_size(btree *);

void btree_print(btree *);

bool btree_has(btree *, int );
int btree_get(btree *, int );

void btree_largura(btree *, void (*f)(int, int));

void btree_inorder(btree *, void (*f)(int, int));
void btree_postorder(btree *, void (*f)(int, int));
void btree_preorder(btree *, void (*f)(int, int));
