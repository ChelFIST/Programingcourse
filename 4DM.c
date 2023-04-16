#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 100

int main() {
    int A[MAX_SIZE], B[MAX_SIZE];
    int m, n, i, j, k;
    bool found;
    int C[2 * MAX_SIZE];

    printf("Enter the number of elements in array A: ");
    scanf("%d", &m);

    printf("Enter the elements of array A: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter the number of elements in array B: ");
    scanf("%d", &n);

    printf("Enter the elements of array B: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    for (i = 0, k = 0; i < m; i++) {
        found = false;
        for (j = 0; j < n; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            C[k++] = A[i];
        }
    }

    for (i = 0; i < n; i++) {
        found = false;
        for (j = 0; j < m; j++) {
            if (B[i] == A[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            C[k++] = B[i];
        }
    }

    printf("The resulting array C: ");
    for (i = 0; i < k; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");

    return 0;
}