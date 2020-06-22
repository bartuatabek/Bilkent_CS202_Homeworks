/*
 * Title : Heaps and AVL Trees
 * Author: Bartu Atabek
 * ID: 21602229
 * Section: 2
 * Assignment: 3
 * Description: Main function for testing the functionality of the code
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "MaxHeap.h"

int main(int argc, const char * argv[]) {

    int size = 0;
    int i;

    ifstream file("/Users/bartu/Desktop/HW\#3/HW\#3_3/HW\#3_3/input.txt");

    if (file.is_open()) {
        file >> size;

        MaxHeap heap(size);

        while (file >> i)
            heap.insert(i);

        file.close();
        heap.permutation();
//        int rootitem;
//        heap.display();
//        heap.remove(rootitem);
//        heap.insert(5);
//        heap.display();
    }

    else
        cout << "Unable to open file" << endl;

    return 0;
}
