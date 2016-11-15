//
// Created by Toby Dragon on 10/24/16.
//

#ifndef STACKSANDQUEUES_LINKEDQUEUE_H
#define STACKSANDQUEUES_LINKEDQUEUE_H

#include "Queue.h"
#include "LinkedNode.h"

template <class ItemType>
class LinkedQueue : public Queue<ItemType> {

private:
    LinkedNode<ItemType>* first;
    LinkedNode<ItemType>* last;

    int totalLinesRun;

public:
    LinkedQueue();
    ~LinkedQueue();

    void enqueue(ItemType item);
    ItemType dequeue();
    bool isEmpty();

    long getTotalLinesRun();
    void resetTotalLinesRun();
    int calcSizeOf();

};


#endif //STACKSANDQUEUES_LINKEDQUEUE_H
