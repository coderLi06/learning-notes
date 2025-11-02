//
// Created by ASUS on 25-8-22.
//
#include <stdio.h>
#include <stdlib.h>
#include "threadedBTree.h"


ThreadedBTree * createThreadedBTree(BTNode *root) {
    ThreadedBTree *tree = malloc(sizeof(ThreadedBTree));
    if (tree == NULL) {
        fprintf(stderr,"Error allocating threaded btree\n");
        return NULL;
    }
    if (root) {
        tree->root = root;
        tree->count = 1;
    }else {
        tree->root = NULL;
        tree->count = 0;
    }
    return tree;
}

BTNode * createBTNode(Element e) {
    BTNode *node = malloc(sizeof(BTNode));
    if (node == NULL) {
        fprintf(stderr,"Error allocating BTNode\n");
        return NULL;
    }
    node->data = e;
    node->left = node->right = NULL;
    node->lTag = node->rTag = 0;
    return node;
}

static freeBTNode(ThreadedBTree *tree, BTNode *node) {
    if (node) {
        if (node->lTag == 0) freeBTNode(tree, node->left);
        if (node->rTag == 0) freeBTNode(tree, node->right);
        //如果Tag为0，说明没有前驱节点，可以删除指向的节点
        free(node);
        tree->count--;
    }
}

void releaseThreadedBTree(ThreadedBTree *tree) {
    if (tree->root) freeBTNode(tree,tree->root);
}

void insertThreadedBTree(ThreadedBTree *tree, BTNode *parent, BTNode *left, BTNode *right) {
    if (tree && parent) {
        parent->left = left;
        parent->right = right;
    }
    if (left) tree->count++;
    if (right) tree->count++;
}//假定原来有parent节点，插入的是left和right节点
void visitThreadedBTnode(const BTNode *node) {
    if (node) printf("\t%c", node->data &0xff);
}

static BTNode *pre = NULL;

static void inOrderThreading(BTNode *node) {
    if (node) {
        inOrderThreading(node->left);
        if (node->left == NULL) {
            node->lTag = 1;
            node->left = pre;
        }
        if (pre && pre->right ==NULL) {
            pre->right = node;
            pre->rTag = 1;
        }
        pre = node;
        inOrderThreading(node->right);
    }
}

void inOrderThreadingBTree(ThreadedBTree *tree) {
    if (tree) inOrderThreading(tree->root);
}

void InOrderThreadedBTree(ThreadedBTree *tree) {
    BTNode *node = tree->root;
    while (node) {
        while (node->lTag == 0) node = node->left;
        visitThreadedBTnode(node);
        while (node->rTag) {
            node = node->right;
            visitThreadedBTnode(node);
        }
    }
    node = node->right;
}








