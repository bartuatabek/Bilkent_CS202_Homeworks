/*
 * Title: Binary Search Trees
 * Author: Bartu Atabek
 * ID: 21602229
 * Section: 2
 * Assignment: 2
 * Description: Main function for testing the functionality of the code
 */

#include <iostream>
#include <string>
using namespace std;

#include "PbBST.h"
#include "analysis.h"

int main(int argc, const char * argv[]) {
    
    // creates empty BST
    BinarySearchTree tree;

    // inserts the following values to BST
    tree.insert(40);
    tree.insert(50);
    tree.insert(45);
    tree.insert(30);
    tree.insert(60);
    tree.insert(55);
    tree.insert(20);
    tree.insert(35);
    tree.insert(10);
    tree.insert(25);

    // prints the height of the BST
    cout << "Tree Height: " << tree.getHeight() << endl;
    
    // deletes the following values from the BST
    tree.deleteKey(45);
    tree.deleteKey(50);

    // prints the median of the BST
    cout << "-----------------------------------------" << endl;
    cout << "Median of BST is: " << tree.medianOfBST() << endl;

    // prints the values from the BST ranged btw 15 & 53
    cout << "-----------------------------------------" << endl;
    cout << "Numbers between 15 and 53 are: ";
    tree.rangeSearch(15, 53);
    
    // calling the height analysis function
    cout << "\n" << endl;
    heightAnalysis();
    
    return 0;
}
