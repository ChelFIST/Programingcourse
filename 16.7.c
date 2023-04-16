#include "matrix.h"

int max2(int a, int b) {
    return a > b ? a : b;
}

long long findSumOfMaxesOfPseudoDiagonal(Matrix m) {
    int sum = 0;
    int i = m.nRows - 1;
    int j = 0;
    for (int k = 1; k < m.nCols + m.nRows; k++) {
        int max = m.values[i][j];
        int c = i;
        int d = j;
        while (c < m.nRows - 1 && d < m.nCols - 1 && c != d) {
            max = max2(max, m.values[++c][++d]);
        }
        sum += max;

        if (i != 0) {
            i--;
        } else {
            j++;
        }

    }

    return sum - m.values[0][0];
}

void testFindSumOfMaxesOfPseudoDiagonal() {
    Matrix a = createMatrixFromArray((int[]) {3, 2, 5, 4,
                                              1, 3, 6, 3,
                                              3, 2, 1, 2}, 3, 4);

    assert(findSumOfMaxesOfPseudoDiagonal(a) == 20);

    Matrix b = createMatrixFromArray((int[]) {7, 10, 4,
                                              8, 3, 5,
                                              6, 7, 7,
                                              9, 2, 1}, 4, 3);

    assert(findSumOfMaxesOfPseudoDiagonal(b) == 37);

    Matrix c = createMatrixFromArray((int[]) {7, 10, 4,
                                              -8, 3, 5,
                                              6, 7, 7}, 3, 3);

    assert(findSumOfMaxesOfPseudoDiagonal(c) == 27);
}

int main() {
    testFindSumOfMaxesOfPseudoDiagonal();

    return 0;
}