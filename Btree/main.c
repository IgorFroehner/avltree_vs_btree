#include <stdlib.h>
#include <stdio.h>

#include "btree.h"

int main() {

    btree* t = btree_create(1);

    int n, x;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", &x);
        btree_insert(t, x);
    }

    // btree_print(t);
    printf("%d\n", btree_iterations(t));
    
}