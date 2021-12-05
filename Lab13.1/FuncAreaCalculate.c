//
// Created by Vadim on 03.12.2021.
//

#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include "FuncAreaCalculate.h"

double AreaCalculateLeftRectangle(struct funcdata data, double l, double r, size_t n) {
    double h = (r - l) * 1.0 / n;
    double sum = 0;
    for (double x = l; x < r; x += h) {
        data.x = x;
        double y = data.func(data);
        sum += y;
    }
    return sum * h;
}

double AreaCalculateMiddleRectangle(struct funcdata data, double l, double r, size_t n) {
    double h = (r - l) * 1.0 / n;
    data.x = l;
    double sum = data.func(data);
    data.x = r;
    sum = (sum + data.func(data)) / 2;
    for (int i = 1; i <= n - 1; i++) {
        data.x = l + i * h;
        sum += data.func(data);
    }
    return sum * h;
}

double AreaCalculateForEps(struct funcdata data, double l, double r, double eps, AreaCalculateFunc areaCalculateFunc) {
    size_t n = 1;
    double oldResult;
    double result = areaCalculateFunc(data, l, r, n);
    do {
        oldResult = result;
        n *= 2;
        result = areaCalculateFunc(data, l, r, n);
    } while (fabs(result - oldResult) > eps);
    return result;
}