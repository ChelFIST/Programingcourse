#include "matrix.h"

int getMax(const int *const a, int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

void sortRowsByMinElement(Matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);

    outputMatrix(m);

    freeMemMatrix(m);
}


int main() {
    Matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 3,
                    1, -10, 2,
                    88, 1, 6
            },
            5, 3
    );
    sortRowsByMinElement(m1);
}