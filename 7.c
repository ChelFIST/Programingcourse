#include <stdio.h>
#include <stdbool.h>

void sort2(int *a, int *b) {
    if (*a > *b) {
        int t = *a;
        *a = *b;
        *b = t;
    }
}

bool isNearestFibonacciMembers_(int a, int b, int fib1, int fib2) {
    if (b > fib2)
        return isNearestFibonacciMembers_(a, b, fib2, fib1 + fib2);
    else
        return a == fib1 && b == fib2;
}

bool isNearestFibonacciMembers(int a, int b) {
    sort2(&a, &b);

    return isNearestFibonacciMembers_(a, b, 1, 1);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d",isNearestFibonacciMembers(a, b));
    return 0;
}