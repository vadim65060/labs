#include <stdio.h>
#include <malloc.h>
#include "StrToArr.h"

int main() {
    size_t len = 1000;
    char *s;
    s = (char *) malloc(len * sizeof(char));
    printf("s=");
    getline(&s, &len, stdin);
    char *words[100];
    size_t n = ToArr(s, words);
    for (size_t i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

}
