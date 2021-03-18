#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdbool.h>

typedef struct avltree avltree;

avltree *avltree_create(void);
void avltree_delete(avltree *);

void avltree_insert(avltree *, int , int);
void avltree_remove(avltree *t, int k);

int avltree_height(avltree *);
int avltree_size(avltree *);

void avltree_print(avltree *);

bool avltree_has(avltree *, int );
int avltree_get(avltree *, int );

void avltree_largura(avltree *, void (*f)(int, int));

void avltree_inorder(avltree *, void (*f)(int, int));
void avltree_postorder(avltree *, void (*f)(int, int));
void avltree_preorder(avltree *, void (*f)(int, int));

#endif