#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdbool.h>

typedef struct avltree avltree;

avltree *avltree_create(void);
void avltree_delete(avltree *);

void avltree_insert(avltree *t, int k, int v);
void avltree_remove(avltree *t, int k);

int avltree_height(avltree *);
int avltree_size(avltree *);
int avltree_iterations(avltree *);

void avltree_print(avltree *);


#endif