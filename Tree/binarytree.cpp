#include <iostream>
#include <queue>
#include <stack>
#include <stdlib.h>
#include "binarytree.h"

using namespace std;

//create a new Binary tree node
BinaryTreeNode::BinaryTreeNode(){
	parent = NULL;
	left = NULL;
	right = NULL;
}
//create node with value
BinaryTreeNode::BinaryTreeNode(int value){
	data = value;
	parent = NULL;
	left = NULL;
	right = NULL;
}
//delete node
BinaryTreeNode::~BinaryTreeNode(){
	delete left;
	delete right;
}
BinaryTree::BinaryTree(){
	root = new BinaryTreeNode();
}
BinaryTree::BinaryTree(int rootValue){
	root = new BinaryTreeNode(rootValue);
}
BinaryTree::~BinaryTree(){
	delete root;
}
void InsertElement(BinaryTree *tree, int data){
	//the Q holding all the nodes, starting with the root node
	queue<BinaryTreeNode*> Q;
	BinaryTreeNode *temp;
	BinaryTreeNode *newNode = new BinaryTreeNode(data);
	Q.push(tree->root);
	while(!Q.empty()){
		temp = Q.front();
		if(temp->left){
			Q.push(temp->left);
		}
		else{
			temp->left = newNode;
			return;
		}
		if(temp->right){
			Q.push(temp->right);
		}
		else{
			temp->right = newNode; 
			return;
		}
		Q.pop();
	}
	return;
}

//using pre-order traversal
void PreOrder(BinaryTreeNode *root){
	if(root){
		cout << root->data;
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

//in order traversal
void InOrder(BinaryTreeNode *root){
	if(root){
		InOrder(root->left);
		cout << root->data;
		InOrder(root->right);
	}
}

//post order traversal
void PostOrder(BinaryTreeNode *root){
	if(root){
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->data;
	}
}

//level order traversal
void LevelOrder(BinaryTreeNode *root){
	queue<BinaryTreeNode*> Q;
	BinaryTreeNode *temp;
	if(root){
		Q.push(root);
	}
	while(!Q.empty()){
		temp = Q.front();
		Q.pop();
		cout << temp-> data;
		if(temp->left){
			Q.push(temp->left);
		}
		if(temp->right){
			Q.push(temp->right);
		}
	}
}

//level order reverse traversal
void LevelOrderReverse(BinaryTreeNode *root){
	queue<BinaryTreeNode*> Q;
	stack<BinaryTreeNode*> S;
	BinaryTreeNode* temp;
	if(root){
		Q.push(root);
	}
	while(!Q.empty()){
		temp = Q.front();
		S.push(temp);
		if(temp->right){
			Q.push(temp->right);
		}
		if(temp->left){
			Q.push(temp->left);
		}
		Q.pop();
	}
	while(!S.empty()){
		temp = S.top();
		cout << temp->data;
		S.pop();
	}
}

//Find the size of the tree
int FindSize(BinaryTreeNode *root){
	if(!root){
		return 0;
	}
	else{
		return FindSize(root->left) + 1 + FindSize(root->right);
	}
}

//Find the max of the tree
int FindMax(BinaryTreeNode *root){
	int root_value, left, right, max = 0;
	if(root!=NULL){
		root_value = root-> data;
		left = FindMax(root->left);
		right = FindMax(root->right);
		if(left > right)
		{
			max = left;
		}
		else{
			max = right;
		}
		if(root_value > max)
		{
			max = root_value;
		}
	}
	return max;
}

//Delete Tree
void DeleteBinaryTree(BinaryTreeNode *root){
	if(root != NULL){
		DeleteBinaryTree(root->left);
		DeleteBinaryTree(root->right);
		root = NULL;
		free(root);
		delete root;
	}
}
/*
struct BTNode{
	int data;
	struct BTnode *left;
	struct BTnode *right;
}

//using pre order traversal
void PreOrder(struct BTNode *root){
	if(root){
		cout << root->data;//process data
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

//using in order travsersal
void InOrder(struct BTNode *root){
	if(root){
		InOrder(root->left);
		cout << root-> data;//process
		InOrder(root->right);
	}
}

//using post order traversal
void PostOrder(struct BTNode *root){
	if(root){
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->data;
	}
}

//traverse using level order
void LevelOrder(struct BTNode *root){
	queue<BTNode*> Q;
	struct BTNode *temp;
	if(root){
		Q.push(root);
	}
	while(!Q.empty()){
		temp = Q.front();
		cout << temp->data;
		Q.pop();
		if(temp->left){
			Q.push(temp->left);
		}
		if(temp->right){
			Q.push(temp->right);
		}
	}
	
}

//printing level order data in reverse order(left-> right, bottom up)
void LevelOrderReverse(struct BTNode *root){
	queue<BTNode*> Q;
	stack<BTNode*> S;
	struct BTNode *temp;
	if(root){
		Q.push(root);
	}
	while(!Q.empty()){
		S.push(Q.front());
		temp = Q.front();
		Q.pop();
		if(temp->right){
			Q.push(temp->right);
		}
		if(temp->left){
			Q.push(temp->left);
		}
	}
	while(!S.empty()){
		temp = S.top();
		cout << temp->data;
		S.pop();
	}
}

//insert with level order traversal
void InsertElement(struct BTNode *root, int data){
	queue<BTNode*> Q;
	struct BTNode *temp;
	struct BTNode* newNode = new (struct BTNode);
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;
	if(root){
		Q.push(root);
	}
	else{
		root = newNode;
		return;
	}
	while(!Q.empty()){
		temp = Q.front();
		if(temp->left){
			Q.push(temp->left);
		}
		else{
			temp->left = newNode;
			return;
		}
		if(temp->right){
			Q.push(temp->right);
		}
		else{
			temp->right = newNode; 
			return;
		}
		Q.pop();
	}
	return;
}

//find the size of the binary tree
int FindSize(struct BTNode *root){
	if(!root){
		return 0;
	}
	else{
		return (FindSize(root->left) + 1 + FindSize(root->right));
	}
}

//find the maximum data of the tree
int FindMax(struct BTNode *root){
	int root_value, left, right, max = 0;
	if(root!=NULL){
		root_value = root-> data;
		left = FindMax(root->left);
		right = FindMax(root->right);
		if(left > right)
		{
			max = left;
		}
		else{
			max = right;
		}
		if(root_value > max)
		{
			max = root_value;
		}
	}
	return max;
}

//delete the tree using post order traversal
//error! not working 
void DeleteBinaryTree(struct BTNode *root){
	if(root != NULL){
	DeleteBinaryTree(root->left);
	DeleteBinaryTree(root->right);
	free(root);
	root = NULL;
	}
}

//find the Height of binary tree
int FindHeightBinaryTree(struct BTNode *root){
	int leftHeight;
	int rightHeight;
	if(root == NULL){
		return 0;
	}
	else{
		leftHeight = FindHeightBinaryTree(root->left);
		rightHeight = FindHeightBinaryTree(root->right);
		if(leftHeight > rightHeight){
			return leftHeight + 1;
		}
		else{
			return rightHeight + 1;
		}
	}
}
*/
//Find the deepest node(inprogress)
/*struct BTNode * FindDeepestNodeBinaryTree(struct BTNode *root){
	queue<BTNode*> Q;
	struct BTNode *temp;
	if(!root){
		return NULL;
	}
	Q.push(root);
	int level = 1;
	while(!Q.empty()){
		temp = Q.front();

	}
}
*/