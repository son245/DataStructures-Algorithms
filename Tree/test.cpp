#include <iostream>
#include "binarytree.h"

using namespace std;

int main()
{
/*test tree	
				6
		5				9
	3		5				1
*/	

//create root using CreateNode
//inaryTreeNode *root =new BinaryTreeNode(6);
	BinaryTree *tree = new BinaryTree(6);
	InsertElement(tree,5);
	InsertElement(tree,9);
	InsertElement(tree,3);
	InsertElement(tree,5);
	InsertElement(tree,1);
	cout <<"pre order";
	PreOrder(tree->root);
	cout <<"in order";
	InOrder(tree->root);
	cout <<"post order";
	PostOrder(tree->root);
	cout <<"level order";
	LevelOrder(tree->root);
	cout <<"reverse order";
	LevelOrderReverse(tree->root);
	cout << "find Size" << FindSize(tree->root);
	cout << "find max" << FindMax(tree->root);
//insert using level order traversal
/*	
	InsertElement(root, 5);
	InsertElement(root, 9);
	InsertElement(root, 3);
	InsertElement(root, 5);
	InsertElement(root, 1);
*/
/*	create and modify nodes using CreateNode function
	struct BTNode* lc = CreateNode(1);
	struct BTNode* rc = CreateNode(5);
	root->left = lc;
	root->right = rc;
	struct BTNode* lcr = CreateNode(3);
	lc->right = lcr;
*/	
	//testing
/*	LevelOrder(root);
	cout << "Max is: ";
	cout << FindMax(root)<<endl;
	cout << "Size is: "<< FindSize(root)<<endl;
	cout << "Height is: "<< FindHeightBinaryTree(root)<<endl;
*/	return 0;
}