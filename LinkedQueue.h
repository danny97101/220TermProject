//
// Created by Toby Dragon on 10/24/16.
// LinkedQueue.h
// An implementation of Queue using a Linked structure.
//

#ifndef STACKSANDQUEUES_LINKEDQUEUE_H
#define STACKSANDQUEUES_LINKEDQUEUE_H

#include "LinkedNode.h"
#include "Queue.h"

template <class ItemType>
class LinkedQueue : public Queue<ItemType> {

private:
    //the first node in the queue.
    LinkedNode<ItemType>* first;
    //the last node in the queue.
    LinkedNode<ItemType>* last;


public:
    /**
     * Default constructor.
     * @return A new LinkedQueue. first and last will both be nullptr.
     */
    LinkedQueue();
    /**
     * Copy constructor
     * @param queue the LinekdQueue to copy.
     * @return A copy of queue.
     */
    LinkedQueue(const LinkedQueue<ItemType>& queue);
    /**
     * Destructor.
     */
    ~LinkedQueue();
    /**
     * Override the assignment operator to make a deep copy.
     * @param toCopy the queue to be copied.
     * @return a deep copy of toCopy.
     */
    LinkedQueue<ItemType>& operator=(LinkedQueue<ItemType> toCopy);
    /**
     * Add item to the end of the queue.
     * @param item the item to be added to the end of the queue.
     */
    void enqueue(ItemType item);
    /**
     * Removes the item at the front of the queue. Returns it.
     * @return the item at the front of the queue.
     */
    ItemType dequeue();
    /**
     * Checks if the queue is empty.
     * @return true if the queue is empty, false otherwise.
     */
    bool isEmpty();


};

#include "LinkedQueue.cpp"


#endif //STACKSANDQUEUES_LINKEDQUEUE_H
