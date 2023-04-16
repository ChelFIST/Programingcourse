#include "stdio.h"

int findLowest(int *a, int x, int n) {
    int l = -1;
    int r = n;
    while (r > l + 1) {
        int m = (l + r) / 2;
        if (a[m] <= x)
            l = m;
        else
            r = m;
    }
    return l+1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int j = 0; j < k; j++) {
        int x;
        scanf("%d", &x);

        printf("%d\n", findLowest(a,x,n));
    }

    return 0;
}