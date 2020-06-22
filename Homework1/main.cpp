/*
 * Title : Algorithm Efficiency and Sorting
 * Author : Bartu Atabek
 * ID : 21602229
 * Section : 2
 * Assignment : 1
 * Description : Main function containing the  testing of the implementations for the
 * sorting algorithms and perfomance analysis method
 */

#include <string>
#include <iostream>
using namespace std;

#include "sorting.h"

int main(int argc, const char * argv[]) {
    
    /* Performance Analysis Testing */
    cout << "\nPerformance Analysis Testing" << endl;

    performanceAnalysis(1000);
    cout << "\n" << endl;

    performanceAnalysis(6000);
    cout << "\n" << endl;

    performanceAnalysis(12000);
    cout << "\n" << endl;

    performanceAnalysis(18000);
    
    return 0;
}
