/*
 * Title: Binary Search Trees
 * Author: Bartu Atabek
 * ID: 21602229
 * Section: 2
 * Assignment: 2
 * Description: Cpp file containing the implementations for the
 * Tree node class
 */

#include "PbTreeNode.h"

// default constructor
TreeNode::TreeNode() :key(0), left(NULL), right(NULL) {
    
}

// constructor
TreeNode::TreeNode(const int &nodeItem, TreeNode *leftPtr, TreeNode *rightPtr) :key(nodeItem), left(leftPtr), right(rightPtr) {
    
}

// copy constructor
TreeNode::TreeNode(const TreeNode &node) :key(node.key), left(node.left), right(node.right) {
    
}
