//
// Created by ASUS on 25-8-8.
//
#include <stdio.h>
#include "arrayQueue.h"
#include "linkQueue.h"

void test01() {
    ArrayQueue stu1;
    initArrayQueue(&stu1);
    for (int i = 0; i < 4; i++) {
        enArrayQueue(&stu1, i);
    }
    enArrayQueue(&stu1, 4);

    printf("Que1 show:");
    Element x1;
    while ((deArrayQueue(&stu1, &x1)) != -1) {
        printf("%d", x1);
    }
}

void test02() {
    LinkQueue *queue = createLinkQueue("stu1");
    if (queue ==NULL) {
        return;
    }
    for (int i = 0; i < 5; ++i) {
        enLinkQueue(queue, i);
    }
    Element x1;
    while ((deLinkQueue(queue, &x1)) != -1) {
        printf("%d", x1);
    }
    releaseLinkQueue(queue);
}

int main() {
    test01();
    test02();
}