#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include <iostream>
using std::cout, std::endl;

/*
 * Queue class
 * All Nodes will point to the Node above
 */
template<typename Object>
class Queue {
private:
    Node<Object>* back;
    Node<Object>* front;

public:
    // Constructor
    Queue() {
        // Start with an empty Queue
        back = nullptr;
        front = nullptr;
    }

    // De-constructor aka destructor
    // This method will automatically be called
    // at the end of the lifetime of the object
    ~Queue() {
        // Make sure no heap allocation
        while (front != nullptr) {
            dequeue();
        }
        cout << "No memory leaks!" << endl;
    }

    // enqueue (add a value to the Queue)
    void enqueue(Object item) {
        // Store the item in a Node in heap memory
        Node<Object>* newNodePtr = new Node<Object>(item);

       if (front == nullptr && back == nullptr) {
           front = newNodePtr;
           back = newNodePtr;
       }

        // Have the new Node point to back
        back->setNext(newNodePtr);
        // The new Node becomes back
        back = newNodePtr;

    }

    // dequeue (remove a value from the Queue)
    // Returns the value being dequeued
    Object dequeue() {
        // Check that there is a Node to dequeue
        if (front == nullptr) {
            // The Queue is empty
            return Object();
        }

        // Create a copy of the value to be returned
        Object item = front->getItem();
        // Store a copy of front
        Node<Object>* frontCopy = front;
        // Update front
        front = front->getNext();
        // Delete the Node from heap memory
        delete frontCopy;
        // Return the value being dequeued
        return item;
    }

    // Search for an item in the Queue
    // Return true if the item is in the Queue
    // Return false otherwise
    bool search(Object item) const {
        Node<Object>* frontCopy = back;
        while (frontCopy != nullptr) {
            if (frontCopy->getItem() == item) {
                return true;
            }
            frontCopy = frontCopy->getNext();
        }
        return false;
    }

    // Print (list all the values in the Stack)
    void print() const {
        cout << "Front of Queue" << endl;
        Node<Object>* frontCopy = front;
        while (frontCopy != nullptr) {
            cout << frontCopy->getItem() << endl;
            frontCopy = frontCopy->getNext();
        }
        cout << "Back of Queue" << endl;
    }
};

#endif
