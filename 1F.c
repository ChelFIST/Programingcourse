#include <stdio.h>

int arrC(int *ar1, int *ar2, size_t sizeAr1, size_t sizeAr2){

    int ar3[sizeAr1 + sizeAr2];

    int i1 = 0, i2 = 0, i3 = 0;
    while(i3 < sizeAr1 + sizeAr2 && i1 < sizeAr1 || i2 < sizeAr2)
    {
    ar3[i3++] = ar1[i1] < ar2[i2] || i2 >= sizeAr2 ? ar1[i1++] : ar2[i2++];

    while(ar3[i3 - 1] == ar1[i1] || ar3[i3 - 1] == ar2[i2])
    ar3[i3 - 1] == ar1[i1] ? i1++ : i2++;
    }
    for(int i = 0; i < i3; i++)
        printf("%d ", ar3[i]);
}

int main() {
    int ar1[]  = {1, 2, 5, 6, 8, 11, 11, 11, 11, 11, 12, 14, 15};
    int ar2[]  = {1, 1, 2, 3, 4, 7, 11, 11, 11, 11, 20};

    size_t sizeAr1  = sizeof(ar1) / sizeof(int);
    size_t sizeAr2  = sizeof(ar2) / sizeof(int);

    int i = 0;

    puts("first array:");
    for(i = 0; i < sizeAr1; i++)
        printf("%d ", ar1[i]);

    puts("\n\nsecond array:");
    for(i = 0; i < sizeAr2; i++)
        printf("%d ", ar2[i]);
    puts("\n\nmerged array:");
    arrC(ar1,ar2, sizeAr1, sizeAr2);

    return 0;
}