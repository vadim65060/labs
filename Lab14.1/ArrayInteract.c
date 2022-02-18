//
// Created by vadim on 18.02.2022.
//

#include <stdio.h>
#include <malloc.h>
#include "ArrayInteract.h"

int *IntArrayRead(int *array, size_t n) {
    for (int *i = array; i != array + n; ++i) {
        scanf("%i", i);
    }
    return array;
}

void IntArrayPrint(const int *array, size_t n) {
    for (int *i = array; i != array + n; ++i) {
        printf("%i ", *i);
    }
    printf("\n");
}

size_t DeleteEvenNumbers(int *array, size_t size) {
    int *j = array;
    for (int *i = array; i != array + size; ++i) {
        if (*i % 2) {
            *j = *i;
            ++j;
        }
    }
    return j - array;
}