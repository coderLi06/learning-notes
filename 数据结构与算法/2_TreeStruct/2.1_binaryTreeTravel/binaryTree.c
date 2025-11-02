//
// Created by ASUS on 25-8-12.
//
#include "arrayStack.h"
#include "binaryTree.h"
#include <stdio.h>
#include <stdlib.h>


BinaryTree * createBinaryTree(TreeNode *root) {
    BinaryTree * tree = (BinaryTree *)malloc(sizeof(BinaryTree));
    if (tree ==NULL) {
        fprintf(stderr, "Memory allocation failed in createBinaryTree()\n");
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

TreeNode * createTreeNode(Element e) {
    TreeNode * node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = e;
    node->left = node->right = NULL;
    return node;
}

void insertBinaryTree(BinaryTree *tree, TreeNode *parent, TreeNode *left, TreeNode *right) {
    if (tree && parent) {
        parent->left = left;
        parent->right = right;

        if (left) {
            tree->count++;
        }
        if (right) {
            tree->count++;
        }
    }
}

void visitTreeNode(const TreeNode *node) {
    if (node) {
        printf("%d ", node->data);
    }
}

static void preOrderNode(const TreeNode *node) {
    if (node) {
        visitTreeNode(node);
        preOrderNode(node->left);
        preOrderNode(node->right);
    }
}
static void inOrderNode(const TreeNode *node) {
    if (node) {
        inOrderNode(node->left);
        visitTreeNode(node);
        inOrderNode(node->right);
    }
}

static void postOrderNode(const TreeNode *node) {
    if (node) {
        postOrderNode(node->left);
        postOrderNode(node->right);
        visitTreeNode(node);
    }
}

void preOrderBTree(const BinaryTree *tree) {
    preOrderNode(tree->root);
    printf("\n");
}

void inOrderBTree(const BinaryTree *tree) {
    inOrderNode(tree->root);
    printf("\n");
}

void postOrderBTree(const BinaryTree *tree) {
    postOrderNode(tree->root);
    printf("\n");
}


/*广度遍历
 *1.引入一个任务队列，先把根节点入队
 *2.从任务队列中，取出一个根节点，处理他
 *3.如果2步的节点有左就入队，有右就入队
 *4.重复第二步
 */
void levelOrderBTree(const BinaryTree *tree) {
    //申请一个任务队列，用顺序存储，循环队列，队列里每个元素是节点的地址
#define MaxQueueSize 8
    TreeNode* queue[MaxQueueSize];
    int front, rear;

    //初始化系统
    front = rear = 0;
    queue[rear] = tree->root;
    rear = (rear+1) % MaxQueueSize;
}
//开始循环系统处理事务
while (rear != front) {
    TreeNode* node = queue[front];
    front = (front+1)%MaxQueueSize;
    visitTreeNode(node);
    if (node->left) {
        queue[rear] = node->left;
        rear = (rear+1)%MaxQueueSize;
    }
    if (node->right) {
        queue[rear] = node->right;
        rear = (rear+1)%MaxQueueSize;
    }
}
/*非递归实现先序遍历，基本思路：
 *先序的结果是当前节点、再左节点、最后右节点。把栈当做任务的暂存区
 *先压右节点，再压左节点，一旦弹栈，出现的是左节点
 *基本步骤：
 *1.初始化部分
 *将根节点压栈
 *2.循环处理任务部分
 *2.1弹栈，访问弹出来的节点，判断节点有右先压右，有左再压左，保证先右后左
 *2.2循环出栈，直到栈内无元素
 */

void preOrderBtreeNoRecursion(const BinaryTree *tree) {
    ArrayStack stack;
    initArrayStack(&stack);
    pushArrayStack(&stack, tree->root);

    TreeNode *node;
    while (!isEmptyArrayStack(&stack)) {
        node = getTopArrayStack(&stack);
        popArrayStack(&stack);
        visitTreeNode(node);
        if (node->right) {
            pushArrayStack(&stack, node->right);
        }
        if (node->left) {
            pushArrayStack(&stack, node->left);
        }
    }
}

/*以根节点开始，整条左边入栈，从栈中弹出新节点，开始访问
 *如果这个节点有右孩子，把右孩子当做新节点
 *再次整条进栈，再弹栈
 */

void inOrderBtreeNoRecursion(const BinaryTree *tree) {
    ArrayStack stack;
    initArrayStack(&stack);
    //pushArrayStack(&stack, tree->root)
    TreeNode *node = tree->root;

    while (!isEmptyArrayStack(&stack) || node) {
        if (node) {
            pushArrayStack(&stack, node);
            node = node->left;
        } else {
            node = getTopArrayStack(&stack);
            popArrayStack(&stack);
            visitTreeNode(node);
            node = node->right;
        }
    }
}