#include <stdlib.h>
#include <stdio.h>
#include "avltree.h"

void print(int a, int b) {
    printf("%i:%i\n", a, b);
}

int main() {

    avltree *t = avltree_create();

    int n, x;
    scanf("%i", &n);

    for (int i=0; i<n; i++){
        scanf("%i", &x);
        avltree_insert(t, x, x);
    }

    // FILE *f = fopen("./outs_piorcaso/out_avltree", "a");
    // fprintf(f, "%d\n", avltree_iterations(t));
    // fclose(f);

    FILE *f_rand = fopen("./outs_piorcaso/out_avltree_rand", "a");
    fprintf(f_rand, "%d\n", avltree_iterations(t));
    fclose(f_rand);
    // printf();

    // avltree_delete(t);

}