#include "ArrayProcessing.h"

int max(int a, int b) {
    if (a > b)return a;
    return b;
}

int GetCountSwapsSign(const int array[], int size) {
    int k = 0;
    for (int i = 0; i < size - 1; ++i) {
        if ((array[i] > 0) != (array[i + 1] > 0)) {
            ++k;
        }
    }
    return k;
}

int GetMaxMonotonyOfArray(const int array[], int size) {
    int mx = -1, tempMax = 2;
    for (int i = 1; i < size - 1; ++i) {
        if (((array[i - 1] > array[i]) == (array[i] > array[i + 1])) || (array[i] == array[i + 1])) {
            ++tempMax;
        } else {
            mx = max(mx, tempMax);
            tempMax = 1;
        }
    }
    mx = max(mx, tempMax);
    return mx;
}

int GetSecondMax(const int array[], int size) {
    int mx = -1, secondMx = -1;
    for (int i = 0; i < size; ++i) {
        if (array[i] >= mx) {
            secondMx = mx;
            mx = array[i];
        }
    }
    return secondMx;
}