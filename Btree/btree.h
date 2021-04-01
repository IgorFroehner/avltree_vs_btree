#ifndef BTREE_H
#define BTREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct btree btree;

btree *btree_create(int);
void btree_delete(btree *);

void btree_insert(btree *, int );

int btree_iterations(btree *t);

void btree_print(btree *);


#endif 
