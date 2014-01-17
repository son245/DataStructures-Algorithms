#ifndef BINARYTREE_H
#define BINARYTREE_H
class BinaryTreeNode{
public:
	int data;
	//left pointer
	BinaryTreeNode *left;
	//right pointer
	BinaryTreeNode *right;
	//pointer to parent
	BinaryTreeNode *parent;
	//Null constructor	
	BinaryTreeNode();
	//constructor with data
	BinaryTreeNode(int data);
	//delete the tree node	
	~BinaryTreeNode();
	//set left pointer
	void setLeft(BinaryTreeNode* node);
	//set right pointer
	void setRight(BinaryTreeNode* node);
};

class BinaryTree{
public:
	BinaryTreeNode *root;
	BinaryTree();
	BinaryTree(int rootValue);
	~BinaryTree();
};

void InsertElement(BinaryTree *root, int data);
void PreOrder(BinaryTreeNode *root);
void InOrder(BinaryTreeNode *root);
void PostOrder(BinaryTreeNode *root);
void LevelOrder(BinaryTreeNode *root);	
void LevelOrderReverse(BinaryTreeNode *root);
int FindSize(BinaryTreeNode* root);
int FindMax(BinaryTreeNode* root);
void DeleteBinaryTree(BinaryTreeNode *root);
#endif