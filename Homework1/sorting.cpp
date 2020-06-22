/*
 * Title : Algorithm Efficiency and Sorting
 * Author : Bartu Atabek
 * ID : 21602229
 * Section : 2
 * Assignment : 1
 * Description : Cpp file containing the implementations for the
 * sorting algorithms and perfomance analysis method
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "sorting.h"

/* –––––––––– Selection Sort –––––––––– */
int indexOfLargest(const int *arr, int size, int &compCount) {
    int index = 0;
    for (int curr = 1; curr < size; curr++) {
        if (arr[curr] < arr[index])
            index = curr;
        compCount++; // increment no of comparisons
    }
    return index;
}

void swap(int &x, int &y, int &moveCount) {
    int temp = x; // temp variable x for swapping
    x = y;
    y = temp;
    moveCount += 3; // each swap requires 3 moves
}

void selectionSort(int *arr, int size, int &compCount, int &moveCount) {
    for (int last = size - 1; last >= 1; last--) {
        int largest = indexOfLargest(arr, last+1, compCount);
        swap(arr[largest], arr[last], moveCount);
    }
} // end selectioSort

/* –––––––––– Merge Sort –––––––––– */
void merge( int *arr, int size, int first, int mid, int last, int &compCount, int &moveCount) {
    
    int tempArray[size];     // temporary array
    
    int first1 = first;      // beginning of first subarray
    int last1 = mid;         // end of first subarray
    int first2 = mid + 1;    // beginning of second subarray
    int last2 = last;        // end of second subarray
    int index = first1;      // next available location in tempArray
    
    while ((first1 <= last1) && (first2 <= last2)) {
        compCount++; // increment no of comparisons
        if (arr[first1] > arr[first2]) {
            tempArray[index] = arr[first1];
            moveCount++; // increment no of moves
            ++first1;
        }
        else {
            tempArray[index] = arr[first2];
            moveCount++; // increment no of moves
            ++first2;
        }
        ++index;
    }
    // finish off the first subarray, if necessary
    while (first1 <= last1) {
        tempArray[index] = arr[first1];
        moveCount++; // increment no of moves
        first1++;
        index++;
    }
    
    // finish off the second subarray, if necessary
    while (first2 <= last2) {
        tempArray[index] = arr[first2];
        moveCount++; // increment no of moves
        first2++;
        index++;
    }
    
    // copy the result back into the original array
    for (index = first; index <= last; index++) {
        arr[index] = tempArray[index];
        moveCount++; // increment no of moves
    }
}   // end merge

// wrapper function for merge sort
void mergeSorter(int *arr, int size, int first, int last, int &compCount, int &moveCount) {
    
    if (first < last) {
        
        int mid = (first + last) / 2; // index of midpoint
        
        // divide array into 2 halves
        mergeSorter(arr, size, first, mid, compCount, moveCount);
        mergeSorter(arr, size, mid + 1, last, compCount, moveCount);
        
        // merge the two halves
        merge(arr, size, first, mid, last, compCount, moveCount);
    }
}

void mergeSort( int *arr, int size, int &compCount, int &moveCount) {
    mergeSorter(arr, size, 0, size - 1, compCount, moveCount);
} // end mergesort

/* –––––––––– Quick Sort –––––––––– */
void partition(int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount) {
    
    int pivot = arr[first]; // copy pivot
    moveCount++;
    int lastS1 = first;           // index of last item in S1
    int firstUnknown = first + 1; // index of first item in unknown
    
    // move one item at a time until unknown region is empty
    while (firstUnknown <= last) {
        
        // move item from unknown to proper region
        if (arr[firstUnknown] > pivot) {      // belongs to S1
            
            ++lastS1;
            swap(arr[firstUnknown], arr[lastS1], moveCount);
        }    // else belongs to S2
        compCount++;
        firstUnknown++;
    }
    // place pivot in proper position and mark its location
    swap(arr[first], arr[lastS1], moveCount);
    pivotIndex = lastS1;
}

// wrapper function for quick sort
void quickSorter(int *arr, int first, int last, int &compCount, int &moveCount) {
    int pivotIndex;
    
    if (first < last) {
        
        // create the partition: S1, pivot, S2
        partition(arr, first, last, pivotIndex, compCount, moveCount);
        
        // sort regions S1 and S2
        quickSorter(arr, first, pivotIndex - 1, compCount, moveCount);
        quickSorter(arr, pivotIndex + 1, last, compCount, moveCount);
    }
}

void quickSort(int *arr, int size, int &compCount, int &moveCount) {
    quickSorter(arr, 0, size - 1, compCount, moveCount);
} // end quicksort

