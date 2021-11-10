#include <stdio.h>
#include "ArrayProcessing.h"

int main() {
    int n;
    printf("12.2)n=");
    scanf("%i", &n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%i", &a[i]);
    }
    printf("A)%i\n", GetCountSwapsSign(a, n));
    printf("D)%i\n", GetMaxMonotonyOfArray(a, n));
    printf("F)%i\n", GetSecondMax(a, n));
    return 0;
}
