//
// Created by ASUS on 25-8-1.
//

#include "arrayStack.h"
#include <string.h>
/*递增空栈*/
void initArrayStack(ArrayStack *stack) {
    memset(stack->data, 0, sizeof(stack->data));
    stack->top = 0;
}

void pushArrayStack(ArrayStack *stack, Element e) {
    stack->data[stack->top] = e;//访问top需要记住是stack->top
    ++stack->top;
}

void popArrayStack(ArrayStack *stack) {
    --stack->top;
}

Element getTopArrayStack(const ArrayStack *stack) {
    int pos = stack->top-1;
    return stack->data[pos];
}

int isEmptyArrayStack(const ArrayStack *stack) {
    return stack->top == 0;
}

int isFullArrayStack(const ArrayStack *stack) {
    return stack->top == MaxStackSize;
}