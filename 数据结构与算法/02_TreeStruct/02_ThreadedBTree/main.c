//线索化二叉树
// Created by ASUS on 25-8-22.
//
#include "threadedBTree.h"
#include <stdio.h>

ThreadedBTree *setupTree() {
    BTNode *nodeA = createBTNode('A');
    BTNode *nodeB = createBTNode('B');
    BTNode *nodeC = createBTNode('C');
    BTNode *nodeD = createBTNode('D');
    BTNode *nodeE = createBTNode('E');
    BTNode *nodeF = createBTNode('F');
    BTNode *nodeH = createBTNode('H');
    BTNode *nodeG = createBTNode('G');
    BTNode *nodeK = createBTNode('K');

    ThreadedBTree *tree = createThreadedBTree(nodeA);
    insertThreadedBTree(tree, nodeA, nodeB, nodeE);
    insertThreadedBTree(tree, nodeB, NULL, nodeC);
    insertThreadedBTree(tree, nodeE, NULL, nodeF);
    insertThreadedBTree(tree, nodeC, nodeD, NULL);
    insertThreadedBTree(tree, nodeF, nodeG, NULL);
    insertThreadedBTree(tree, nodeG, nodeH, nodeK);

    return tree;
}

void test01() {
    ThreadedBTree *tree = setupTree();
    printf("tree node: %d\n", tree->count);
    inOrderThreadingBTree(tree);
    printf("show: ");
    InOrderThreadedBTree(tree);
    releaseThreadedBTree(tree);
}

int main() {
    test01();

    return 0;
}