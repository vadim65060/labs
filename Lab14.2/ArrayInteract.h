//
// Created by vadim on 18.02.2022.
//

#ifndef LAB14_1_ARRAYINTERACT_H
#define LAB14_1_ARRAYINTERACT_H

double *DoubleArrayRead(double *array, size_t n);

void DoubleArrayPrint(const double *array, size_t n);

double CalculateAverage(const double *array, size_t n);

double CalculateSrKv(const double *array, size_t n);

double *DeltaEpsFind(double *itBegin, const double *itEnd, double a, double eps);

void FindAllMiss(double *array, size_t n);

#endif //LAB14_1_ARRAYINTERACT_H
