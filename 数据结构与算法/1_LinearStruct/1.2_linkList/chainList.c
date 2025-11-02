//
// Created by ASUS on 25-6-8.
//

#include "chainList.h"
#include <stdio.h>
#include <stdlib.h>

void initChainList(ChainList_t *table) {
    table->count = 0;
    table->header = NULL;
}

void destroyChainList(ChainList_t *table) {
    node_t dummy;
    dummy.next = table->header;

    node_t *p = &dummy;
    node_t *tmp;
    while (p->next) {
        tmp = p->next;
        p->next = tmp->next;
        free(tmp);
        --table->count;
    }
    printf("LinkList have %d node!\n", table->count);
    table->header = NULL;
}

int insertChainListHeader(ChainList_t *table, Element_t val) {
    node_t dummy;
    dummy.next = table->header;
    node_t *p = &dummy;
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL) {
        return -1;
    }
    new_node->val = val;
    new_node->next = p->next;
    p->next = new_node;

    ++table->count;
    table->header = new_node;
    return 0;
}

int insertChainListPos(ChainList_t *table, int pos, Element_t val) {
    node_t dummy;
    dummy.next = table->header;

    //1.判断边界值
    if (pos < 0 || pos > table->count) {
        printf("insert pos valid\n");
        return -1;
    }
    //2.找到pos-1索引的节点首地址
    node_t *p = &dummy;
    int index = -1;
    while (index < pos -1) {
        p = p->next;
        ++index;
    }
    node_t *new_node = malloc(sizeof(node_t));
    new_node->val = val;
    new_node->next = p->next;
    p->next = new_node;
    ++table->count;

    table->header = dummy.next;//或者写成new_node
    return 0;
}

int deleteChainListElement(ChainList_t *table, Element_t val) {
    node_t dummy;
    dummy.next = table->header;

    node_t *p = &dummy;
    while (p->next && p->next->val != val) {
        p = p->next;
    }
    if (p->next == NULL) {
        printf("Not FinD!\n");
        return -1;
    }
    node_t *tmp = p->next;
    p->next = tmp->next;
    free(tmp);
    --table->count;

    table->header = dummy.next;
    return 0;
}

void showChainList(const ChainList_t *table) {
    node_t *p = table->header;
    printf("LinkList have %d node!\n", table->count);
    while (p) {
        printf("%d->", p->next->val);
        p = p->next;
    }
    printf("\n");
}