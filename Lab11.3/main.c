#include <stdio.h>
#include "nums.h"


int main() {
    int n, p;
    printf("n=");
    scanf("%i", &n);
    printf("p=");
    scanf("%i", &p);
    printf("iter:\n");
    NumPrint(n, p);
    printf("\nrecursion:\n");
    RecNumPrint(n, p);
    printf("\nrevers recursion:\n");
    RecNumPrintRevers(n, p);
}
