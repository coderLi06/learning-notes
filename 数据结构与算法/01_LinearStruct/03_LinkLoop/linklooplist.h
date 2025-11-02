//
// Created by ASUS on 25-6-22.
//

#ifndef LINK_LOOP_LIST_H
#define LINK_LOOP_LIST_H
//定义节点结构
typedef int Element;
typedef struct _loop_node{
Element val;
    struct _loop_node *next;
}LoopNode;
//定义单向循环链表的头结构
typedef struct {
    LoopNode header;
    LoopNode *rear;
    int num;
}LinkLoopList;
//初始化接口
void initLinkLoopList(LinkLoopList *link_loop);
//插入（头插、尾插）
int insertLinkLoopHeader(LinkLoopList *link_loop, Element val);
int insertLinkLoopRear(LinkLoopList *link_loop, Element value);;
//遍历显示
void showLinkLoopList(const LinkLoopList *link_loop);
//删除
int deleteLinkLoopList(LinkLoopList *link_loop, Element val);
//释放整个数据域，不释放头
void destroyLinkLoopList(LinkLoopList *link_loop);
#endif //LINK_LOOP_LIST_H
