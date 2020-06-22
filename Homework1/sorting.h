/*
 * Title : Algorithm Efficiency and Sorting
 * Author : Bartu Atabek
 * ID : 21602229
 * Section : 2
 * Assignment : 1
 * Description : Header file containing the templates for the
 * sorting algorithms and perfomance analysis method
 */

#ifndef sorting_h
#define sorting_h

#include <string>
using namespace std;

// template for selection sort functions
int indexOfLargest(const int *arr, int size, int &compCount);
void swap(int &x, int &y, int &moveCount);
void selectionSort(int* arr, int size, int &compCount, int &moveCount);

// template for merge sort functions
void merge( int* arr, int size, int first, int mid, int last, int &compCount, int &moveCount);
void mergeSorter(int* arr, int size, int first, int last, int &compCount, int &moveCount);
void mergeSort(int* arr, int size, int &compCount, int &moveCount);

// template for quick sort functions
void partition(int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount);
void quickSorter(int *arr, int first, int last, int &compCount, int &moveCount);
void quickSort(int* arr, int size, int &compCount, int &moveCount);

// template for performance analysis
void performanceAnalysis(int size);

#endif /* sorting_h */
