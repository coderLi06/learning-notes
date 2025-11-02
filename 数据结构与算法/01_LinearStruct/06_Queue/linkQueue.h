//
// Created by ASUS on 25-8-8.
//

#ifndef LINK_QUEUE_H
#define LINK_QUEUE_H
typedef int Element;
typedef struct _node {
    Element data;
    struct _node *next;
}QueNode;
typedef struct {
    QueNode *rear;
    QueNode *front;
    int cnt;
    const char *name;
}LinkQueue;
LinkQueue *createLinkQueue(const char *name);
void releaseLinkQueue(LinkQueue *queue);

int enLinkQueue(LinkQueue *queue, Element e);
int deLinkQueue(LinkQueue *queue, Element *e);

#endif //LINK_QUEUE_H
