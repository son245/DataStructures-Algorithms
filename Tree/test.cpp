#include <iostream>
#include "binarytree.h"

using namespace std;

int main()
{
	struct BTNode* root = CreateNode(0);
	struct BTNode* lc = CreateNode(1);
	struct BTNode* rc = CreateNode(5);
	root->left = lc;
	root->right = rc;
	struct BTNode* lcr = CreateNode(3);
	lc->right = lcr;
	InsertElement(root, 4);
	LevelOrder(root);
	cout << "Max is: ";
	cout << FindMax(root)<<endl;
	return 0;
}