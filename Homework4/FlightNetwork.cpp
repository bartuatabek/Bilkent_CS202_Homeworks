/*
 * Title: Hashing and Graphs
 * Author: Bartu Atabek
 * ID: 21602229
 * Section: 2
 * Assignment: 4
 * Description: Cpp file containing the implementations for the
 * flight network class and its functions.
 */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "FlightNetwork.h"
#include "Queue.h"
#include "LinkedList.h"

// constructor
FlightNetwork::FlightNetwork() {
    ifstream file("/home/cs/bartu.atabek/HW#1/routes.csv");
    
    if (!file.is_open()) {
        cout << "File not found!" << endl;
    }
    
    string source, destination, airline;
    int hashVal;
    
    size = 3409;
    adjList = new FlightNode *[size];
    
    while (getline(file, airline, ',')) {
        getline(file, source, ',');
        getline(file, destination, file.widen('\n'));
        
        FlightNode *destinationNode = new FlightNode;
        destinationNode->airport = destination;
        hashVal = hash(source, size);
        
        // if the index is empty instert directly
        if (adjList[hashVal] == NULL) {
            FlightNode *sourceNode = new FlightNode;
            sourceNode->airport = source;
            destinationNode->next = NULL;
            sourceNode->next = destinationNode;
            adjList[hashVal] = sourceNode;
        }
        
        else {
            if (adjList[hashVal]->airport == source) {
                FlightNode *temp = adjList[hashVal]->next;
                FlightNode *prev = NULL;
                
                bool exists = false;
                while (temp) {
                    if (temp->airport == destination) {
                        exists = true;
                        break;
                    }
                    prev = temp;
                    temp = temp->next;
                }
                
                if (!exists) {
                    destinationNode->next = NULL;
                    prev->next = destinationNode;
                }
            }
            
            else {
                while (adjList[hashVal] && adjList[hashVal]->airport != source) {
                    hashVal++;
                    hashVal %= size;
                }
                
                if (adjList[hashVal] == NULL) {
                    FlightNode *newFromNode = new FlightNode;
                    
                    newFromNode->airport = source;
                    destinationNode->next = NULL;
                    newFromNode->next = destinationNode;
                    adjList[hashVal] = newFromNode;
                }
                else {
                    FlightNode *temp = adjList[hashVal]->next;
                    FlightNode *prev = NULL;
                    
                    bool exists = false;
                    while (temp) {
                        if (temp->airport == destination) {
                            exists = true;
                            break;
                        }
                        prev = temp;
                        temp = temp->next;
                    }
                    
                    if (!exists) {
                        destinationNode->next = NULL;
                        prev->next = destinationNode;
                    }
                }
            }
        }
    }
    
    file.close();
}

// checks if there are any direct flights from airport A to airport B
bool FlightNetwork::directFlightExists(string source, string destination) {
    for (int i = 0; i < size; i++) {
        if (adjList[i]->airport == source) {
            FlightNode *temp = adjList[i]->next;
            while(temp) {
                if(temp->airport == destination) {
                    return true;
                }
                temp = temp->next;
            }
            delete temp;
            break;
        }
    }
    return false;
}

// depth first traversal function
bool FlightNetwork::dft(int vertex, string destination, bool visited[]) {
    visited[vertex] = true;
    
    if (adjList[vertex]->airport == destination)
        return true;
    
    FlightNode *temp = (adjList[vertex])->next;
    
    bool exists = false;
    while (temp) {
        int i = hash(temp->airport, size);
        
        while (adjList[i]->airport != temp->airport) {
            i++;
            i %= size;
        }
        
        if(!visited[i])
            exists = (exists || dft(i, destination, visited));
        
        if(exists)
            break;
        temp = temp->next;
    }
    return exists;
}


// finds and prints all airports which are directly accessible from airport A
void FlightNetwork::printAccessibleAirports(string airport) {
    for (int i = 0; i < size; i++) {
        if (adjList[i]->airport == airport) {
            FlightNode *temp = adjList[i]->next;
            while (temp) {
                cout << temp->airport << endl;
                temp = temp->next;
            }
            delete temp;
            break;
        }
    }
}

// checks if there are any flight paths from airport A to airport B
bool FlightNetwork::flightPathExists(string source, string destination) {
    int vertex = hash(source, size);
    
    while (adjList[vertex]->airport != source) {
        vertex++;
        vertex %= size;
    }
    
    bool *visited = new bool[size];
    
    for (int i = 0; i < size; i++)
        visited[i] = false;
    
    return dft(vertex, destination, visited);
}

// finds and prints the flight path from airport A to airport B with the minimum number of stops
void FlightNetwork::printMinFlightPath(string source, string destination) {
    if (flightPathExists(source, destination)) {
        Queue queue;
        List path;
        
        path.insert(1, source);
        queue.enqueue(&path);
        
        while (!queue.isEmpty()) {
            List currentPath;
            queue.dequeue(currentPath);
            
            string v;
            currentPath.retrieve(currentPath.size, v);
            
            if (v == destination) {
                string tmp;
                for (int i = 1; i <= currentPath.size; i++) {
                    currentPath.retrieve(i, tmp);
                    cout << tmp << "->";
                }
                return;
            }
            
            for (int i = 0; i < size; i++) {
                if (adjList[i]->airport == v) {
                    FlightNode *u = adjList[i]->next;
                    while (u != NULL) {
                        if (!currentPath.contains(u->airport)) {
                            List newPath = currentPath;
                            newPath.insert(1, u->airport);
                            queue.enqueue(&newPath);
                        }
                        u = u->next;
                    }
                }
            }
        }
    }
    else
        cout << "There's no flight path between these destinations" << endl;
}

// finds and prints all of the flight paths with n or lower number of stops from airport A to airport B
void FlightNetwork::printFlightPathWithNStops(string source, string destination, int n) {
    if (flightPathExists(source, destination)) {
        Queue queue;
        List path;
        
        path.insert(1, source);
        queue.enqueue(&path);
        
        while (!queue.isEmpty()) {
            List currentPath;
            queue.dequeue(currentPath);
            
            string v;
            currentPath.retrieve(currentPath.size, v);
            
            if (v == destination) {
                string tmp;
                for (int i = 1; i <= currentPath.size; i++) {
                    currentPath.retrieve(i, tmp);
                    cout << tmp << "->";
                }
            }
            
            for (int i = 0; i < size; i++) {
                if (adjList[i]->airport == v) {
                    FlightNode *u = adjList[i]->next;
                    while (u != NULL) {
                        if (!currentPath.contains(u->airport) && currentPath.getLength() <= n) {
                            List newPath = currentPath;
                            newPath.insert(1, u->airport);
                            queue.enqueue(&newPath);
                        }
                        u = u->next;
                    }
                }
            }
        }
    }
    else
        cout << "There's no flight path between these destinations" << endl;
}

int FlightNetwork::hash(const string &key, int tableSize) {
    int hashVal = 0;
    
    for (int i = 0; i < key.length(); i++)
        hashVal = 37 * hashVal + key[i];
    
    hashVal %=tableSize;
    
    if (hashVal < 0)   /* in case overflows occurs */
        hashVal += tableSize;
    
    return hashVal;
}
