/*
 * Title: Binary Search Trees
 * Author: Bartu Atabek
 * ID: 21602229
 * Section: 2
 * Assignment: 2
 * Description: Cpp file containing the implementations for the
 * height analysis function
 */

#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>
using namespace std;

#include "analysis.h"
#include "PbBST.h"

/* –––––––––– Height Analysis –––––––––– */
void heightAnalysis() {
    
    BinarySearchTree tree;
    int size = 20000;
    
    int *arr = new int[size];
    
    cout << "Part d - Analysis of BST height - part 1" << endl;
    cout << "-----------------------------------------" << endl;
    printf("%-10s %-10s \n", "Tree Size", "Tree Height");
    cout << "-----------------------------------------" << endl;
    
    // create array with random integers
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size;
        tree.insert(arr[i]);
        
        if ((i + 1) % 1000 == 0) {
            printf("%-10d %-10d \n", i + 1, tree.getHeight());
        }
    }
    
    for (int i = size - 1; i > 0; i--) {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);
        
        // Swap arr[i] with the element at random index
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    cout << "\n\nPart d - Analysis of BST height - part 2" << endl;
    cout << "-----------------------------------------" << endl;
    printf("%-10s %-10s \n", "Tree Size", "Tree Height");
    cout << "-----------------------------------------" << endl;
    
    for (int i = 0; i < size; i++) {
        tree.deleteKey(arr[i]);
        
        if ((i+1) % 1000 == 0) {
            printf("%-10d %-10d \n", size-(i+1), tree.getHeight());
        }
    }
    
    delete [] arr;
}
