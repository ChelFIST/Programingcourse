#include "stdio.h"

void arrC(int *a, int *b, size_t ar1, size_t ar2){
    int c[ar1+ar2];
    int k = 0;
    for (int i = 0; i < ar1; i++){
        for (int j = 0; j < ar2; j++){
            if (a[i] == b[j]) {
                c[k] = a[i];
                printf("%d\n", c[k]);
                break;
            }
        }
    }
}

int main(){
    int ar1[]  = {1, 2, 3, 4,110};
    int ar2[]  = { 4, 110, 800, 7, 11};

    size_t sizeAr1  = sizeof(ar1) / sizeof(int);
    size_t sizeAr2  = sizeof(ar2) / sizeof(int);

    arrC(ar1, ar2, sizeAr1, sizeAr2);
}
