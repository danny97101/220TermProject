//
// Created by Erika Rumbold on 12/3/16.
// Queue.h
// An ADT for a Queue data structure. Implemented here so the current
// implementation using a LinkedQueue for waitList can easily be switched.

#ifndef INC_220TERMPROJECT_QUEUE_H
#define INC_220TERMPROJECT_QUEUE_H

template <class ItemType>
class Queue {

public:
    /**
     * Destructor
     */
    virtual ~Queue(){}
    /**
     * Adds item to the end of the queue.
     * @param item item to be added to the queue
     */
    virtual void enqueue(ItemType item)=0;
    /**
     * Removes the item at the front of the queue
     * @return the item that was removed
     */
    virtual ItemType dequeue()=0;
    /**
     * Checks if the queue is empty.
     * @return true if the queue is empty, false otherwise.
     */
    virtual bool isEmpty()=0;
};

#endif //INC_220TERMPROJECT_QUEUE_H
