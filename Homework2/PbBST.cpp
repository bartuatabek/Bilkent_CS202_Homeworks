/*
 * Title: Binary Search Trees
 * Author: Bartu Atabek
 * ID: 21602229
 * Section: 2
 * Assignment: 2
 * Description: Cpp file containing the implementations for the
 * Binary search tree functions
 */

#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

#include "PbTreeNode.h"
#include "PbBST.h"

// default constrtuctor
BinarySearchTree::BinarySearchTree() :root(NULL) {
    
}

// protected constructor
BinarySearchTree::BinarySearchTree(TreeNode *node) :root(node) {
    
}

// destructor
BinarySearchTree::~BinarySearchTree() {
    destroy(root);
}

// recursive destructor method for deleting the tree
void BinarySearchTree::destroy(TreeNode *node) {
    if (node != NULL) {
        destroy(node->left);
        destroy(node->right);
        delete node;
        node = NULL;
    }
}

// BST insetion method
void BinarySearchTree::insert(int key) {
    insertItemHelper(root, key);
}

// helper method for BST insertion
void BinarySearchTree::insertItemHelper(TreeNode *&node, const int &key) {
    // position of insertion found; insert after leaf
    if (node == NULL)
        node = new TreeNode(key, NULL, NULL);
    
    // else search for the insertion position
    else if (key < node->key)
        insertItemHelper(node->left, key);
    else
        insertItemHelper(node->right, key);
}

// BST delete key method for removing the node with the designated key
void BinarySearchTree::deleteKey(int key) {
    deleteKeyHelper(root, key);
}

// helper method for BST node deletion
void BinarySearchTree::deleteKeyHelper(TreeNode *&node, int key) {
    if (node == NULL) // Empty tree
        return;
    
    // Position of deletion found
    else if (key == node->key)
        deleteNodeItem(node);
    
    // Else search for the deletion position
    else if (key < node->key)
        deleteKeyHelper(node->left, key);
    else
        deleteKeyHelper(node->right, key);
}

// deletes the node accordingly wrt to the cases
void BinarySearchTree::deleteNodeItem(TreeNode *&node) {
    TreeNode *delPtr;
    int replacementItem;
    
    // (1) test for a leaf
    if ((node->left == NULL) && (node->right == NULL)) {
        delete node;
        node = NULL;
    }
    
    // (2) test for no left child
    else if (node->left == NULL) {
        delPtr = node;
        node = node->right;
        delPtr->right = NULL;
        delete delPtr;
    }
    
    // (3) test for no right child
    else if (node->right == NULL) {
        delPtr = node;
        node = node->left;
        delPtr->left = NULL;
        delete delPtr;
    }
    
    // (4) there are two children
    else {
        inorderSuccessor(node->right, replacementItem); // retrieve and delete the inorder successor
        node->key = replacementItem;
    }
}

// finds the inorder successor for deletion
void BinarySearchTree::inorderSuccessor(TreeNode *&node, int &key) {
    if (node->left == NULL) {
        key = node->key;
        TreeNode *delPtr = node;
        node = node->right;
        delPtr->right = NULL;
        delete delPtr;
    }
    else
        inorderSuccessor(node->left, key);
}

// method for finding the height of the BST
int BinarySearchTree::getHeight() {
    return getHeightHelper(root);
}

// helper method for finding the height of the BST
int BinarySearchTree::getHeightHelper(TreeNode *node) {
    if (node == NULL)
        return 0;
    
    int left = getHeightHelper(node->left);
    int right = getHeightHelper(node->right);
    
    return 1 + max(left, right);
}

// method for counting the number of nodes in BST
int BinarySearchTree::countNodes(TreeNode *node) {
    if (!node)
        return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

// method for finding the median of numbers in BST
double BinarySearchTree::medianOfBST() {
    if (!root)
        return 0.0;
    
    int count = countNodes(root);
    
    if (count == 1)
        return double(root->key);

    else if (count % 2 == 1)
        return findkthElement(root, (count / 2) + 1);
    
    else
        return (findkthElement(root, count / 2) + findkthElement(root, (count / 2) + 1)) / 2;
}

// recursive method for finding the kth element in BST
double BinarySearchTree::findkthElement(TreeNode *node, int k) {
    if(!node)
        return 0.0;
    
    //count the nodes in left subtree
    int count = countNodes(node->left);
    
    //check if the root is median
    if (k == count + 1)
        return node->key;
    
    //check if median falls on left subtree
    else if (count >= k)
        return findkthElement(node->left, k);
    
    //the median falls on right subtree
    else {
        k = k - (count + 1);
        return findkthElement(node->right, k);
    }
}

// method for printing all the keys which in the given range
void BinarySearchTree::rangeSearch(int a, int b) {
    rangeHelper(root, a, b);
}

// helper method for printing all the keys which in the given range
void BinarySearchTree::rangeHelper(TreeNode *node, int a, int b) {
    // base case
    if (!node)
        return;
    
    if (node->key >= a)
        rangeHelper(node->left, a, b);
    
    // if root's data lies in range, then prints root's data
    if (node->key >= a && node->key <= b)
        printf("%d ", node->key );
    
    // If root->data is smaller than b, then traverse in right subtree
    if (node->key < b)
        rangeHelper(node->right, a, b);
}
