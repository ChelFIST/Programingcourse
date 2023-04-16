#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

bool contains(int *array, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            return true;
        }
    }
    return false;
}

void array_difference(int *A, int sizeA, int *B, int sizeB, int *C, int *sizeC) {
    int i, j;
    *sizeC = 0;
    for (i = 0; i < sizeA; i++) {
        if (!contains(B, sizeB, A[i])) {
            C[(*sizeC)++] = A[i];
        }
    }
}

int main() {
    int A[MAX_SIZE], B[MAX_SIZE], C[MAX_SIZE];
    int sizeA, sizeB, sizeC;

    // Input arrays A and B
    printf("Enter the size of array A: ");
    scanf("%d", &sizeA);
    printf("Enter elements of array A: ");
    for (int i = 0; i < sizeA; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter the size of array B: ");
    scanf("%d", &sizeB);
    printf("Enter elements of array B: ");
    for (int i = 0; i < sizeB; i++) {
        scanf("%d", &B[i]);
    }

    // Calculate difference between arrays
    array_difference(A, sizeA, B, sizeB, C, &sizeC);

    // Output resulting array C
    printf("Elements present in A but not in B are: ");
    for (int i = 0; i < sizeC; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");

    return 0;
}