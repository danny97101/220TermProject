//
// Created by Toby Dragon on 10/24/16.
//

#ifndef STACKSANDQUEUES_LINKEDQUEUE_H
#define STACKSANDQUEUES_LINKEDQUEUE_H

#include "LinkedNode.h"

template <class ItemType>
class LinkedQueue {

private:
    LinkedNode<ItemType>* first;
    LinkedNode<ItemType>* last;


public:
    LinkedQueue();
    LinkedQueue(const LinkedQueue<ItemType>& queue);
    ~LinkedQueue();
    LinkedQueue<ItemType>& operator=(LinkedQueue<ItemType> toCopy);

    void enqueue(ItemType item);
    ItemType dequeue();
    bool isEmpty();


};

#include "LinkedQueue.cpp"


#endif //STACKSANDQUEUES_LINKEDQUEUE_H
