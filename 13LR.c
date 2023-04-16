#include "stdio.h"
#include "stdlib.h"

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int main() {
    long long n;
    scanf("%lld", &n);

    int a[n], b[n], c[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; i++) {
        c[i] = a[i] - b[i];
    }
    qsort(c, n, sizeof(int), compare_ints);

    long long counter = 0;
    int l = 0;
    long long r = n - 1;

    while (l < r) {
        if (c[l] + c[r] > 0) {
            counter += (r - l);
            r--;
        } else {
            l++;
        }
    }
    printf("%lld", counter);

    return 0;
}