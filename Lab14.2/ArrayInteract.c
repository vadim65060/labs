//
// Created by vadim on 18.02.2022.
//

#include <stdio.h>
#include "ArrayInteract.h"
#include "math.h"

#define pow2(x) ((x)*(x))

double *DoubleArrayRead(double *array, size_t n) {
    for (double *i = array; i != array + n; ++i) {
        scanf("%lf", i);
    }
    return array;
}

void DoubleArrayPrint(const double *array, size_t n) {
    for (const double *i = array; i != array + n; ++i) {
        printf("%lf ", *i);
    }
    printf("\n");
}

double CalculateAverage(const double *array, size_t n) {
    double sum = 0;
    for (const double *i = array; i != array + n; ++i) {
        sum += *i;
    }
    return sum / n;
}

double CalculateSrKv(const double *array, size_t n) {
    double sum = 0;
    double average = CalculateAverage(array, n);
    for (const double *i = array; i != array + n; ++i) {
        sum += pow2(*i - average);
    }
    return sqrt(sum / (n - 1));
}

double *DeltaEpsFind(double *itBegin, const double *itEnd, double a, double eps) {
    for (double *i = itBegin; i != itEnd; ++i) {
        if (fabs(*i - a) > eps)return i;
    }
    return NULL;
}

void FindAllMiss(double *array, size_t n) {
    double average = CalculateAverage(array, n);
    double srKv = CalculateSrKv(array, n);
    double *itEnd = array + n;
    double *itBegin = array;
    while ((itBegin = DeltaEpsFind(itBegin, itEnd, average, srKv))){
        printf("%i %lf\n", itBegin - array + 1, *itBegin);
        ++itBegin;
    }
}