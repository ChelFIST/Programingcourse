#include "stdio.h"

double rope(const int *a, int k, int n) {
    double l = 0;
    double r = 1e8;

    for (int i = 0; i < 100; i++) {
        double m = (l + r) * 0.5;
        int s = 0;
        for (int j = 0; j < n; j++) {
            s += (int) (a[j] / m);
        }
        if (s >= k)
            l = m;
        else
            r = m;
    }
    return l;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%lf\n", rope(a, k, n));

    return 0;
}