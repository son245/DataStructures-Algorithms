/*****
 * Author   : horm
 * Date     : 2009-09-30
 * Sources  : All code is original
 * Purpose  : The BinTree class is an implementation of a Binary Tree structure, containing nodes of class BinTreeNode.
 * Note     : BinTree contains a pointer to a root node 'root' and methods to set and get the root node.
 *           BinTreeNode contains a pointer to its parent and left and right branches, and a integer 'data', as well
 *            methods to access/mutate these members.
 *****/

#pragma once

#define NULL 0;


class BinTreeNode {

public:

   // Constructors and destructor
   //   The destructor calls delete on its left and right branches, leading to
   //   recursive deletion of the entire subtree.
   BinTreeNode();
   BinTreeNode(int val);
   ~BinTreeNode();

   // Set and get data member
   int getData(){   return data; };
   void setData(int val){   data = val; };

   // Set and get left and right branches,
   BinTreeNode* getLeft()   { return left; };
   BinTreeNode* getRight(){ return right; };
   BinTreeNode* getParent(){ return parent; };
   void setLeft(BinTreeNode* node){ left = node; };
   void setRight(BinTreeNode* node){ right = node; };
   void setParent(BinTreeNode* node){   parent = node; };

private:

   int data;
   BinTreeNode *left, *right, *parent;
};

class BinTree {

public:

   // Constructors and destructor
   BinTree();
   BinTree(int rootVal);
   ~BinTree();

   // Set and get root node
   void setRoot(BinTreeNode* node){ root = node; };
   BinTreeNode* getRoot(){ return root; };

private:

   BinTreeNode* root;
};


/*
 * Additional helper methods
 */

// Deletes left and right branches of node
void prune(BinTreeNode* node);