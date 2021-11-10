#include "ArrrayProcessing.h"

int DeleteEvenNumbers(int array[], int size) {
    int j = 0;
    for (int i = 0; i < size; ++i) {
        array[j] = array[i];
        if (array[i] % 2)j++;
    }
    return j; //new size
}