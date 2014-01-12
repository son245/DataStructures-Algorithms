#include <iostream>
#include <queue>
#include "binarytree.h"

using namespace std;


struct BTNode* CreateNode(int data)
{
	struct BTNode* newNode = new (struct BTNode);
	newNode->data = data;
	newNode-> left = NULL;
	newNode-> right = NULL;
	return newNode;
}
 
void PreOrder(struct BTNode *root){
	if(root){
		cout << root->data;//process data
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void InOrder(struct BTNode *root){
	if(root){
		InOrder(root->left);
		cout << root-> data;//process
		InOrder(root->right);
	}
}

void PostOrder(struct BTNode *root){
	if(root){
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->data;
	}
}

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

int main()
{
	struct BTNode* root = CreateNode(0);
	struct BTNode* lc = CreateNode(1);
	struct BTNode* rc = CreateNode(5);
	root->left = lc;
	root->right = rc;
	struct BTNode* lcr = CreateNode(3);
	lc->right = lcr;
	LevelOrder(root);
	cout <<"\n 	Max is: ";
	cout << FindMax(root)<<endl;
	return 0;
}


