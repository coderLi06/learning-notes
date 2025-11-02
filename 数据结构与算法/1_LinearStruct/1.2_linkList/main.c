#include <stdio.h>
#include "linkList.h"
// 需求：设计并实现一个带头节点的单向链表，实现头插法、
// 任意位置插入法，按照值来删除某个元素，显示整个链表的数据
// Created by ASUS on 25-6-6.
int main() {
    printf("link Table!\n");
    LinkList_t *table = creatLinkList();
    if (!table) {
        return -1;
    }
for (int i = 0;i < 10;i++) {
    insertLinkListHeader(table, i + 100);
}
    insertLinkListPos(table,3,300);
    showLinkList(table);
    printf("==========");
    deleteLinkList(table,105);
    showLinkList(table);
    releaseLinkList(table);
    return 0;
}
