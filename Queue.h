//
// Created by Toby Dragon on 10/21/16.
//

#ifndef STACKSANDQUEUES_QUEUE_H
#define STACKSANDQUEUES_QUEUE_H

template <class ItemType>
class Queue {
public:
    //virtual destructor that forces desctructor calls to also call child destructors
    virtual ~Queue(){};

    //adds an item to the end of the queue
    virtual void enqueue(ItemType item)=0;

    //takes an item off the front of the queue
    //throws out_of_range exception if the queue is empty
    virtual ItemType dequeue()=0;

    //returns true if the stack has no items, false otherwise
    virtual bool isEmpty() = 0;

    //returns the total number of lines run by this object
    virtual long getTotalLinesRun() = 0;

    //resets the value of totalLinesRun to 0
    virtual void resetTotalLinesRun() = 0;

    //returns the minimum size of the object in bytes
    virtual int calcSizeOf() = 0;

};


#endif //STACKSANDQUEUES_QUEUE_H
