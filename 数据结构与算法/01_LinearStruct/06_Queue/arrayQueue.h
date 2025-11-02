//
// Created by ASUS on 25-8-8.
//

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H
typedef int Element;
#define MaxQueueSize 5
typedef struct {
    Element data[MaxQueueSize];
    int front;
    int rear;
}ArrayQueue;

void initArrayQueue(ArrayQueue *queue);

int enArrayQueue(ArrayQueue *queue, Element e);
int deArrayQueue(ArrayQueue *queue, Element *e);//这里的解引用*

#endif //ARRAY_QUEUE_H
