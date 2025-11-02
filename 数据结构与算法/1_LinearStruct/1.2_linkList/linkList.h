//
// Created by ASUS on 25-6-5.
//

#ifndef LINKLIST_H
#define LINKLIST_H
#include "common.h"

//定义链表头的结构，即为表的类型，包含计数和节点类型
typedef struct  {
    node_t *head;
    int count;
}LinkList_t;

LinkList_t *creatLinkList();
void releaseLinkList(LinkList_t *table);//释放内存
int insertLinkListHeader(LinkList_t *table, Element_t val);//头插法
int insertLinkListPos(LinkList_t *table, int pos, Element_t val);//按位置插入（第几个）
int deleteLinkList(LinkList_t *table, Element_t val);//按值删除
void showLinkList(LinkList_t *table);//显示链表元素；表的类型是表头
#endif //LINKLIST_H
