#include <iostream>
#include <binarytree.h>

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