/* –––––––––– Perfomance Analysis –––––––––– */
void performanceAnalysis(int size) {
    int *arr1 = new int[size], *arr2 = new int[size], *arr3 = new int[size]; // init 3 arrays of same size
    int compCount1 = 0, compCount2 = 0, compCount3 = 0; // set initial number of comparisons as 0
    int moveCount1 = 0, moveCount2 = 0, moveCount3 = 0; // set initial number of moves as 0
    double duration1 = 0, duration2 = 0, duration3 = 0; // set initial durations as 0
    
    // create three identical arrays with random integers
    for (int i = 0; i < size; i++) {
        arr1[i] =  arr2[i] = arr3[i] = rand() % size + 1;
    }
    
    // find the duration of selection sort for rand intergers
    clock_t startTime = clock();
    selectionSort(arr1, size, compCount1, moveCount1);
    duration1 = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    
    // find the duration of merge sort for rand intergers
    startTime = clock();
    mergeSort(arr2, size, compCount2, moveCount2);
    duration2 = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    
    // find the duration of quick sort for rand intergers
    startTime = clock();
    quickSort(arr3, size, compCount3, moveCount3);
    duration3 = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    
    
    // output the results
    cout << "Performance Analysis for arrays of size " << size << endl;
    cout << "–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;
    cout << "Random integers" << setw(20) << "Elapsed time" << setw(20) << "compCount" << setw(20) << "moveCount" <<endl ;
    cout << "Selection sort" << setw(14) << duration1  << setw(24) << compCount1  << setw(18) << moveCount1 << endl;
    cout << "Merge sort" << setw(18) << duration2  << setw(22) << compCount2  << setw(21) << moveCount2 << endl;
    cout << "Quick sort" << setw(18) << duration3  << setw(23) << compCount3  << setw(20) << moveCount3 << endl;
    
    // reset the values for next iteration
    compCount1 = compCount2 = compCount3 = 0;
    moveCount1 = moveCount2 = moveCount3 = 0;
    duration1 = duration2 = duration3 = 0;
    
    // create arrays with elements in ascending order
    for (int i = 1; i <= size; i++) {
        arr1[i] =  arr2[i] = arr3[i] = i;
    }
    
    // find the duration of selection sort for ascending intergers
    startTime = clock();
    selectionSort(arr1, size,compCount1, moveCount1);
    duration1 = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    
    // find the duration of merge sort for ascending intergers
    startTime = clock();
    mergeSort(arr2, size, compCount2, moveCount2);
    duration2 = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    
    // find the duration of quick sort for ascending intergers
    startTime = clock();
    quickSort(arr3, size, compCount3, moveCount3);
    duration3 = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    
    // output the results
    cout << "–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;
    cout << "Ascending integers" << setw(17) << "Elapsed time" << setw(20) << "compCount" << setw(20) << "moveCount" <<endl ;
    cout << "Selection sort" << setw(14) << duration1  << setw(24) << compCount1  << setw(18) << moveCount1 << endl;
    cout << "Merge sort" << setw(18) << duration2  << setw(22) << compCount2  << setw(21) << moveCount2 << endl;
    cout << "Quick sort" << setw(18) << duration3  << setw(24) << compCount3  << setw(20) << moveCount3 << endl;
    
    // reset the values for next iteration
    compCount1 = compCount2 = compCount3 = 0;
    moveCount1 = moveCount2 = moveCount3 = 0;
    duration1 = duration2 = duration3 = 0;
    
    // create arrays with elements in descending order
    for (int i = size; i > 0; i--) {
        arr1[i] =  arr2[i] = arr3[i] = i;
    }
    
    // find the duration of selection sort for ascending intergers
    startTime = clock();
    selectionSort(arr1, size,compCount1, moveCount1);
    duration1 = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    
    // find the duration of merge sort for ascending intergers
    startTime = clock();
    mergeSort(arr2, size, compCount2, moveCount2);
    duration2 = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    
    // find the duration of quick sort for ascending intergers
    startTime = clock();
    quickSort(arr3, size, compCount3, moveCount3);
    duration3 = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    
    // output the results
    cout << "–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;
    cout << "Descending integers" << setw(16) << "Elapsed time" << setw(20) << "compCount" << setw(20) << "moveCount" <<endl ;
    cout << "Selection sort" << setw(14) << duration1  << setw(24) << compCount1  << setw(18) << moveCount1 << endl;
    cout << "Merge sort" << setw(18) << duration2  << setw(22) << compCount2  << setw(21) << moveCount2 << endl;
    cout << "Quick sort" << setw(18) << duration3  << setw(24) << compCount3  << setw(20) << moveCount3 << endl;
    
    // reset the values for next iteration
    compCount1 = compCount2 = compCount3 = 0;
    moveCount1 = moveCount2 = moveCount3 = 0;
    duration1 = duration2 = duration3 = 0;
    
    // create arrays with half of elements in ascending order
    for (int i = 0; i < size / 2; i++) {
        arr1[i] =  arr2[i] = arr3[i] = i;
    }
    
    // create arrays with half of elements in descending order
    for (int i = size; i > size / 2; i--) {
        arr1[i] =  arr2[i] = arr3[i] = i;
    }
    
    // find the duration of selection sort for ascending intergers
    startTime = clock();
    selectionSort(arr1, size,compCount1, moveCount1);
    duration1 = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    
    // find the duration of merge sort for ascending intergers
    startTime = clock();
    mergeSort(arr2, size, compCount2, moveCount2);
    duration2 = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    
    // find the duration of quick sort for ascending intergers
    startTime = clock();
    quickSort(arr3, size, compCount3, moveCount3);
    duration3 = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    
    // output the results
    cout << "–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––" << endl;
    cout << "Mixed integers" << setw(21) << "Elapsed time" << setw(20) << "compCount" << setw(20) << "moveCount" <<endl ;
    cout << "Selection sort" << setw(14) << duration1  << setw(24) << compCount1  << setw(18) << moveCount1 << endl;
    cout << "Merge sort" << setw(18) << duration2  << setw(22) << compCount2  << setw(21) << moveCount2 << endl;
    cout << "Quick sort" << setw(18) << duration3  << setw(24) << compCount3  << setw(20) << moveCount3 << endl;
    
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;
} // end performanceAnalysis

