#include "ArrayProcessing.h"

size_t GetLineWithMaxSum(double array[N][N], size_t n, size_t m) {
    double mxSum = -9e9;
    size_t mxi = -1;
    for (size_t i = 0; i < n; ++i) {
        double tempSum = 0;
        for (size_t j = 0; j < m; ++j) {
            tempSum += array[i][j];
        }
        if (tempSum > mxSum) {
            mxSum = tempSum;
            mxi = i;
        }
    }
    return mxi;
}