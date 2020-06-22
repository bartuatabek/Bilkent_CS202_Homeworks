/*
 * Title : Heaps and AVL Trees
 * Author: Bartu Atabek
 * ID: 21602229
 * Section: 2
 * Assignment: 3
 * Description: Cpp file containing the implementations for the
 * AVL tree functions
 */

#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

#include "PbTreeNode.h"
#include "AVLTree.h"

// default constrtuctor
AVLTree::AVLTree() :root(NULL), noOfRotations(0) {
    
}

// protected constructor
AVLTree::AVLTree(TreeNode *node) :root(node), noOfRotations(0) {
    
}

// destructor
AVLTree::~AVLTree() {
    destroy(root);
}

// recursive destructor method for deleting the tree
void AVLTree::destroy(TreeNode *node) {
    if (node != NULL) {
        destroy(node->left);
        destroy(node->right);
        delete node;
        node = NULL;
    }
}

// BST insetion method
void AVLTree::insert(int key) {
    root = insertItemHelper(root, key);
}

// helper method for BST insertion
TreeNode* AVLTree::insertItemHelper(TreeNode *&node, const int &key) {
    /* 1.  Perform the normal BST insertion */
    if (!node) {
        node = new TreeNode(key, NULL, NULL);
        return(node);
    }
    
    if (key < node->key)
        node->left  = insertItemHelper(node->left, key);
    else if (key > node->key)
        node->right = insertItemHelper(node->right, key);
    else // Equal keys are not allowed in BST
        return node;
    
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    
    /* 3. Get the balance factor of this ancestor
     node to check whether this node became
     unbalanced */
    int balance = getBalance(node);
    
    // If this node becomes unbalanced, then
    // there are 4 cases
    
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return r_rotation(node);
    
    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return l_rotation(node);
    
    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left =  l_rotation(node->left);
        return r_rotation(node);
    }
    
    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = r_rotation(node->right);
        return l_rotation(node);
    }
    
    // return the (unchanged) node pointer
    return node;
}

// height of AVL tree
int AVLTree::getHeight(TreeNode *node) {
    if (node == NULL)
        return 0;
    
    int left = getHeight(node->left);
    int right = getHeight(node->right);
    
    return 1 + max(left, right);
}

// Get Balance factor of node N
int AVLTree::getBalance(TreeNode *node) {
    if (!node)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// function for getting the no of rotations
int AVLTree::getNumberOfRotations() {
    return noOfRotations;
}

// Case 1: Right Rotation
TreeNode* AVLTree::r_rotation(TreeNode *node) {
    TreeNode *x = node->left;
    TreeNode *T2 = x->right;
    
    // Perform rotation
    x->right = node;
    node->left = T2;
    
    // Update heights
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    
    // Return new root
    noOfRotations++;
    return x;
}

// Case 2: Left Rotation
TreeNode* AVLTree::l_rotation(TreeNode *node) {
    TreeNode *y = node->right;
    TreeNode *T2 = y->left;
    
    // Perform rotation
    y->left = node;
    node->right = T2;
    
    //  Update heights
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    
    // Return new root
    noOfRotations++;
    return y;
}

