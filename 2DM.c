#include "stdio.h"

void arrC(int *a, int *b, size_t n, size_t m){
    int i3 = 0;
    int c[m+n];

    for (int i = 0; i < n; i++) {
        for (int j =0; j < m; j++){
            if (a[i] == b[j]) {
                c[i3] = a[i];
                printf("%d ", c[i3]);
                i3++;
            }
        }
    }
}

int main(){
    int ar1[]  = {1, 2, 5, 6};
    int ar2[]  = { 1, 6, 4, 7, 11};

    size_t sizeAr1  = sizeof(ar1) / sizeof(int);
    size_t sizeAr2  = sizeof(ar2) / sizeof(int);

    arrC(ar1, ar2, sizeAr1, sizeAr2);
}