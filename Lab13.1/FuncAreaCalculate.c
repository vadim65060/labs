//
// Created by Vadim on 03.12.2021.
//

#include <stddef.h>
#include <stdio.h>
#include "FuncAreaCalculate.h"

double AreaCalculate(struct funcdata data, double l, double r, size_t n) {
    double h = (r - l) * 1.0 / n;
    double sum = 0;
    for (double x = l; x < r; x += h) {
        data.x = x;
        double y = data.func(data);
        sum += y;
        printf("x=%lf y=%lf\n",data.x,y);
    }
    printf("%lf",sum);
    return sum * h;
}