//链式队列的实现，链式的核心在于节点
// Created by ASUS on 25-8-8.
//
#include <stdio.h>
#include <stdlib.h>
#include "linkQueue.h"

LinkQueue *createLinkQueue(const char *name) {
    LinkQueue *queue = malloc(sizeof(LinkQueue));
    if (queue == NULL) {
        fprintf(stderr, "Error allocating memory for LinkQueue\n");
        return NULL;
    }
    queue->name = name;
    queue->front = queue->rear = NULL;
    queue->cnt = 0;

    return queue;
}

void releaseLinkQueue(LinkQueue* queue) {
    if (queue) {
        QueNode *node;
        while (queue->front) {
            node = queue->front;
            queue->front = queue->front->next;
            free(node);
            queue->cnt--;
        }
        printf("LinkQueue has %d node\n",queue->cnt);
        free(queue);
    }
}

int enLinkQueue(LinkQueue *queue,Element e) {
    QueNode *node = malloc(sizeof(QueNode));
    if (node ==NULL) {
        fprintf(stderr, "Error allocating memory for Queue element\n");
        return -1;
    }
    //先处理新节点
    node->data = e;
    node->next = NULL;
    if (queue->rear) {
        queue->rear->next = node;
        queue->rear = node;
    }else {
        queue->rear = queue->front = node;
    }
    queue->cnt++;
    return 0;
}

int deLinkQueue(LinkQueue *queue, Element *e) {
    if (queue->front ==NULL) {
        fprintf(stderr, "LinkQueue is empty\n");
        return -1;
    }
    *e = queue->front->data;
    QueNode *tmp = queue->front;
    queue->front = queue->front->next;
    free(tmp);
    queue->cnt--;
     return 0;
}
