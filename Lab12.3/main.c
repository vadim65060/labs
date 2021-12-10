#include <stdio.h>
#include <malloc.h>
#include "ArrrayProcessing.h"

int main() {
    int n;
    printf("12.3)n=");
    scanf("%i", &n);
    int *a = (int *) malloc(n * sizeof(int));
    for (size_t i = 0; i < n; ++i) {
        scanf("%i", &a[i]);
    }
    n = (int) (DeleteEvenNumbers(a, n));
    for (size_t i = 0; i < n; ++i) {
        printf("%i ", a[i]);
    }
    free(a);
}
