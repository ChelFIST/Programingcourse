#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
bool leftCheck(bool A, bool B, bool C) {
    bool result = ((A | B) & !C);
    return result;
}
bool rightCheck(bool A, bool B, bool C) {
    bool result = (!C) & !((!C) & !((A-B)^B));
    return result;
}
int main() {
    SetConsoleOutputCP(CP_UTF8);
    bool t[3] = {false};
    printf("A\tB\tC\t\tЛХФ левой части\t\tЛХФ правой части\n");
    printf("%d\t%d\t%d\t\t\t%d\t\t\t%d\n", t[0], t[1], t[2],
           leftCheck(t[0], t[1], t[2]),
           rightCheck(t[0], t[1], t[2]));
    bool flag = true;
    while (t[0] != 1 || t[1] != 1 || t[2] != 1) {
        if (t[2]) {
            if (t[1]) {
                t[0] = true;
                t[1] = t[2] = false;
            } else {
                t[1] = true;
                t[2] = false;
            }
        } else {
            t[2] = true;
        }
        printf("%d\t%d\t%d\t\t\t%d\t\t\t%d\n", t[0], t[1], t[2],
               leftCheck(t[0], t[1], t[2]),
               rightCheck(t[0], t[1], t[2]));
        if (leftCheck(t[0], t[1], t[2] != rightCheck(t[0], t[1], t[2]))) {
            flag = false;
        }
    }
    if (flag) {
        printf("Таблицы истинности ЛХФ левой и правой частей совпадают, следовательно, тождество верно.");
    } else {
        printf("Таблицы истинности ЛХФ левой и правой частей не совпадают, следовательно, тождество не верно.");
    }
    return 0;
}