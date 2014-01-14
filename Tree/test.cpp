#include <iostream>
#include "binarytree.h"

using namespace std;

int main()
{
	struct BTNode* root = CreateNode(1);
	InsertElement(root, 2);
	InsertElement(root, 3);
	InsertElement(root, 4);
	InsertElement(root, 5);
	InsertElement(root, 6);
	InsertElement(root, 7);


/*	struct BTNode* lc = CreateNode(1);
	struct BTNode* rc = CreateNode(5);
	root->left = lc;
	root->right = rc;
	struct BTNode* lcr = CreateNode(3);
	lc->right = lcr;
*/	
//	InsertElement(root, 4);
	LevelOrderReverse(root);
	cout << "\n";
	LevelOrder(root);
	cout << "Max is: ";
	cout << FindMax(root)<<endl;
	cout << "Size is: "<< FindSize(root)<<endl;
	cout << "Height is: "<< FindHeightBinaryTree(root)<<endl;
	return 0;
}