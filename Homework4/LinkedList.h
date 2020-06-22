/*
 * Title: Hashing and Graphs
 * Author: Bartu Atabek
 * ID: 21602229
 * Section: 2
 * Assignment: 4
 * Description: Header file containing the template for the
 * linked list data structure with its functions.
 * Taken from the CS 201 slides
 */

#ifndef LinkedList_h
#define LinkedList_h

#include <string>
using namespace std;

#include "LinkedList.h"

class List {
    
public:
    List();                  // constructor
    List(const List& aList); // copy constructor
    ~List();                 // destructor

    int getLength() const;
    
    bool isEmpty() const;
    bool contains(string str);
    bool retrieve(int index, string& dataItem) const;
    bool insert(int index, string newItem);
    bool remove(int index);

private:
    
    struct ListNode {      // a node on the list
        string item;       // a data item on the list
        ListNode *next;    // pointer to next node
    };
    
    int size;        // number of items in list
    ListNode *head;  // pointer to linked list
    
    ListNode *find(int index) const;
    // Returns a pointer to the index-th node
    // in the linked list
    
    friend class FlightNetwork;
    friend class Queue;
};
#endif /* LinkedList_h */
