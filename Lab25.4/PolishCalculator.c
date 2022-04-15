//
// Created by vadim on 08.04.2022.
//

#include <string.h>
#include <math.h>
#include "PolishCalculator.h"


int Calculate(Stack *stack, char *operation) {
    if (stack->len < 1)return -1;
    if (strcmp(operation, "+") == 0) {
        if (stack->len < 2)
            return -1;
        double n1 = Pop(stack);
        double n2 = Pop(stack);
        Push(stack, n1 + n2);
    } else if (strcmp(operation, "-") == 0) {
        if (stack->len < 2)
            return -1;
        double n1 = Pop(stack);
        double n2 = Pop(stack);
        Push(stack, n2 - n1);
    } else if (strcmp(operation, "*") == 0) {
        if (stack->len < 2)
            return -1;
        double n1 = Pop(stack);
        double n2 = Pop(stack);
        Push(stack, n2 * n1);
    } else if (strcmp(operation, "/") == 0) {
        if (stack->len < 2)
            return -1;
        double n1 = Pop(stack);
        double n2 = Pop(stack);
        Push(stack, n2 / n1);
    } else if (strcmp(operation, "^") == 0) {
        if (stack->len < 2)
            return -1;
        double n1 = Pop(stack);
        double n2 = Pop(stack);
        Push(stack, pow(n2, n1));
    } else if (strcmp(operation, "inv") == 0) {
        Push(stack, 1 / Pop(stack));
    } else if (strcmp(operation, "rev") == 0) {
        Push(stack, -Pop(stack));
    } else if (strcmp(operation, "sin") == 0) {
        Push(stack, sin(Pop(stack)));
    } else if (strcmp(operation, "cos") == 0) {
        Push(stack, cos(Pop(stack)));
    } else {
        return 1;
    }
    return 0;
}
