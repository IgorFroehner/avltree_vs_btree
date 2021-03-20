#ifndef BTREE_H
#define BTREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct btree btree;

btree *btree_create(int);
void btree_delete(btree *);

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

#endif 
