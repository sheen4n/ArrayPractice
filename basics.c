#include <stdio.h>
#include <stdlib.h>

int main() {

    // In Stack
    int A[5] = {1, 2, 3, 4, 999};
    printf("%d\n", A[4]);

    // In Heap
    int *P;
    P = (int *) malloc(5 * sizeof(int));

    P[1] = 2;
    printf("%d\n", P[1]);
    free(P);
    return 0;
}
