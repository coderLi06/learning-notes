//
// Created by ASUS on 25-9-23.
//

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
typedef int Element;
// 定义二叉搜索树的节点结构
typedef struct _bs_node {
    Element data;
    struct _bs_node *left;
    struct _bs_node *right;
} BSNode;

// 定义二叉搜索树的头节点
typedef struct {
    BSNode *root;
    int count;
    const char *name;
} BSTree;

BSTree *createBSTree(const char *name);
void releaseBSTree(BSTree *tree);

void insertBSTree(BSTree *tree, Element e);
void deleteBSTree(BSTree *tree, Element e);
void visitBSNode(const BSNode *node);
void inOrderBSTree(const BSTree *tree);

int heightBSTree(const BSTree *tree);

BSNode *searchBSTree(const BSTree *tree, Element e);
#endif //BINARY_SEARCH_TREE_H
