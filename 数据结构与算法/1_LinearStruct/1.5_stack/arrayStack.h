//
// Created by ASUS on 25-8-1.
//

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
#define MaxStackSize 5
typedef int Element;
typedef struct {
    Element data[MaxStackSize];
    int top;;
}ArrayStack;
/*递增空栈*/
//函数参数代表要对此类对象进行操作
//如int a表示对int类型变量传入的值进行操作,* p表示对指针类型变量传入的值
//进行操作，即为地址中存放的值
//传参的本质是值传递
void initArrayStack(ArrayStack *stack);//指向栈结构体的指针

void pushArrayStack(ArrayStack *stack,Element e);
void popArrayStack(ArrayStack *stack);

Element getTopArrayStack(const ArrayStack *stack);

int isEmptyArrayStack(const ArrayStack *stack);
int isFullArrayStack(const ArrayStack *stack);

#endif //ARRAY_STACK_H
