#include <stdio.h>
#include "ArrrayProcessing.h"

int main() {
    int n;
    printf("12.3)n=");
    scanf("%i", &n);
    int a[n];
    for (size_t i = 0; i < n; ++i) {
        scanf("%i", &a[i]);
    }
    n = (int)(DeleteEvenNumbers(a, n));
    for (size_t i = 0; i < n; ++i) {
        printf("%i ", a[i]);
    }
}
