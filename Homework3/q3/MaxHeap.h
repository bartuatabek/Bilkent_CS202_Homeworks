/*
 * Title : Heaps and AVL Trees
 * Author: Bartu Atabek
 * ID: 21602229
 * Section: 2
 * Assignment: 3
 * Description: Header file containing the templates for the
 * Max Heap
 */

#ifndef MaxHeap_h
#define MaxHeap_h

class MaxHeap {
public:
    MaxHeap(int size);
    MaxHeap(const MaxHeap &heap);
    ~MaxHeap();
    
    bool isEmpty() const;
    void insert(const int& newItem);
    void remove(int& rootItem);

    void permutation();
    void permutationHelper(int curr, int size, int &count, int &noOfSwaps);
    void swap(int first, int second);
    void display();
    
protected:
    void heapRebuild(int root);

private:
    int *items;
    int size;
    int counter;
    int noOfSwaps;
};
#endif /* MaxHeap_h */
