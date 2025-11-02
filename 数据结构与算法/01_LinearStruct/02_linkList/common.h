//
// Created by ASUS on 25-6-8.
//

#ifndef COMMON_H
#define COMMON_H
typedef int Element_t;
//定义链表的节点结构
typedef struct _node {
    Element_t val;
    struct _node *next;
}node_t;
#endif //COMMON_H
