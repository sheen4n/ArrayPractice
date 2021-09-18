#include <stdio.h>
#include <stdlib.h>

int main() {
    // In Heap, can make dynamic array
    int *P;
    P = (int *) malloc(5 * sizeof(int));
    P[0] = 3;
    P[1] = 9;
    P[2] = 10;
    P[3] = 20;
    P[4] = 25;

    int *Q;
    Q = (int *) malloc(10 * sizeof(int));

    // Copy P to Q
    for (int i = 0; i < 5; i++) {
        Q[i] = P[i];
    }

    // Free up memory of P
    free(P);

    P = Q;

    // POINT Q to null
    Q = NULL;

    for (int i = 0; i < 10; i++) {
        printf("%d \n", P[i]);
    }

    return 0;
}
