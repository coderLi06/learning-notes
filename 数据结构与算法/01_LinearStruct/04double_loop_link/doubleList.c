//
// Created by ASUS on 25-7-1.
//

#include "doubleList.h"
#include <stdlib.h>
#include <stdio.h>

static void addDNode(DNode* new_node, DNode* prev, DNode* next) {
    next->prev = new_node;
    new_node->next = next;
    new_node->prev = prev;
    prev->next = new_node;
}

static void delDNode(DNode*prev, DNode* next) {
    next->prev = prev;
    prev->next = next;
}

void initDList(DList* header) {
    header->val = 0;
    header->next = header->next = header;
}

void releaseDList(DList* header) {
    DNode* pos = header->next;
    DNode* tmp = NULL;
    while (pos != header) {
        tmp = pos;
        delDNode(pos->prev, pos->next);
        pos = pos->next;
        free(tmp);
        --header->val;
    }
}

void insertDListHeader(DList* header, Element val) {
    DNode* new_node = malloc(sizeof(DNode));
    new_node->val = val;
    addDNode(new_node, header, header->next);
    ++header->val;
}

void insertDListRear(DList* header, Element val) {
    DNode* new_node = malloc(sizeof(DNode));
    new_node->val = val;
    addDNode(new_node, header->prev, header);
    ++header->val;
}

void showDList(const DList* header) {
    DNode* pos = header->next;
    while (pos != header) {
        printf("%d ", pos->val);
        pos = pos->next;
    }
}

void delDList(DList* header, Element e) {
    //找到这个元素就可以删除，不再需要找到前置节点删除
    DNode* pos = header->next;
    while (pos != header && pos->val != e) {
        pos = pos->next;
    }
    if (pos != header) {
        delDNode(pos->prev, pos->next);
        pos->prev = pos->next = NULL;//写不写都行
        free(pos);
        --header->val;
    }else {
        printf("Not find");
    }
}