#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stdbool.h"
#include <string.h>

#ifndef INC_10DM_C_16_2_H
#define INC_10DM_C_16_2_H


typedef struct Matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} Matrix;
typedef struct Position {
    int rowIndex;
    int colIndex;
} Position;

Matrix getMemMatrix(int nRows,
                    int nCols) {      //размещает в динамической памяти матрицу размером nRows на nCols. Возвращает матрицу.
    int **a = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        a[i] = (int *) malloc(sizeof(int) * nCols);
    return (Matrix) {a, nRows, nCols};
}


//размещает в динамической памяти массив из nMatrices матриц размером nRows на
// nCols. Возвращает указатель на нулевую матрицу.
Matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    Matrix *ms = (Matrix *) malloc(sizeof(Matrix) * nMatrices);
    for (int i = 0; i < nRows; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

//освобождает память, выделенную под хранение
//матрицы m.
void freeMemMatrix(Matrix m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);
    free(m.values);
}

//освобождает память,
//выделенную под хранение массива ms из nMatrices матриц.
void freeMemMatrices(Matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)

        freeMemMatrix(ms[i]);
    free(ms);
}

//ввод матрицы m.
void inputMatrix(Matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            scanf("%d", &m.values[i][j]);
}

//ввод массива из nMatrices
//матриц, хранящейся по адресу ms.
void inputMatrices(Matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(ms[i]);
}

//вывод матрицы m.
void outputMatrix(Matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
}

//вывод массива из nMatrices
//матриц, хранящейся по адресу ms.
void outputMatrices(Matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
}

//обмен строк с порядковыми номерами i1 и
//i2 в матрице m.
void swapForRows(int **a, int **b) {
    int *t = *a;
    *a = *b;
    *b = t;
}

void swapRows(Matrix m, int i1, int i2) {
    assert(0 <= i1 && i1 < m.nRows);
    assert(0 <= i2 && i2 < m.nRows);
    swapForRows(&m.values[i1], &m.values[i2]);
}

//обмен колонок с порядковыми
//номерами j1 и j2 в матрице m.
void swapForCols(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void swapColumns(Matrix m, int j1, int j2) {
    assert(0 <= j1 && j1 < m.nCols);
    assert(0 <= j2 && j2 < m.nCols);
    for (int i = 0; i < m.nRows; i++)
        swapForCols(&m.values[i][j1], &m.values[i][j2]);
}

//выполняет сортировку вставками строк матрицы m по неубыванию значения
//функции criteria применяемой для строк.
int getSum(const int *const a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

void insertionSortRowsMatrixByRowCriteria(Matrix m, int(*criteria)(int *, int)) {
    int *criteriaValues = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; i++)
        criteriaValues[i] = criteria(m.values[i], m.nCols);
    for (int j = 1; j < m.nRows; j++) {
        int t = criteriaValues[j];
        int k = j;
        while (k > 0 && criteriaValues[k - 1] > t) {
            criteriaValues[k] = criteriaValues[k - 1];
            k--;
            swapRows(m, k, k + 1);
        }
        criteriaValues[k] = t;
    }
    free(criteriaValues);
}

void outputArr(int * a, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}

//выполняет сортировку выбором столбцов матрицы m по
//неубыванию значения функции criteria применяемой для столбцов.

void selectionSortColsMatrixByColCriteria(Matrix m, int(*criteria)(int *, int)) {
    int *criteriaValues = (int *) malloc(sizeof(int) * m.nCols);
    int *column = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nCols; i++) {
        for (int j = 0; j < m.nRows; j++)
            column[j] = m.values[j][i];
        criteriaValues[i] = criteria(column, m.nRows);
    }
    for (int j = 0; j < m.nCols - 1; j++) {
        int minPos = j;
        for (int k = j + 1; k < m.nCols; k++)
            if (criteriaValues[k] < criteriaValues[minPos])
                minPos = k;
        if (j != minPos) {
            swapForCols(&criteriaValues[j], &criteriaValues[minPos]);
            swapColumns(m, j, minPos);
        }
    }
    free(column);
    free(criteriaValues);
}
//ntcn
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void selectionSortColsMatrixByColCriteria2(Matrix m,
                                          int (*criteria)(int *, int)) {
    int *criteriaValues = (int *) malloc(sizeof(int) * m.nCols);
    int *column = (int *) malloc(sizeof(int) * m.nRows);
    for (int j = 0; j < m.nCols; j++) {
        for (int i = 0; i < m.nRows; i++) {
            column[i] = m.values[i][j];
        }
        criteriaValues[j] = criteria(column, m.nCols);
    }

    for (int i = 0; i < m.nCols; i++) {
        int minIndex = i;
        for (int j = i + 1; j < m.nCols; j++) {
            if (criteriaValues[j] < criteriaValues[minIndex]) {
                minIndex = j;
            }
        }
        if (i != minIndex) {
            swap(&criteriaValues[i], &criteriaValues[minIndex]);
            swapColumns(m, i, minIndex);
        }
    }

    free(column);
    free(criteriaValues);
}

