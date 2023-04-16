#include "matrix.h"

bool isNonDescendingSorted(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}

bool hasAllNonDescendingRows(Matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        if (isNonDescendingSorted(m.values[i], m.nCols) != true)
            return false;
    }
    return true;
}

int countNonDescendingRowsMatrices(Matrix *ms, int n) {
    int counter = 0;
    for (int j = 0; j < n; j++) {
        if (hasAllNonDescendingRows(ms[j]) == true) {
            counter++;
        }
    }
    return counter;
}

void testCountNonDescendingRowsMatrices() {
    Matrix *ms1 = createArrayOfMatrixFromArray((int[]) {7, 1, 1, 1,
                                                        1, 6, 2, 2,
                                                        5, 4, 2, 3,
                                                        1, 3, 7, 9}, 4, 2, 2);
    assert(countNonDescendingRowsMatrices(ms1, 4) == 2);
}


int main() {
    testCountNonDescendingRowsMatrices();

    return 0;
}

