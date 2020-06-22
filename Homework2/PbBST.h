/*
 * Title: Binary Search Trees
 * Author: Bartu Atabek
 * ID: 21602229
 * Section: 2
 * Assignment: 2
 * Description: Header file containing the templates for the
 * Binary search tree functions
 */

#ifndef PbBST_h
#define PbBST_h

#include "PbTreeNode.h"
#include "PbBST.h"

class BinarySearchTree {
public:
    BinarySearchTree();
    BinarySearchTree(TreeNode *node);
    ~BinarySearchTree();
    
    void destroy(TreeNode *node);
    
    void insert(int key);
    void insertItemHelper(TreeNode *&node, const int &key);
    
    void deleteKey(int key);
    void deleteKeyHelper(TreeNode *&node, int key);
    void deleteNodeItem(TreeNode *&node);
    void inorderSuccessor(TreeNode *&node, int &key);
    
    int getHeight();
    int getHeightHelper(TreeNode *node);
    
    double medianOfBST();
    int countNodes(TreeNode *node);
    double findkthElement(TreeNode * node, int k);
    
    void rangeSearch(int a, int b);
    void rangeHelper(TreeNode *node, int a, int b);

private:
    TreeNode *root;
    
};
#endif /* PbBST_h */
