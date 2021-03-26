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

    // avltree_print(t);
    printf("%d\n", avltree_iterations(t));

    avltree_delete(t);

}