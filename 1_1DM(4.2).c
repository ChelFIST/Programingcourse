#include <stdio.h>

#define SIZE 10

// вывод элементов множества
void outputSet(const int *const a, const int size) {
    for (int i = 0; i < size; i++)
        if (a[i] != 0)
            printf("%d ", a[i]);
    printf("\n");
}

// объединение двух множеств
int combiningSets(const int *const a, const int sizeA, const int *const b,
                  const int sizeB, int *c, int *sizeC) {
    *sizeC = 0;
    int l = 0;
    int m = 0;
    while (l < sizeA && m < sizeB) {
        if (a[l] < b[m])
            c[(*sizeC)++] = a[l++];
        else if (a[l] > b[m])
            c[(*sizeC)++] = b[m++];
        else {
            c[(*sizeC)++] = a[l++];
            m++;
        }
    }

    while (l < sizeA)
        c[(*sizeC)++] = a[l++];

    while (m < sizeB)
        c[(*sizeC)++] = b[m++];

    return *c;
}

// разность двух множеств
int differenceOfSets(const int *const a, const int sizeA, const int *const b,
                     const int sizeB, int *c, int *sizeC) {
    *sizeC = 0;
    int l = 0;
    int m = 0;
    while (l < sizeA && m < sizeB) {
        if (a[l] == b[m]) {
            l++;
            m++;
        } else if (a[l] < b[m])
            c[(*sizeC)++] = a[l++];
        else
            m++;
    }

    while (l < sizeA)
        c[(*sizeC)++] = a[l++];

    return *c;
}


int main() {
    int a[SIZE] = {2, 3, 4, 5, 6};
    int sizeA = sizeof(a) / sizeof(int);

    int b[SIZE] = {1, 2, 4, 9};
    int sizeB = sizeof(b) / sizeof(int);

    int c[SIZE] = {4, 5, 7, 8};
    int sizeC = sizeof(c) / sizeof(int);

    int sizeD = SIZE;
    int d[sizeD];

    int firstSize = SIZE;
    int first[firstSize];

    combiningSets(b, sizeB, c, sizeC, first, &firstSize);

    differenceOfSets(a, sizeA, first, firstSize, d, &sizeD);

    outputSet(d, sizeD);

    return 0;
}