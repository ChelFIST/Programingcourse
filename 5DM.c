#include <stdbool.h>
#include "stdio.h"

int contains_all_elements(int *a, int size_a, int *b, int size_b) {
    int i, j;
    for (i = 0; i < size_a; i++) {
        bool found = false;
        for (j = 0; j < size_b; j++) {
            if (a[i] == b[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            return -1;
        }
    }
    return 1;
}

int main(){
    int ar1[]  = {11, 2, 3, 6, 8, 1};
    int ar2[]  = {1, 5, 2, 6, 11, 8};

    size_t sizeAr1  = sizeof(ar1) / sizeof(int);
    size_t sizeAr2  = sizeof(ar2) / sizeof(int);

    printf("%d", contains_all_elements(ar1,sizeAr1, ar2, sizeAr2));
}