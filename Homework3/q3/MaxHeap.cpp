/*
 * Title : Heaps and AVL Trees
 * Author: Bartu Atabek
 * ID: 21602229
 * Section: 2
 * Assignment: 3
 * Description: Cpp file containing the implementations for the
 * Max Heap
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#include "MaxHeap.h"

// default constructor
MaxHeap::MaxHeap(int size) :size(size), counter(0), noOfSwaps(0) {
    items = new int[size];
}

// copy constructor
MaxHeap::MaxHeap(const MaxHeap &heap) :size(heap.size), counter(heap.counter), noOfSwaps(heap.noOfSwaps) {
    if (size > 0) {
        items = new int[size];
        for (int i = 0; i < size; i++)
            items[i] = heap.items[i];
    }
}

// destructor
MaxHeap::~MaxHeap() {
    delete [] items;
}

// function for checking whether the heap is empty or not
bool MaxHeap::isEmpty() const {
    return (size == 0);
}

// instert function for the heap
void MaxHeap::insert(const int& newItem)  {
    
    if (size == counter)
        cout << "Heap is full!" << endl;
    
    // Place the new item at the end of the heap
    items[counter] = newItem;
    
    // Trickle new item up to its proper position
    int place = counter;
    int parent = (place - 1) / 2;
    
    while (place > 0 && items[place] > items[parent]) {
        int temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;
        
        place = parent;
        parent = (place - 1) / 2;
    }
    counter++;
}

// delete function for the heap
void MaxHeap::remove(int &rootItem) {
    if (isEmpty()){
        cout << "Heap is empty!" << endl;
        return;
    }
    
    else {
        rootItem = items[0];
        items[0] = items[size - 1];
        counter--;
        heapRebuild(0);
    }
}

// heap rebuild function
void MaxHeap::heapRebuild(int root) {
    int child = 2 * root + 1;     // index of root's left child, if any
    if (child < size) {
        // root is not a leaf so that it has a left child
        int rightChild = child + 1;     // index of a right child, if any
        // If root has right child, find larger child
        if ((rightChild < size) && (items[rightChild] >items[child]))
            child = rightChild;     // index of larger child
        
        // If root’s item is smaller than larger child, swap values
        if (items[root] < items[child]) {
            int temp = items[root];
            items[root] = items[child];
            items[child] = temp;
            noOfSwaps++;
            // transform the new subtree into a heap
            heapRebuild(child);
        }
    }
}

void MaxHeap::permutation() {
    int count = 0;
    int noOfSwaps = 0;
    permutationHelper(size/2 + 1, size, count, noOfSwaps);
    
    cout << "The total number of swaps is " << noOfSwaps <<  "." << endl;
    double result = double(noOfSwaps) / double(count);
    cout << "The average number of swaps per permutation is " << result <<  "." << endl;
    
    if (result * 10 < 20)
        cout << "Taking 20 TL is a better option" << endl;
    else
        cout << "10 TL per swap is a better option" << endl;
}

void MaxHeap::permutationHelper(int curr, int size, int &count, int &noOfSwaps) {
        if (curr == size) {
//            for (int i = size/2; i < size; i++)
//                cout << items[i] << "\t";
//            cout << endl;
            for (int index = size/2 - 1; index >= 0; index--) {
                MaxHeap heap(*this);
                heap.heapRebuild(index);
                noOfSwaps += heap.noOfSwaps;
            }
            count++;
        }
    
        else {
            for (int i = curr - 1; i < size; i++){
                swap(i, curr - 1);
                permutationHelper(curr + 1, size, count, noOfSwaps);
                swap(i, curr - 1);
            }
        }
    }
    
    void MaxHeap::swap(int first, int second) {
        int temp = items[first];
        items[first] = items[second];
        items[second] = temp;
        return;
    }
    
    void MaxHeap::display() {
        for (int i = 0; i < size; i++)
            cout << items[i] << " ";
        cout << endl;
    }
    