//возвращает значение ’истина’, если матрица m является
//квадратной, ложь – в противном случае.
bool isSquareMatrix(Matrix m) {
    return m.nRows == m.nCols;
}

//возвращает значение ’истина’,
//если матрицы m1 и m2 равны, ложь – в противном случае.
bool areTwoMatricesEqual(Matrix m1, Matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;
    for (int i = 0; i < m1.nRows; i++)
        if (memcmp(m1.values[i], m2.values[i], sizeof(int) * m1.nRows) != 0)
            return false;
    return true;
}

//возвращает значение ’истина’, если матрица m
//является симметричной, ложь – в противном случае.
bool isSymmetricMatrix(Matrix m) {
    if (m.nRows != m.nCols)
        return false;
    for (int i = 0; i < m.nCols; i++)
        for (int j = 0; j < i; j++)
            if (m.values[i][j] != m.values[j][i])
                return false;
    return true;
}

//транспонирует квадратную матрицу m.
void transposeSquareMatrix(Matrix m) {
    int n = m.nRows;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            swapForCols(&m.values[i][j], &m.values[j][i]);
}

//транспонирует матрицу m.
void transposeMatrix(Matrix *m) {
    Matrix b = getMemMatrix(m->nCols, m->nRows);
    for (int i = 0; i < m->nRows; i++)
        for (int j = 0; j < m->nCols; j++)
            b.values[j][i] = m->values[i][j];
    freeMemMatrix(*m);
    *m = b;
}

//возвращает позицию минимального элемента
//матрицы m.
Position getMinValuePos(Matrix m) {
    int rowMinIndex = 0;
    int colMinIndex = 0;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] < m.values[rowMinIndex][colMinIndex]) {
                rowMinIndex = i;
                colMinIndex = j;
            }
    return (Position) {rowMinIndex, colMinIndex};
}

//возвращает позицию максимального элемента
//матрицы m.
Position getMaxValuePos(Matrix m) {
    int rowMaxIndex = 0;
    int colMaxIndex = 0;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] > m.values[rowMaxIndex][colMaxIndex]) {
                rowMaxIndex = i;
                colMaxIndex = j;
            }
    return (Position) {rowMaxIndex, colMaxIndex};
}

//возвращает
//матрицу размера nRows на nCols, построенную из элементов массива a.
Matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    Matrix m = getMemMatrix(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];
    return m;
}

//возвращает указатель на нулевую матрицу массива из nMatrices
//матриц, размещенных в динамической памяти, построенных из элементов массива a.
Matrix *createArrayOfMatrixFromArray(const int *values,
                                     size_t nMatrices, size_t nRows,
                                     size_t nCols) {
    Matrix *m = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    for (int i = 0; i < nMatrices; i++) {
        m[i] = createMatrixFromArray(values, nRows, nCols);
        values += nRows * nCols;
    }

    return m;
}

#endif //INC_10DM_C_16_2_H
