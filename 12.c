#include "stdbool.h"

#define SIZE 10
// объединение двух множеств
void combiningSets(const bool *const a, const bool *const b, bool *c) {
    for (int i = 0; i<SIZE; i++) {
        if (a[i] == false && b[i] == a[i])
            c[i] = false;
        else
            c[i] = true;
    }
}

// пересечение двух множеств
void intersectionOfSets(const bool *const a, const bool *const b, bool *c) {
    for (int i = 0; i<SIZE; i++) {
        if (a[i] == true && b[i] == a[i])
            c[i] = true;
        else
            c[i] = false;
    }
}

// разность двух множеств
void differenceOfSets(const bool *const a, const bool *const b, bool *c) {
    for (int i = 0; i<SIZE; i++) {
        if (a[i] == true && b[i] != a[i])
            c[i] = true;
        else
            c[i] = false;
    }
}

// симметрическая разность
void symmetricDifferenceOfSets(const bool *const a, const bool *const b, bool *c) {
    for (int i = 0; i<SIZE; i++) {
        if ((a[i] == true || b[i] == true) && b[i] != a[i])
            c[i] = true;
        else
            c[i] = false;
    }
}

// дополнение множеств до универсума
void complementOfSets(const bool *const a, bool *c) {
    for (int i = 0; i<SIZE; i++)
        if (a[i] == false)
            c[i] = a[i];
}

// включение
bool inclusion(const int *const a, const int *const b) {
    for (int l = 0; l <SIZE; l++)
        if (a[l] > b[l])
            return false;

    return true;
}

// строгое включение
bool strictInclusion(const int *const a, const int *const b) {
    for (int l = 0; l <SIZE; l++)
        if (a[l] != b[l])
            return false;

    return true;
}
