#include "stdio.h"

int getIndexOfMin_(int i, int min, int indexOfMin, int n) {
    if (i == n)
        return indexOfMin;
    else {
        int value;
        scanf("%d", &value);

        if (value < min) {
            indexOfMin = i;
            min = value;
        }
        return getIndexOfMin_(i + 1, min, indexOfMin, n);
    }
}

int getIndexOfMin(int n) {
    int min;
    scanf("%d", &min);

    return getIndexOfMin_(1, min, 0, n);
}

int main() {
    printf("%d", getIndexOfMin(5));

    return 0;
}