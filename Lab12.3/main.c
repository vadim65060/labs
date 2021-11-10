#include <stdio.h>
#include "ArrrayProcessing.h"

int main() {
    int n;
    printf("12.3)n=");
    scanf("%i", &n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%i", &a[i]);
    }
    n = DeleteEvenNumbers(a, n);
    for (int i = 0; i < n; ++i) {
        printf("%i ", a[i]);
    }
}
