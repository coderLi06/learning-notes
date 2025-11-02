//
// Created by ASUS on 25-6-22.
//

#include "linklooplist.h"
#include <stdio.h>
#include <stdlib.h>

void initLinkLoopList(LinkLoopList *link_loop) {
    link_loop->header.next = link_loop->rear = &link_loop->header;
    link_loop->num = 0;
}

int insertLinkLoopHeader(LinkLoopList* link_loop, Element value) {
    //1.先有新节点
    LoopNode* node = malloc(sizeof(LoopNode));
    if (node == NULL) {
        return -1;
    }
    node->val = value;
    node->next = link_loop->header.next;
    link_loop->header.next = node;
    //判断尾指针是否需要更新
    if (link_loop->rear == &link_loop->header) {
        link_loop->rear = node;
    }
    ++link_loop->num;
    return 0;
}

int insertLinkLoopRear(LinkLoopList* link_loop, Element value) {
    //1.先有新节点
    LoopNode* node = malloc(sizeof(LoopNode));
    if (node == NULL) {
        return -1;
    }
    node->val = value;
    node->next = link_loop->rear->next;
    //2.判断头节点是否需要更新
    if (&link_loop->header == link_loop->rear) {
        link_loop->rear->next = node;
    }
    link_loop->rear->next = node;//连接原来最后一个节点和新插入的节点
    link_loop->rear = node;//更新尾指针指向新节点

    ++link_loop->num;
    return 0;
}

void showLinkLoopList(const LinkLoopList* link_loop) {
    LoopNode *node = link_loop->header.next;
    while (node != &link_loop->header) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

int deleteLinkLoopList(LinkLoopList* link_loop, Element value) {
    LoopNode *node = &link_loop->header;
    while (node->next != &link_loop->header && node->next->val != value) {
        node = node->next;
    }
    if (node->next->val == value) {
        LoopNode *tmp = node->next;
        node->next = tmp->next;
        free(tmp);
        --link_loop->num;
    } else {
        printf("Element not found\n");
    }
    return 0;
}

void destroyLinkLoopList(LinkLoopList* link_loop) {
    LoopNode *node = link_loop->header.next;
    while (node != &link_loop->header) {
        LoopNode *tmp = node;
        node = node->next;
        free(tmp);
        --link_loop->num;
    }
    printf("Table %d element!\n", link_loop->num);
}