#ifndef BINARYTREE_H
#define BINARYTREE_H

struct BTNode{
	int data;
	struct BTNode *left;
	struct BTNode *right;
};

struct BTNode* CreateNode(int data);
int FindMax(struct BTNode *root);
void LevelOrder(struct BTNode *root);
void InsertElement(struct BTNode *root, int data);
int FindSize(struct BTNode *root);
void LevelOrderReverse(struct BTNode *root);
void DeleteBinaryTree(struct BTNode *root);
int FindHeightBinaryTree(struct BTNode *root);
#endif