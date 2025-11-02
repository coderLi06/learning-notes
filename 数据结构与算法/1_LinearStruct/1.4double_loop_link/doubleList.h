//
// Created by ASUS on 25-7-1.
//

#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H
typedef int Element;
typedef struct _node {
    Element val;
    struct _node* next;
    struct _node* prev;
}DNode,DList;

//使用一个带头结点的双向循环链表，头结点让用户来管理，提供初始化接口
void initDList(DList* header);
void releaseDList(DList* header);

//实现头插尾插
void insertDListHeader(DList* header, Element val);
void insertDListRear(DList* header, Element val);
//显示链表
void showDList(const DList* header);
//删除一个元素
void delDList(DList* header, Element e);

#endif //DOUBLE_LIST_H
