//链式栈的实现
// Created by ASUS on 25-8-1.
//满递增栈

#include "linkStack.h"
#include <stdio.h>
#include <stdlib.h>

LinkStack* createLinkStack() {
    LinkStack* link_stack = malloc(sizeof(LinkStack));
    if (link_stack == NULL) {
        fprintf(stderr, "linkStack malloc failed!\n");
        return NULL;
    }
    link_stack->top = NULL;
    link_stack->count = 0;
    return link_stack;
}
//从第一个元素的前面链接，方便后续删除
void releaseLinkStack(LinkStack *stack) {
    if (stack) {
        while (stack->top) {
            StackNode *tmp = stack->top;
            stack->top = tmp->next;
            free(tmp);
            --stack->count;
        }
        printf("stack count: %d\n",stack->count);
    }
}

int pushLinkStack(LinkStack *stack, Element e) {
    StackNode *node = malloc(sizeof(StackNode));
    if (node == NULL) {
        fprintf(stderr, "malloc failed!\n");
        return -1;
    }
    node->data = e;

    node->next = stack->top;
    stack->top = node;
    ++stack->count;
    return 0;
}

int popLinkStack(LinkStack *stack, Element *e) {
    if (stack->top == NULL) {
        fprintf(stderr, "stack empty!\n");
        return -1;
    }
    e = stack->top->data;
    StackNode *tmp = stack->top;
    stack->top = tmp->next;
    free(tmp);
    --stack->count;
    return 0;
}