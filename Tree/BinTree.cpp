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

    #include "BinTree.h"

    #define NULL 0

    /*
     * BinTreeNode class
     */

    // Constructors and destructor
    //   The destructor calls delete on its left and right branches, leading to
    //   recursive deletion of the entire subtree.
    BinTreeNode::BinTreeNode(){
       data = NULL;
       parent = NULL;
       left = NULL;
       right = NULL;
    }
    BinTreeNode::BinTreeNode(int val){
       data = val;
       parent = NULL;
       left = NULL;
       right = NULL;
    }
    BinTreeNode::~BinTreeNode(){
       delete left;
       delete right;
    }

    // Setters and getters are implemented in BinTree.h

    /*
     * End BinTreeode class
     */


    /*
     * BinTree class
     */

    // Constructor and destructor
    BinTree::BinTree(){
       root = new BinTreeNode();
    }
    BinTree::BinTree(int rootVal){
       root = new BinTreeNode(rootVal);
    }
    BinTree::~BinTree(){
       delete root;
    }

    // setRoot and getRoot implemented in BinTree.h

    /*
     * End BinTree class
     */

    /*

     * Additional helper methods
     */

    // Deletes left and right branches of node
    void prune(BinTreeNode* node){
       delete node->getLeft();
       node->setLeft(NULL);
       delete node->getRight();
       node->setRight(NULL);
    }