#include <stdlib.h>
#include <stdio.h>
#include "avltree.h"

void print(int a, int b) {
    printf("%i:%i\n", a, b);
}

int main() {

    avltree *t = avltree_create();

    int n, x, type;
    scanf("%i", &type); // seleciona o tipo de input, 1 para ordenado e 2 para randômico
    scanf("%i", &n);

    for (int i=0; i<n; i++){
        scanf("%i", &x);
        avltree_insert(t, x, x);
    }

    // avltree_print(t);

    if(type == 1) { // salvar o output para números ordenados
        FILE *f = fopen("./outs_piorcaso/out_avltree", "a");
        fprintf(f, "%d\n", avltree_iterations(t));
        fclose(f);
    }

    else if (type == 2) { // salvar o output para números randômicos
        FILE *f_rand = fopen("./outs_piorcaso/out_avltree_rand", "a");
        fprintf(f_rand, "%d\n", avltree_iterations(t));
        fclose(f_rand);
    }

    avltree_delete(t);

}