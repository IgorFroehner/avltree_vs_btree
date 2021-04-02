#include <stdlib.h>
#include <stdio.h>

#include "btree.h"

int main() {

    btree* t = btree_create(100);

    int n, x;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", &x);
        btree_insert(t, x);
    }

    printf("%d\n", btree_iterations(t));

    // FILE *f = fopen("./outs_piorcaso/out_btree", "a");
    // fprintf(f, "%d\n", btree_iterations(t));
    // fclose(f);

    FILE *f_rand = fopen("./outs_piorcaso/out_btree_rand", "a");
    fprintf(f_rand, "%d\n", btree_iterations(t));
    fclose(f_rand);

    // btree_delete(t);
    
}