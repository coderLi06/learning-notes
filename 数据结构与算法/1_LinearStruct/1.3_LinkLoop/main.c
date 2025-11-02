//
// Created by ASUS on 25-6-22.
//
#include <stdio.h>
#include "linklooplist.h"

void test01() {
    LinkLoopList table;
    initLinkLoopList(&table);
    for (int i = 0; i < 10; ++i) {
        insertLinkLoopRear(&table, i + 100);
    }
    showLinkLoopList(&table);
    printf("=========");
    deleteLinkLoopList(&table, 106);
    showLinkLoopList(&table);
    destroyLinkLoopList(&table);
}

int main() {
    test01();
    return 0;
}