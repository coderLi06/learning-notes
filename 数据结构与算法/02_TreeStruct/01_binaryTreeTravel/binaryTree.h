//
// Created by ASUS on 25-8-12.
//

#ifndef BINARY_TREE_H
#define BINARY_TREE_H
//二叉树节点结构
typedef int Element;
typedef struct _tree_node{
    Element data;
    struct _tree_node *left;
    struct _tree_node *right;
}TreeNode;

//树头部分
typedef struct {
    TreeNode *root;
    int count;
}BinaryTree;

//造树和释放树
BinaryTree *createBinaryTree(TreeNode *root);
void releaseBinaryTree(BinaryTree *tree);

//
TreeNode *createTreeNode(Element e);
void insertBinaryTree(BinaryTree *tree, TreeNode *parent, TreeNode *left, TreeNode *right);
void visitTreeNode(const TreeNode *node);

void preOrderBTree(const BinaryTree *tree);
void inOrderBTree(const BinaryTree *tree);
void postOrderBTree(const BinaryTree *tree);
void levelOrderBtree(const BinaryTree *tree);

void preOrderBtreeNoRecursion(const BinaryTree *tree);
void inOrderBtreeNoRecursion(const BinaryTree *tree);
#endif //BINARY_TREE_H
