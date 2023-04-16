#include "matrix.h"

int getNSpecialElement(int *const a, int n) {
    int current = 0;
    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (a[i] < a[j]) {
                current = 0;
                break;
            } else {
                current = 1;
                if (j == i) {
                    for (int k = i + 1; k < n; k++) {
                        if (a[i] > a[k]) {
                            current = 0;
                            break;
                        } else {
                            current = 1;
                        }
                    }
                }
            }
        }
        total += current;
    }
    return total;
}

int getNSpecialElement2(Matrix m) {
    int total2 = 0;
    for (int i = 0; i < m.nRows; i++) {
        total2 += getNSpecialElement(m.values[i], m.nCols);
    }
    return total2;
}

void testgetNSpecialElement2() {
    Matrix m1 = createMatrixFromArray(
            (int[]) {6, 2, 3, 8, 7, 12, 15,
                     1, 2, 3, 2, 5, 4, 8,
                     3, 5, 1, 2, 12, 9, 10}, 3, 7);
    assert(getNSpecialElement2(m1) == 5);
}

int main() {
    testgetNSpecialElement2();

    return 0;
}
