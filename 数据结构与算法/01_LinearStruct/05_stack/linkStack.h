//
// Created by ASUS on 25-8-1.
//

#ifndef LINK_STACK_H
#define LINK_STACK_H
typedef int Element;
typedef struct _node {
    Element data;
    struct _node *next;
}StackNode;
typedef struct {
    StackNode *top;
    int count;
}LinkStack;
LinkStack *createLinkStack();
void releaseLinkStack(LinkStack *stack);

int pushLinkStack(LinkStack *stack, Element e);
int popLinkStack(LinkStack *stack, Element e);

#endif //LINK_STACK_H
