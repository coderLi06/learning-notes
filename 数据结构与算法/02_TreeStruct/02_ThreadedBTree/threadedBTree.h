//
// Created by ASUS on 25-8-22.
//

#ifndef THREADED_BTREE_H
#define THREADED_BTREE_H
typedef int Element;
//树的节点结构
typedef struct treeNode {
    Element data;
    struct treeNode *left;
    struct treeNode *right;
    int lTag;//0表示left指针指向NULL,1表示指向了前驱
    int rTag;
}BTNode;
typedef struct {
    BTNode *root;
    int count;
}ThreadedBTree;

ThreadedBTree *createThreadedBTree(BTNode *root);
BTNode *createBTNode(Element e);
void releaseThreadedBTree(ThreadedBTree *tree);
void insertThreadedBTree(ThreadedBTree *tree, BTNode *parent, BTNode *left, BTNode *right);
void visitThreadedBTnode(const BTNode *node);
void inOrderThreadingBTree(ThreadedBTree *tree);//中序线索化的过程
void InOrderThreadedBTree(ThreadedBTree *tree);//线索化后，遍历树

#endif //THREADED_BTREE_H
