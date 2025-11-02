//
// Created by ASUS on 2025/11/1.
//
#include <stdio.h>
#include <stdlib.h>
#include "avlTree.h"
#include <time.h>

AVLTree* createAVLTree() {
    AVLTree* tree = malloc(sizeof(AVLTree));
    if (tree == NULL) {
        printf("Memory allocation failed");
        return NULL;
    }
    tree->count = 0;
    tree->root = NULL;

    return tree;
}

void visitAVLNode(const AVLNode* node) {
    if (node) {
        printf("\t<%d:%d>", node->data, node->height);
    }
}

static void inOrderNode(AVLNode *node) {
    if (node) {
        inOrderNode(node->left);
        visitAVLNode(node);
        inOrderNode(node->right);
    }
}

void inOrderAVLTree(AVLTree* tree) {
    if (tree) {
        inOrderNode(tree->root);
        printf("\n");
    }
}

int heightAVLTree(const AVLTree* tree) {
    if (tree) {
        return tree->root->height;
    }
    return 0;
}
static int maxNum(int a, int b) {
    return (a > b) ? a : b;
}
static int h(const AVLNode *node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

/* 左旋操作
 *     px
 *     |
 *     x
 *   /  \
 * lx    y
 *      / \
 *     ly ry
 * */

static AVLNode *leftRotate(AVLNode *x){
    AVLNode *y = x->right;
    x->right = y->left;
    y->left = x;

    x->height = maxNum(h(x->left), h(x->right)) + 1;
    y->height = maxNum(h(y->left), h(y->right)) + 1;
    return y;
}

/* 右旋操作
 *       py
 *       |
 *       y
 *     /  \
 *    x   ry
 *   / \
 * lx  rx
 * */
static AVLNode *rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    y->left = x->right;
    x->right = y;

    y->height = maxNum(h(y->left), h(y->right)) + 1;
    x->height = maxNum(h(x->left), h(x->right)) + 1;
    return x;
}

static int getBalance(const AVLNode *node) {
    if (node == NULL) {
        return 0;
    }
    return h(node->left) - h(node->right);
}

static AVLNode *createAVLNode(Element data) {
    AVLNode *node = malloc(sizeof(AVLNode));
    if (node == NULL) {
        printf("Memory allocation failed");
        return NULL;
    }
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

//把向树中插入节点，采用递归的方式，分为两层，
// 第一层传入一般节点，递归遍历树中节点找到插入元素位置
//第二层在树中插入元素转换为用根节点作为一般节点
//以达到遍历树中节点的目的
static AVLNode *insertAVLNode(AVLTree *tree,  AVLNode *node, Element e) {
    // 1. 递归的初始化位置
    if (node == NULL) {
        tree->count++;
        return createAVLNode(e);
    }
    // 1.1 递的过程
    if (e < node->data) {
        node->left = insertAVLNode(tree, node->left, e);
    }
    else if (e > node->data) {
        node->right = insertAVLNode(tree, node->right, e);
    } else {
        return node;
    }
    // 2. 运行到这里的代码，已经进入到归的过程，更新这条路径上节点高度，同时监测平衡因子
    // 2.1 归过程中的节点高度的更新
    node->height = maxNum(h(node->right), h(node->left)) + 1;
    // 2.2 计算机当前节点的平衡因子
    int balance = getBalance(node);
    if (balance > 1) {
        // 失衡点子节点是L还是R，LL or LR
        if (e > node->left->data) {
            // LR
            node->left = leftRotate(node->left);
        }
        // LL
        return rightRotate(node);
    }
    if (balance < -1) {
        if (e < node->right->data) {
            // RL
            node->right = rightRotate(node->right);
        }
        // RR
        return leftRotate(node);
    }
    return node;
}

void insertAVLTree(AVLTree* tree, Element data) {
    if (tree) {
        tree->root = insertAVLNode(tree, tree->root, data);
    }
}
static AVLNode *deleteAVLNode(AVLTree *tree, AVLNode *node, Element e) {
    if (node == NULL) {
        return NULL;
    }
    // 1. 找到要删除的节点
    if (e < node->data) {
        node->left = deleteAVLNode(tree, node->left, e);
    } else if (e > node->data) {
        node->right = deleteAVLNode(tree, node->right, e);
    } else {
        // 找到了e值的元素
        AVLNode *tmp;
        if (node->left == NULL || node->right == NULL) {
            tmp = node->left ? node->left : node->right;
            if (tmp == NULL){
                // 度为0，直接删除
                tree->count--;
                free(node);
                return NULL;
            }
            // 度为1，将tmp的值直接替换成node
            node->data = tmp->data;
            node->left = tmp->left;
            node->right = tmp->right;
            tree->count--;
            free(tmp);
        }
        else {
            // 度为2的点，找前驱节点
            tmp = node->left;
            while (tmp->right) {
                tmp = tmp->right;
            }
            node->data = tmp->data;
            node->left = deleteAVLNode(tree, node->left, tmp->data);
        }
    }
    // 2. 归的过程中，更新平衡因子
    node->height = 1 + maxNum(h(node->left), h(node->right));
    int balance = getBalance(node);
    if (balance > 1) {
        // L
        if (getBalance(node->left) < 0) {
            // R
            node->left = leftRotate(node->left);
        }
        return rightRotate(node);
    }
    if (balance < -1) {
        if (getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
        }
        return leftRotate(node);
    }
    return node;
}

/* 平衡二叉树中删除元素e
 * 1. 按照二叉搜索树的规则，递归找到元素e的节点
 * 2. 判断度的情况，是否转移矛盾
 * 3. 归的过程中，根据平衡因子进行调整
 */
void deleteAVLTree(AVLTree* tree, Element e) {
    if (tree) {
        tree->root = deleteAVLNode(tree, tree->root, e);
    }
}
