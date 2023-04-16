#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#define l 7
// Проверка на равенство множеств
bool equals(const bool *a, const bool *b) {
    for (int i = 0; i < l; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

//Разность множеств
void denial(const int KU, const bool *a, const bool *b, bool *c) {
    for (int i = 0; i < KU; ++i) {
        if (a[i] == true && a[i] != b[i])
            c[i] = true;
        else
            c[i] = false;
    }
}

//Симметрическая разность
void addition(const int KU, const bool *a, const bool *b, bool *c) {
    for (int i = 0; i < KU; ++i) {
        if (a[i] != b[i])
            c[i] = true;
        else c[i] = false;
    }
}

//Объединение
void unification(const int KU, const bool *a, const bool *b, bool *c) {
    for (int i = 0; i < KU; ++i) {
        c[i] = a[i] | b[i];
    }
}

//пересечение
void intersection(const int KU, const bool *a, const bool *b, bool *c) {
    for (int i = 0; i < KU; ++i) {
        c[i] = a[i] & b[i];
    }
}

//Вывод множества
void conclusion(const int KU, const bool *a) {
    for (int i = 0; i < KU; i++)
        if (a[i] == true)
            printf("%d ", i + 1);
    printf("\n");
}

//Ввод множества
void output(const bool *a) {
    for (int i = 0; i < l; i++)
        if (a[i])
            printf("%d ", i + 1);
    printf("\n");
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    bool U[l] = {1, 1, 1, 1, 1, 1, 1,};
    bool A[l] = {1, 0, 1, 0, 1, 0, 1};
    printf("Множество A: ");
    output(A);
    bool B[l] = {0, 1, 1, 0, 0, 1, 1};
    printf("Множество B: ");
    output(B);
    bool C[l] = {0, 0, 0, 1, 1, 1, 1};
    printf("Множество C: ");
    output(C);
    bool d1[l] = {};
    bool d2[l] = {};
    bool d3[l] = {};
    bool D1[l] = {};
    bool D2[l] = {};
    bool D3[l] = {};
    bool D4[l] = {};

    intersection(l, A, B, d1);
    denial(l, A, B, d2);
    addition(l, d2, B, D1);
    intersection(l, D1, C, D2);
    addition(l, d1, D2, D4);

    printf("Для левой части: ");
    output(D4);

    denial(l, A, B, d1);
    denial(l, A, d1, d2);

    addition(l, d1, B, d3);
    denial(l, d3, C, D1);
    denial(l, d3, D1, D2);

    addition(l, d2, D2, D3);

    printf("Для правой части: ");
    output(D3);
    if (equals(D4, D3)) {
        printf("Множества, соответсвующие левой и правой части равны, "
               "следовательно, равенство является \nтеоретико-множественнным тождеством.");
    } else {
        printf("Множества, соответсвующие левой и правой части не равны, "
               "следовательно, равенство не является \nтеоретико-множественнным тождеством.");
    }
    return 0;
}