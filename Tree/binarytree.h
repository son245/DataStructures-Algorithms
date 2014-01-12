#ifndef BINARYTREE_H
#define BINARYTREE_H

struct BTNode{
	int data;
	struct BTNode *left;
	struct BTNode *right;
};

void LevelOrder(struct BTNode *root);
struct BTNode* CreateNode(int data);

#endif 