//
// Created by ASUS on 25-8-17.
//
#include <string.h>
#include "arrayStack.h"

/*递增空栈*/
void initArrayStack(ArrayStack *stack) {
    memset(stack->data, 0, sizeof(stack->data));
    stack->top = 0;
}

void pushArrayStack(ArrayStack *stack, TreeElement e) {
    stack->data[stack->top] = e;
    ++stack->top;
}

void popArrayStack(ArrayStack *stack) {
    --stack->top;//弹栈为什么只需要更新top的值，而不需要清除内容？
}

TreeElement getTopArrayStack(const ArrayStack *stack) {
    int pos = stack->top-1;
    return stack->data[pos];
}

int isEmptyArrayStack(const ArrayStack *stack) {
    return stack->top == 0;
}

int isFullArrayStack(const ArrayStack *stack) {
    return stack->top == MaxStackSize;
}