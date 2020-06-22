/*
 * Title : Heaps and AVL Trees
 * Author: Bartu Atabek
 * ID: 21602229
 * Section: 2
 * Assignment: 3
 * Description: Header file containing the templates for the
 * AVL tree functions
 */

#ifndef AVLTree_h
#define AVLTree_h

#include "PbTreeNode.h"
#include "AVLTree.h"

class AVLTree {
public:
    AVLTree();
    AVLTree(TreeNode *node);
    ~AVLTree();
    
    void destroy(TreeNode *node);
    
    void insert(int key);
    TreeNode* insertItemHelper(TreeNode *&node, const int &key);
    
    int getHeight(TreeNode *node);
    int getBalance(TreeNode *node);
    int getNumberOfRotations();
    
    TreeNode* r_rotation(TreeNode *node);
    TreeNode* l_rotation(TreeNode *node);

private:
    TreeNode *root;
    int noOfRotations;
    
};
#endif /* AVLTree_h */
