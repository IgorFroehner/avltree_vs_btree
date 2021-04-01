#include <stdlib.h>
#include <stdio.h>

#include "btree.h"

int main() {

    btree* t = btree_create(25);

    int n, x;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", &x);
        btree_insert(t, x);
    }

    FILE *f = fopen("../outs_piorcaso/out_btree", "a");

    fprintf(f, "%d\n", btree_iterations(t));

    fclose(f);

    // btree_delete(t);
    
}