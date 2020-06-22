/*
 * Title: Hashing and Graphs
 * Author: Bartu Atabek
 * ID: 21602229
 * Section: 2
 * Assignment: 4
 * Description: Header file containing the template for the
 * flight network class and its functions.
 */

#ifndef FlightNetwork_h
#define FlightNetwork_h

#include <string>
using namespace std;

#include "FlightNetwork.h"
#include "LinkedList.h"
#include "Queue.h"

class FlightNetwork {
public:
    FlightNetwork(); 
    
    bool directFlightExists(string source, string destination);
    bool flightPathExists(string source, string destination);
    bool dft(int vertex, string destination, bool visited[]);
    
    void printAccessibleAirports(string airport);
    void printMinFlightPath(string source, string destination);
    void printFlightPathWithNStops(string source, string destination, int n);
    
    int hash(const string &key, int tableSize); // implemented using course slides (hash func. 3)

private:
    struct FlightNode {
        string airport;
        FlightNode *next;
    };
    
    FlightNode **adjList;
    int size;
    
    friend class Queue;
    friend class List;
};
#endif /* FlightNetwork_h */
