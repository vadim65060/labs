//
// Created by vadim on 28.03.2022.
//

#ifndef LAB25_4_STACK_H
#define LAB25_4_STACK_H

typedef struct Stack Stack;
typedef struct Node Node;
typedef struct Value Value;

enum type {
    INT, STR
};

Stack *StackInit();

Node *Push(Stack *stack, enum type valueType, void *value);

void Pop(Stack *stack);

Value Back(Stack *stack);

void StackDelete(Stack *stack);

void StackToStr(Stack *stack, char *str, int maxSize);

#endif //LAB25_4_STACK_H
