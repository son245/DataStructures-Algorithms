#include <iostream>
#include <queue>
#include "binarytree.h"

using namespace std;

//create a new Binary tree node
struct BTNode* CreateNode(int data)
{
	struct BTNode* newNode = new (struct BTNode);
	newNode->data = data;
	newNode-> left = NULL;
	newNode-> right = NULL;
	return newNode;
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

//insert with level order traversal
void InsertElement(struct BTNode *root, int data)
{
	queue<BTNode*> Q;
	struct BTNode *temp;
	struct BTNode *newNode;
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
