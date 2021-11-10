#include <stdio.h>
#include "nums.h"

const char num[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};


void NumPrint(int n, int p) {
    while (n) {
        printf("%c ", num[n % p]);
        n /= p;
    }
}

void RecNumPrintRevers(int n, int p) {
    if (!n) {
        return;
    }
    printf("%c ", num[n % p]);
    RecNumPrintRevers(n / p, p);
}


void RecNumPrint(int n, int p) {
    if (!n) {
        return;
    }
    RecNumPrint(n / p, p);
    printf("%c ", num[n % p]);
}
