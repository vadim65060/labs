#include <stdio.h>
#include "nums.h"

void NumPrint(int p) {
    for (int i = p - 1; i >= 0; --i) {
        printf("%c ", num[i]);
    }
    printf("\n");
}

void RecNumPrint(int p) {
    if (p == 0) {
        printf("\n");
        return;
    }
    printf("%c ", num[p - 1]);
    RecNumPrint(p - 1);
}
