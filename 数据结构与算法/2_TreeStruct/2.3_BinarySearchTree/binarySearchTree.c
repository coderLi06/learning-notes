//
// Created by ASUS on 25-9-23.
//一个节点度为2，前驱为左边节点的最大值，
//后继为右边节点的最小值（二叉搜索树中序遍历）
#include <stdio.h>
#include <stdlib.h>
#include "binarySearchTree.h"

BSTree* createBSTree(const char* name) {
    BSTree* tree = malloc(sizeof(BSTree));
    if (tree == NULL) {
        return NULL;
    }
    tree->name = name;
    tree->root = NULL;
    tree->count = 0;
    return tree;
}

static BSNode *createBSNode(Element e) {
    BSNode *node = malloc(sizeof(BSNode));
    if (node == NULL) {
        return NULL;
    }
    node->data = e;
    node->left = node->right = NULL;
    return node;
}

static void freeBSNode(BSTree *tree, BSNode *node) {
    if (node) {
        freeBSNode(tree, node->left);
        freeBSNode(tree, node->right);
        free(node);
        tree->count--;
    }
}

void releaseBSTree(BSTree* tree) {
    if (tree) {
        freeBSNode(tree, tree->root);
        free(tree);
    }
}

static BSNode* insertBSNode(BSTree *tree, BSNode *node, Element e) {
    if (node == NULL) {
        tree->count++;
        return createBSNode(e);
    }
    if (e<node->data) {
        node->left = insertBSNode(tree, node->left,e);
    }else if (e>node->data) {
        node->right = insertBSNode(tree,node->right,e);
    }
    return node;
}

void insertBSTree(BSTree* tree, Element e) {
#ifdef RECURSIVE
    tree->root = insertBSNode(tree, tree->root, e);
#else
    BSNode *cur = tree->root;
    BSNode *pre = NULL;
    while (cur) {
        pre = cur;
        if (e < cur->data) cur = cur->left;
        else if (e > cur->data) cur = cur->right;
        else return;
    }//可能插入时数为空或非空
    BSNode *node = createBSNode(e);
    if (pre) {//插入时存在节点
        if (e < pre->data) pre->left = node;
        else if (e > pre->data) pre->right = node;
    }else tree->root = node;
    tree->count++;
#    endif
}

static BSNode *maxValueBSNode(BSNode *node) {
    while (node && node->right) {
        node = node->right;
    }
    return node;
}

static BSNode* deleteBSNode(BSTree* tree, BSNode *node, Element e) {
    if (node == NULL) {
        return NULL;
    }
    if (e<node->data) {
        node->left = deleteBSNode(tree,node->left,e);
    }else if (e>node->data) {
        node->right = deleteBSNode(tree,node->right,e);
    }else {
        BSNode *tmp;
        if (node->left == NULL) {
            tmp = node->right;
            free(node);
            tree->count--;
            return tmp;
        }
        if (node->right == NULL) {
            tmp = node->left;
            free(node);
            tree->count--;
            return tmp;
        }
        tmp = maxValueBSNode(node->left);
        node->data = tmp->data;
        node->left = deleteBSNode(tree,node->left,node->data);
        node->left = deleteBSNode(tree,node->left,node->data);
    }
    return node;
}
//删除右子树的最小值
static void deleteMiniNode(BSNode *node) {
    BSNode *mini = node->right;
    BSNode *pre = node;
    while (mini && mini->left) {
        pre = mini;
        mini = mini->left;
    }
    if (pre != node) {
        pre->left = mini->right;
    }else {
        pre->right = mini->right;
    }
    node->data = mini->data;
    free(mini);
}


void deleteBSTree(BSTree* tree, Element e) {
    #ifdef RECURSIVE
    if (tree) tree->root = deleteBSNode(tree,tree->root,e);
#else
    BSNode *node = tree->root;
    BSNode *pre = NULL;
    while (node) {
        if (e>node->data) {
            pre = node;
            node = node->left;
        }
        else if (e<node->data) {
            pre = node;
            node = node->right;
        }else break;
    }
    if (node == NULL) return;
    BSNode *tmp;
    if (node->left == NULL) tmp = node->right;
    else if (node->right == NULL) tmp = node->left;
    else {
        deleteMiniNode(node);
        --tree->count;
        return;
    }
    if (pre) {
        if (node->data < pre->data) {
            pre->left = tmp;
        }else pre->right = tmp;
    }else tree->root = tmp;
    free(node);
    tree->count--;
#endif
}



void visitBSNode(const BSNode* node) {
    printf("\t%d", node->data);
}

static void inOrderBSNode(const BSNode *node) {
    if (node) {
        inOrderBSNode(node->left);
        visitBSNode(node);
        inOrderBSNode(node->right);
    }
}

void inOrderBSTree(const BSTree* tree) {
    printf("[%s]Tree: ", tree->name);
    inOrderBSNode(tree->root);
    printf("\n");
}

static int heightBSNode(const BSNode* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = heightBSNode(node->left);
    int rightHeight = heightBSNode(node->right);

    if (leftHeight > rightHeight) {
        return ++leftHeight;
    }
    return ++rightHeight;
}

int heightBSTree(const BSTree* tree) {
    return heightBSNode(tree->root);
}

BSNode* searchBSTree(const BSTree* tree, Element e) {
    BSNode* node = tree->root;
    while (node) {
        if (e<node->data) node = node->left;
        else if (e>node->data) node = node->right;
        else return node;
    }
    return NULL;
}