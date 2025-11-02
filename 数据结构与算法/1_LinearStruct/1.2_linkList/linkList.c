//
// Created by ASUS on 25-6-5.
//
#include <stdio.h>
#include "linkList.h"
#include <stdlib.h>
LinkList_t * creatLinkList() {
    //为表头分配空间
    LinkList_t *table = NULL;
    table = malloc(sizeof(LinkList_t));
    //分配空间后，要检查是否分配成功
    if (table == NULL) {
        return NULL;
    }
    //初始化表中的值
    table->count = 0;
    table->head->val = 0;
    table->head->next = NULL;
    return table;

}

void releaseLinkList(LinkList_t *table) {
    //先依次删除表中节点，再删除表头
    //引入辅助指针，指向表头的head节点，方便定位，删除后面的节点
    if (table) {
        node_t *p = table->head;
        node_t *tmp;
        while (p->next) {
            tmp = p->next;
            p->next = tmp->next;
            free(tmp);
            --table->count;
        }
        printf("link list has %d node\n",table->count);
    }
}



int insertLinkListHeader(LinkList_t *table, Element_t val) {
    node_t *p = &table->head;
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return -1;
    }
    new_node->val = val;
    new_node->next = p->next;
    p->next = new_node;
    ++table->count;
    return 0;
}

int insertLinkListPos(LinkList_t *table, int pos,Element_t val) {
    //按照下标位置插入
    //1.判断边界值
    if (pos < 0 || pos > table->count) {
        printf("insert pos invalid!\n");
        return -1;
    }
    //找到pos-1索引的节点首地址
    node_t *p = &table->head;
    int index = -1;//因为从head开始
    while (index < pos -1) {
        p = p->next;
        ++index;
    }
    node_t *new_node = malloc(sizeof(node_t));
    new_node->val = val;
    new_node->next = p->next;
    p->next = new_node;
    ++table->count;
    return 0;
}

int deleteLinkList(LinkList_t *table, Element_t val) {
    //按照元素的值删除节点
    node_t *p = &table->head;
    while (p->next) {
        if (p->next->val == val) {
            break;
        }
        p = p->next;
    }
    if (p->next == NULL) {
        printf("Not Find!\n");
        return -1;
    }
    node_t *tmp = p->next;
    p->next = tmp->next;
    free(tmp);
    --table->count;
    return 0;
}

void showLinkList(LinkList_t *table) {
    node_t *p = &table->head;
    printf("link list has %d nodes\n",table->count);
    while (p) {
        printf("%d\t",p->val);
        p = p->next;
    }
    printf("\n");
}
