#include <stdio.h>
#include "reader.h"

int ReadInt(const char *message) {
    int n, loop = 1;
    char var[32];
    do {
        if (message != NULL)
            printf("%s", message);
        scanf("%s", &var);
        if (sscanf(var, "%i", &n) == 1)
            loop = 0;
        else {
            printf("%s", "Incorrect input. Try again.\n");
        }

    } while (loop);
    return n;
}