#include "matrix.h"

int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

void sortColsByMinElement(Matrix m) {
    selectionSortColsMatrixByColCriteria(m, getMin);

    outputMatrix(m);

    freeMemMatrix(m);
}

int main() {
    Matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 2, 4, 3, 3,
                    2, 5, 1, 8, 2, 7,
                    6, 1, 4, 4, 8, 3,
            },
            3, 6
    );
    sortColsByMinElement(m1);

    return 0;
}