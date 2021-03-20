#include <stdlib.h>
#include <stdio.h>

#include "btree.h"

int main() {

    btree *t = btree_create(3);

    btree_delete(t);
    
}