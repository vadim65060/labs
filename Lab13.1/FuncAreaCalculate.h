//
// Created by Vadim on 03.12.2021.
//

#ifndef LAB13_1_FUNCAREACALCULATE_H
#define LAB13_1_FUNCAREACALCULATE_H

#include "Functions.h"

typedef double (*AreaCalculateFunc)(struct funcdata, double, double, size_t);

double AreaCalculateLeftRectangle(struct funcdata data, double l, double r, size_t n);

double AreaCalculateMiddleRectangle(struct funcdata data, double l, double r, size_t n);

double AreaCalculateForEps(struct funcdata data, double l, double r, double eps, AreaCalculateFunc areaCalculateFunc);

double UnknownAreaCalculateFunc(struct funcdata data, double l, double r, size_t n);

#endif //LAB13_1_FUNCAREACALCULATE_H
