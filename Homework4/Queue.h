/*
 * Title: Hashing and Graphs
 * Author: Bartu Atabek
 * ID: 21602229
 * Section: 2
 * Assignment: 4
 * Description: Header file containing the template for the
 * queue data structure with its functions.
* Taken from the CS 201 slides
 */

#ifndef Queue_h
#define Queue_h

#include <string>
using namespace std;

#include "Queue.h"
#include "LinkedList.h"

class Queue {
public:
    Queue();                     // constructor
    Queue(const Queue& Q);       // copy constructor
    ~Queue();                    // destructor
    
    // Queue operations:
    bool isEmpty() const;
    bool enqueue(List *newItem);
    bool dequeue();
    bool dequeue(List& queueFront);
    bool getFront(List& queueFront) const;
    
private:
    // The queue is implemented as a linked list with one external
    // pointer to the front of the queue and a second external
    // pointer to the back of the queue.
    
    struct QueueNode {
        List item;
        QueueNode *next;
    };
    QueueNode *backPtr;
    QueueNode *frontPtr;
    
    friend class List;
};
#endif /* Queue_h */
