#include "ArrrayProcessing.h"

size_t DeleteEvenNumbers(int array[], size_t size) {
    size_t j = 0;
    for (size_t i = 0; i < size; ++i) {
        if (array[i] % 2) {
            array[j] = array[i];
            j++;
        }
    }
    return j; //new size
}