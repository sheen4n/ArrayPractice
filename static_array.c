#include <stdio.h>
#include <stdlib.h>

int main() {
    // In stack
    int A[5] = {2, 3, 4, 5, 6};

    // In Heap, can make dynamic array
    int *P;
    P = (int *) malloc(5 * sizeof(int));
    P[0] = 3;
    P[1] = 9;
    P[2] = 10;
    P[3] = 20;
    P[4] = 25;

    for (int i = 0; i < 5; i++) {
        printf("%d ", A[i]);
    }

    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", P[i]);
    }


    printf("%d\n", P[1]);
    free(P);
    return 0;
}
