/*
 * Title : Heaps and AVL Trees
 * Author: Bartu Atabek
 * ID: 21602229
 * Section: 2
 * Assignment: 3
 * Description: Cpp file containing the implementations for the
 * rotation analysis function
 */

#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>
using namespace std;

#include "analysis.h"
#include "AVLTree.h"

/* –––––––––– Rotation Analysis –––––––––– */
void rotationAnalysis() {
    printf("%-15s %-15s %-15s %-15s \n", "Array Size", "Random", "Ascending", "Descending");
    cout << "----------------------------------------------------------" << endl;
    
    for (int i = 1000; i <= 10000; i+=1000) {
        rotationAnalysisHelper(i);
    }
}

/* –––––––––– Rotation Analysis Helper –––––––––– */
void rotationAnalysisHelper(int size) {
    
    AVLTree tree1;
    AVLTree tree2;
    AVLTree tree3;
    
    int *arr1;
    int *arr2;
    int *arr3;
    
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    
    // create array with random integers
    for (int i = 0; i < size; i++) {
        arr1[i] = rand() % 100000 + 1;
        tree1.insert(arr1[i]);
    }
    
    // create array with ascending integers
    for (int i = 0; i < size; i++) {
        arr2[i] = i + 1;
        tree2.insert(arr2[i]);
    }
    
    // create array with descending integers
    for (int i = size - 1; i >= 0; i--) {
        arr3[i] = i + 1;
        tree3.insert(arr3[i]);
    }
    
    printf("%-16d", size);
    printf("%-16d", tree1.getNumberOfRotations());
    printf("%-16d", tree2.getNumberOfRotations());
    printf("%-16d \n", tree3.getNumberOfRotations());
    
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
}
