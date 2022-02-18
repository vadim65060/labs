#include <stdio.h>
#include <malloc.h>
#include "ArrayInteract.h"

int main() {
    size_t n;
    printf("14.2)n=");
    scanf("%i", &n);
    double *array = (double *) malloc(n * sizeof(double));
    DoubleArrayRead(array, n);
    printf("%lf\n%lf\n", CalculateAverage(array, n), CalculateSrKv(array, n));
    FindAllMiss(array, n);
}
