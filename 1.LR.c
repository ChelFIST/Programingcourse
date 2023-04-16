#include "matrix.h"

int getNSpecialElement(int *const a, int n) {
    int current = 0;
    int total = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0, k = i + 1; j < i, k < n; j++, k++){
            if(a[i] < a[j] || a[i] > a[k]){
                current = 0;
                break;
            } else {
                current = 1;
            }
            total += current;
        }

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

int main() {
    int a[7] = {2, 3, 5, 5, 4};
    Matrix m1 = createMatrixFromArray(
            (int[]) {2, 3, 5, 5, 4,
                     6, 2, 3, 8, 12,
                     12, 12, 2, 1, 2}, 3, 5);
    printf("%d\n", getNSpecialElement(a, 5));

    printf("%d", getNSpecialElement2(m1));
}
