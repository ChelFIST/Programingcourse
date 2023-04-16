#include <stdbool.h>
#include "stdio.h"

bool noCommonElements(int *a, size_t sizeA, int *b, size_t sizeB) {
    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < sizeB; j++) {
            if (a[i] == b[j]) {
                return false;
            }
        }
    }
    return true;
}

int main(){
    int ar1[]  = {11, 2, 3, 4, 8};
    int ar2[]  = {1 , 5, 21, 6, 14, 9};

    size_t sizeAr1  = sizeof(ar1) / sizeof(int);
    size_t sizeAr2  = sizeof(ar2) / sizeof(int);

    printf("%d", noCommonElements(ar1,sizeAr1, ar2, sizeAr2));
}