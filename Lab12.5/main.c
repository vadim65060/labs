#include <stdio.h>
#include "ArrayProcessing.h"

int main() {
    size_t n, m;
    printf("12.5)\nn=");
    scanf("%i", &n);
    printf("m=");
    scanf("%i", &m);
    double array[N][N];
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            double x;
            scanf("%lf", &x);
            array[i][j] = x;
        }
    }
    printf("%i", GetLineWithMaxSum(array, n, m) + 1);
}
