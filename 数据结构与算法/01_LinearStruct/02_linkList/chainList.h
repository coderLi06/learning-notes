//
// Created by ASUS on 25-6-8.
//

#ifndef CHAIN_LIST_H
#define CHAIN_LIST_H
#include "common.h"
//带头指针的单向链表，维护元素也是node，头指针指向第一个元素
//定义带头指针的链表头结构
typedef struct {
    node_t *header;
    int count;
}ChainList_t;
//链表头放到数据区，放到全局变量
void initChainList(ChainList_t *table);
//销毁链表的元素区域
void destroyChainList(ChainList_t *table);
int insertChainListHeader(ChainList_t *table, Element_t val);
int insertChainListPos(ChainList_t *table, int pos, Element_t val);
int deleteChainListElement(ChainList_t *table, Element_t *val);
void showChainList(ChainList_t *table);
#endif //CHAIN_LIST_H
