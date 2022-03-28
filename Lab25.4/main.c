#include <stdio.h>
#include <malloc.h>
#include "stack.h"

int main() {
    size_t len = 1000;
    char *s = (char *) malloc(len * sizeof(char));
    //printf("%s\n",s);
    //getline(&s, &len, stdin);
    Stack *stack = StackInit();

    int n;
    scanf("%i", &n);
    int ttt[n];
    for (int i = 0; i < n; ++i) {
        scanf("%i", &ttt[i]);
        Push(stack,INT,&ttt[i]);
    }
    StackToStr(stack,s,1000);
    printf("res=%s",s);
}
