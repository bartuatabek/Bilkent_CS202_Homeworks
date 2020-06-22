/*
 * Title: Hashing and Graphs
 * Author: Bartu Atabek
 * ID: 21602229
 * Section: 2
 * Assignment: 4
 * Description: Main function for testing the functionality of the code
 */

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

#include "FlightNetwork.h"

int main(int argc, const char * argv[]) {
    FlightNetwork network;
    
    if (argc == 1)
        cout << ("No Extra Command Line Argument Passed Other Than Program Name") << endl;
    
    if (argc >= 2) {
        if (strcmp(argv[1], "a") == 0) {
            cout << network.directFlightExists(argv[2], argv[3]) << endl;
        }
        
        else if (strcmp(argv[1], "b") == 0) {
            network.printAccessibleAirports(argv[2]);
        }
        
        else if (strcmp(argv[1], "c") == 0) {
            cout << network.flightPathExists(argv[2], argv[3]) << endl;
        }
        
        else if (strcmp(argv[1], "d") == 0) {
            network.printMinFlightPath(argv[2], argv[3]);
        }
        
        else if (strcmp(argv[1], "e") == 0) {
            network.printFlightPathWithNStops(argv[2], argv[3], atoi(argv[4]));
        }
    }
    return 0;
}
