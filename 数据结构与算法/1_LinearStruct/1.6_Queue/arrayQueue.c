//数组实现顺序队列（循环队列），防止假溢出
//循环队列需要空一个位置，
// Created by ASUS on 25-8
#include <stdio.h>
#include "arrayQueue.h"

void initArrayQueue(ArrayQueue* queue) {
    queue->front = queue->rear = 0;
}

int enArrayQueue(ArrayQueue *queue, Element e) {
    //rear指向最后一个代表队满
    if ((queue->rear + 1)%MaxQueueSize == queue->front) {
        fprintf(stderr, "Queue is full\n");
        return -1;
    }
    //rear指向最后一个元素，先更新位置
    queue->rear = (queue->rear + 1)%MaxQueueSize;
    queue->data[queue->rear] = e;
    return 0;
}

int deArrayQueue(ArrayQueue *queue, Element *e) {
    if ((queue->rear == queue->front)) {
        fprintf(stderr, "Queue is empty\n");
        return -1;
    }
    queue->front = (queue->front + 1)%MaxQueueSize;
    *e = queue->data[queue->front];
    return 0;
}
