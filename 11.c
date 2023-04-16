#include <stdio.h>
#include <stdlib.h>

int contains(int *arr, int len, int num) {
    int i;
    for (i = 0; i < len; i++) {
        if (arr[i] == num) return 1;
    }
    return 0;
}

void merge_arrays(int *A, int lenA, int *B, int lenB, int *C, int *lenC) {
    int i, j, k = 0;
    for (i = 0; i < lenA; i++) {
        if (!contains(B, lenB, A[i])) {
            C[k++] = A[i];
        }
    }
    for (j = 0; j < lenB; j++) {
        if (!contains(A, lenA, B[j])) {
            C[k++] = B[j];
        }
    }
    *lenC = k;
}

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int A[] = {1, 2, 3, 5};
    int lenA = sizeof(A) / sizeof(A[0]);
    int B[] = {3, 4, 8, 9};
    int lenB = sizeof(B) / sizeof(B[0]);
    int C[100];
    int lenC;

    merge_arrays(A, lenA, B, lenB, C, &lenC);
    qsort(C, lenC, sizeof(int), cmp);

    int i;
    for (i = 0; i < lenC; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");
    return 0;
}
