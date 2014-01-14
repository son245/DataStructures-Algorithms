#include <iostream>
#include "binarytree.h"

using namespace std;

int main()
{
/*	
			6
		5		9
	3		5		1
*/	

	//create root using CreateNode
	struct BTNode* root = CreateNode(6);
	//insert using level order traversal
	InsertElement(root, 5);
	InsertElement(root, 9);
	InsertElement(root, 3);
	InsertElement(root, 5);
	InsertElement(root, 1);

/*	create and modify nodes using CreateNode function
	struct BTNode* lc = CreateNode(1);
	struct BTNode* rc = CreateNode(5);
	root->left = lc;
	root->right = rc;
	struct BTNode* lcr = CreateNode(3);
	lc->right = lcr;
*/	
	//testing
	LevelOrder(root);
	cout << "Max is: ";
	cout << FindMax(root)<<endl;
	cout << "Size is: "<< FindSize(root)<<endl;
	cout << "Height is: "<< FindHeightBinaryTree(root)<<endl;
	return 0;
}