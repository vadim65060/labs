#include <stdio.h>
#include <malloc.h>
#include "ArrayInteract.h"

int main() {
    size_t n;
    printf("14.1)n=");
    scanf("%i", &n);
    int *a = (int *) malloc(n * sizeof(int));
    IntArrayRead(a, n);
    n = DeleteEvenNumbers(a, n);
    realloc(a, n * sizeof(int));
    IntArrayPrint(a, n);
    free(a);
}
