/*
 * Title: Binary Search Trees
 * Author: Bartu Atabek
 * ID: 21602229
 * Section: 2
 * Assignment: 2
 * Description: Header file containing the templates for the
 * Tree node class
 */

#ifndef PbTreeNode_h
#define PbTreeNode_h

#include <string>
#include "PbTreeNode.h"

class TreeNode {     // a node in the tree
private:
    TreeNode();
    TreeNode(const int &nodeItem, TreeNode *left = NULL, TreeNode *right = NULL);
    TreeNode(const TreeNode &node);
    
    int key;           // a data item in the tree
    TreeNode *left;    // pointers to children
    TreeNode *right;
    
    // friend class - can access private parts
    friend class BinarySearchTree;
};
#endif /* PbTreeNode_h */
