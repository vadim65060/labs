#include "ArrayProcessing.h"
#include <stdio.h>

size_t max(size_t a, size_t b) {
    if (a > b)return a;
    return b;
}

size_t GetCountSwapsSign(const int array[], size_t size) {
    size_t k = 0;
    for (size_t i = 0; i < size - 1; ++i) {
        if ((array[i] > 0) != (array[i + 1] > 0)) {
            ++k;
        }
    }
    return k;
}

size_t GetMaxMonotonyOfArray(const int array[], size_t size) {
    size_t mx = -1, tempMaxUp = 1, tempMaxDown = 1;
    for (size_t i = 1; i < size; ++i) {
        if (array[i - 1] >= array[i]) {
            tempMaxDown++;
        } else {
            mx = max(mx, tempMaxDown);
            tempMaxDown = 1;
        }
        if (array[i - 1] <= array[i]) {
            tempMaxUp++;
        } else {
            mx = max(mx, tempMaxUp);
            tempMaxUp = 1;
        }
    }
    mx = max(max(mx, tempMaxUp), tempMaxDown);
    return mx;
}

int GetSecondMax(const int array[], size_t size) {
    int mx = -1, secondMx = -1;
    for (size_t i = 0; i < size; ++i) {
        if (array[i] >= mx) {
            secondMx = mx;
            mx = array[i];
        } else if (array[i] > secondMx) {
            secondMx = array[i];
        }
    }
    return secondMx;
}