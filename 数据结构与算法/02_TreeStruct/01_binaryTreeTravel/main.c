//
// Created by ASUS on 25-8-12.
//
#include <stdio.h>
#include "binaryTree.h"
BinaryTree *initTree() {
    TreeNode *nodeA = createTreeNode('A');
    TreeNode *nodeB = createTreeNode('B');
    TreeNode *nodeC = createTreeNode('C');
    TreeNode *nodeD = createTreeNode('D');
    TreeNode *nodeE = createTreeNode('E');
    TreeNode *nodeF = createTreeNode('F');
    TreeNode *nodeG = createTreeNode('G');
    TreeNode *nodeH = createTreeNode('H');
    TreeNode *nodeK = createTreeNode('K');

    BinaryTree *tree = createBinaryTree(nodeA);
    insertBinaryTree(tree, nodeA, nodeB, nodeE);
    insertBinaryTree(tree, nodeB, NULL, nodeC);
    insertBinaryTree(tree, nodeE, NULL, nodeF);
    insertBinaryTree(tree, nodeC, nodeD, NULL);
    insertBinaryTree(tree, nodeF, nodeG, NULL);
    insertBinaryTree(tree, nodeG, nodeH, nodeK);
    return tree;
}

void test01() {
    BinaryTree *tree = initTree();
    printf("tree count: %d\n", tree->count);
    printf("PreOrder travel: ");
    preOrderBTree(tree);
    printf("inOrder travel: ");
    inOrderBTree(tree);
    printf("postOrder travel: ");
    postOrderBTree(tree);
    printf("LevelOrder travel: ");
    levelOrderBtree(tree);
}

void test02() {
    BinaryTree *tree = initTree();
    printf("tree count: %d\n", tree->count);
    printf("NoRecursion preOrder travel: ");
    preOrderBtreeNoRecursion(tree);
    printf("\n");
    printf("NoRecursion inOrder travel: ");
    inOrderBtreeNoRecursion(tree);
    printf("\n");

}

int main() {
    test02();

    return 0;
}