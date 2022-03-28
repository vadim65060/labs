//
// Created by vadim on 28.03.2022.
//

#include <stddef.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include "stack.h"

typedef struct Stack Stack;
typedef struct Node Node;
typedef struct Value Value;


struct Value {
    void *value;
    enum type valueType;
};


struct Node {
    Value value;
    Node *back, *next;
};

struct Stack {
    size_t len;
    Node *first, *last;
    Node *current;
};

Stack *StackInit() {
    Stack *initStack = (Stack *) malloc(sizeof(Stack));
    initStack->last = NULL;
    initStack->first = NULL;
    initStack->current = NULL;
    initStack->len = 0;
    return initStack;
}

Node *Push(Stack *stack, enum type valueType, void *value) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->value.valueType = valueType;
    node->value.value = value;
    node->next = NULL;
    node->back = NULL;
    if (stack->len == 0) {
        stack->last = node;
        stack->first = node;
    } else {
        stack->last->next = node;
        stack->last = node;
    }
    stack->len++;
    printf("in=%i\n", *(int *) (node->value.value));
    return node;
}

void Pop(Stack *stack) {
    Node *node = stack->last;
    if (stack->len < 2) {
        stack->first = NULL;
        stack->len = 0;
    } else {
        stack->len--;
    }
    stack->last = NULL;
    if (node != NULL) {
        free(stack->last);
    }
}

Value Back(Stack *stack) {
    return stack->last->value;
}

void StackDelete(Stack *stack) {
    while (stack->len > 0) {
        Pop(stack);
    }
    free(stack);
}

int SCat(char *inS, int n, const char *outS) {
    char *j = inS + n;
    for (const char *i = outS; *i != '\0'; ++i, ++j) {
        *j = *i;
    }
    int r = j - inS - n;
    return r;
}

void StrReverse(char *s, int len) {
    for (int i = 0; i < len / 2; ++i) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

int ToString(int n, char *s) {
    int i = 0;
    while (n) {
        char c = '0' + n % 10;
        SCat(s, i, &c);
        n /= 10;
        ++i;
        s[i] = '\0';
    }
    StrReverse(s,i);
    return i;
}

void StackToStr(Stack *stack, char *str, int maxSize) {
    char *s = str;
    int it = 0;
    if (str == NULL) {
        s = (char *) malloc(maxSize * sizeof(char));
        s[0] = '\0';
    }
    Node *node = stack->first;
    for (; node != NULL; node = node->next) {
        char tempS[20];
        switch (node->value.valueType) {
            case STR:
                it += SCat(s, it, node->value.value);
                break;
            case INT:
                ToString(*(int *) (node->value.value), tempS);
                it += SCat(s, it, tempS);
                it += SCat(s, it, " ");
                break;
        }
        if(maxSize-it<50){
            if(maxSize-it>10)
                it +=SCat(s,it,"LowSize");
            break;
        }
    }
    s[it] = '\0';
    if (str == NULL)
        printf("%s", s);
}