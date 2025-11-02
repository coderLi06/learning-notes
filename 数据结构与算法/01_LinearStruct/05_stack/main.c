//
// Created by ASUS on 25-8-1.
//
#include "arrayStack.h"
#include <stdio.h>

#include "linkStack.h"
void test01() {
    ArrayStack info;

    initArrayStack(&info);
    for (int i = 0; i < 5; i++) {
        pushArrayStack(&info, i+100);
    }
    printf("push 5 elements");
    if (!isFullArrayStack(&info)) {
        pushArrayStack(&info, 500);
    }

    Element w;
    printf("show: ");
    while (!isEmptyArrayStack(&info)) {
        w = getTopArrayStack(&info);
        printf("\t%d", w);
        popArrayStack(&info);
    }
}

void test02() {
    LinkStack *stack = createLinkStack();
    if (stack == NULL) {
        return;
    }
    for (int i = 0; i < 5; ++i) {
        pushLinkStack(stack, i + 50);
    }
    printf("Have %d element on the stack!\n", stack->count);
    Element w;
    while (popLinkStack(stack, &w) != -1) {
        printf("\t%d", w);
    }
    printf("\n");
    releaseLinkStack(stack);
}

int main() {
    test01();
    test02();
    return 0;
}