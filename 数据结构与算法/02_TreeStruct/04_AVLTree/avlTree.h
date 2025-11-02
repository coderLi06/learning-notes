//平衡二叉树代码
// Created by ASUS on 2025/11/1.
//
#ifndef DATA_STRUCTURE_AVLTREE_H
#define DATA_STRUCTURE_AVLTREE_H

typedef int Element;
// 平衡二叉树的节点结构
typedef struct _avl_node{
    Element data;
    struct _avl_node *left, *right;
    int height;// 当前节点的高度（这个节点左子树的高度和右子树高度的最大值 + 1）
}AVLNode;

// 平衡二叉树的树头结构
typedef struct {
    AVLNode *root;
    int count;
} AVLTree;

AVLTree *createAVLTree();
void releaseAVLTree(AVLTree *tree);
void insertAVLTree(AVLTree *tree, Element data);
void deleteAVLTree(AVLTree *tree, Element e);
void visitAVLNode(const AVLNode *node);
void inOrderAVLTree(AVLTree *tree);
int heightAVLTree(const AVLTree *tree);
#endif //DATA_STRUCTURE_AVLTREE_H
