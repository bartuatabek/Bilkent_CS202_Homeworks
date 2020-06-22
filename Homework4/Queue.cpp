/*
 * Title: Hashing and Graphs
 * Author: Bartu Atabek
 * ID: 21602229
 * Section: 2
 * Assignment: 4
 * Description: Cpp file containing the implementation for the
 * queue data structure with its functions.
* Taken from the CS 201 slides
 */

#include <iostream>
#include <string>
using namespace std;

#include "Queue.h"
#include "LinkedList.h"

// default constructor
Queue::Queue() : backPtr(NULL), frontPtr(NULL) {

}

// copy constructor
Queue::Queue(const Queue& Q) {
}

Queue::~Queue() {
    while (!isEmpty())
        dequeue();
}

bool Queue::isEmpty() const {
    return backPtr == NULL;
}

bool Queue::enqueue(List *newItem){
    // create a new node
    QueueNode *newPtr = new QueueNode;
    
    // set data portion of new node
    newPtr->item = *newItem;
    newPtr->next = NULL;
    
    // insert the new node
    if (isEmpty())   // insertion into empty queue
        frontPtr = newPtr;
    else             // insertion into nonempty queue
        backPtr->next = newPtr;
    
    backPtr = newPtr;  // new node is at back
    return true;
}

bool Queue::dequeue() {
    if (isEmpty())
        return false;
    
    else {
        // queue is not empty; remove front
        QueueNode *tempPtr = frontPtr;
        
        if (frontPtr == backPtr) {   // special case
            frontPtr = NULL;
            backPtr = NULL;
        }
        else
            frontPtr = frontPtr->next;
        
        tempPtr->next = NULL;  // defensive strategy
        delete tempPtr;
        return true;
    }
}

bool Queue::dequeue(List& queueFront) {
    if (isEmpty())
        return false;
    
    else {
        // queue is not empty; retrieve front
        queueFront = frontPtr->item;
        dequeue();  // delete front
        return true;
    }
}

bool Queue::getFront(List& queueFront)const {
    if (isEmpty())
        return false;
    
    else {
        // queue is not empty; retrieve front
        queueFront = frontPtr->item;
        return true;
    }
}
