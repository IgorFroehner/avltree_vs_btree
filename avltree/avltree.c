#include "avltree.h"
#include <stdlib.h>
#include <stdio.h>

#define max(X, Y)  ((X) > (Y) ? (X) : (Y))
#define min(X, Y)  ((X) < (Y) ? (X) : (Y))

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
    int value;
    int height;
} node;

struct avltree {
    node *root;
    int cont;
};

// ------------create-----------------

avltree *avltree_create(void){
    avltree *t = malloc(sizeof(avltree));
    t->root = NULL;
    t->cont = 0;
    return t;
}

// ----------delete------------------

static void node_delete(node *n){
    if (n->left!=NULL) node_delete(n->left);
    if (n->right!=NULL) node_delete(n->right);
    free(n);
}

void avltree_delete(avltree *t){
    if (t->root) node_delete(t->root);
    free(t);
}

// ------------- HEIGHT

static int node_height(node *n){
    if (n==NULL) return 0;
    return n->height;
}

static int node_factor(node *n) {
    return node_height(n->left) - node_height(n->right);
}

int avltree_height(avltree *t){
    return node_height(t->root);
}

// -------------- INSERT ---------------

static node *left_rotate(node *n, avltree *t){
    t->cont++;
    node *b = n->right;
    node *y = b->left;

    b->left = n;
    n->right = y;

    n->height = max(node_height(n->left), node_height(n->right))+1;
    b->height = max(node_height(b->left), node_height(b->right))+1;

    return b;
}

static node *right_rotate(node *n, avltree *t) {
    t->cont++;
    node *b = n->left;
    node *y = b->right;

    b->right = n;
    n->left = y;

    n->height = max(node_height(n->left), node_height(n->right))+1;
    b->height = max(node_height(b->left), node_height(b->right))+1;

    return b;
}

static node *node_insert(node *n, int k, int v, avltree *t){
    if (n!=NULL){
        t->cont++;
        // vê se o cara que a gente tá já não é a chave que estamos procurando
        if (n->key==k){
            n->value = v;
            return n;
        }

        // se for menor vamos pra esquerda se não vamos pra direita
        if (k<n->key){
            n->left = node_insert(n->left, k,  v, t);
        } else {
            n->right = node_insert(n->right, k, v, t);
        }

        int factor = node_height(n->left) - node_height(n->right);

        n->height = max(node_height(n->right), node_height(n->left))+1;

        if (factor < -1){
            if (k > n->right->key)
                n = left_rotate(n, t);
            else{
                n->right = right_rotate(n->right, t);
                n = left_rotate(n, t);
            }
        }else
        if (factor > 1){
            if (k > n->right->key){
                n->left = left_rotate(n->left, t);
                n = right_rotate(n, t);
            }else
                n = right_rotate(n, t);
        }

        return n;
    } else{
        // se chegamos em uma parte em que não existe nodo é aqui que ele vai
        t->cont++;

        n = malloc(sizeof(node));
        n->key = k;
        n->left = NULL;
        n->right = NULL;
        n->value = v;
        n->height = 1;
        return n;
    }
}

void avltree_insert(avltree *t, int k, int v){
    t->root = node_insert(t->root, k, v, t);
}

int avltree_iterations(avltree *t){
    return t->cont;
}


// ------------- SIZE ---------

static int node_size(node *n){
    if (n==NULL) return 0;
    return node_size(n->left)+node_size(n->right)+1;
}

int avltree_size(avltree *t){
    if (t->root!=NULL)
        return node_size(t->root);
    return 0;
}


// -------------- PRINT -----------

static void node_print(node *n){
    printf("( ");
    if (n!=NULL){
        if (n->left!=NULL){
            node_print(n->left);
            printf(" ");
        }
        printf("%d:%d ", n->key, n->value);
        if (n->right!=NULL){
            node_print(n->right);
            printf(" ");
        }
    }
    printf(")");
}

void avltree_print(avltree *t){
    node_print(t->root);
    printf("\n");
}

// ------------------ GET -----------------------

static int node_get(node *n, int k) {
    if (n) {
        if (n->key==k) return n->value;
        if (n->key<k) return node_get(n->left, k);
        return node_get(n->right, k);
    }
    return -1;
}

int avltree_get(avltree *t, int k) {
    return node_get(t->root, k);
}

