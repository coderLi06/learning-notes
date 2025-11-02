//
// Created by ASUS on 25-8-17.
//

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
typedef void* TreeElement;//C语言万能指针特性
#define MaxStackSize 16

typedef struct {
    TreeElement data[MaxStackSize];
    int top;
}ArrayStack;

/*递增空栈*/
void initArrayStack(ArrayStack *stack);

void pushArrayStack(ArrayStack *stack, TreeElement e);
void popArrayStack(ArrayStack *stack);

TreeElement getTopArrayStack(const ArrayStack *stack);

int isEmptyArrayStack(const ArrayStack *stack);
int isFullArrayStack(const ArrayStack *stack);
#endif //ARRAY_STACK_H
