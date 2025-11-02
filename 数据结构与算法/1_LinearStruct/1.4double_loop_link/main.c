//
// Created by ASUS on 25-7-1.
//
#include <stdio.h>
#include "doubleList.h"

DList stu_table;

int main() {
    initDList(&stu_table);
    for (int i=0; i<5; ++i) {
        insertDListRear(&stu_table, i+100);
    }
    insertDListHeader(&stu_table, 60);
    insertDListRear(&stu_table, 70);
    showDList(&stu_table);
    printf("==========");
    delDList(&stu_table, 102);
    showDList(&stu_table);
    releaseDList(&stu_table);
    printf("num: %d\n", stu_table.val);
    showDList(&stu_table);
    return 0;
}