//
// Created by Erika Rumbold on 12/3/16.
//

#ifndef INC_220TERMPROJECT_QUEUE_H
#define INC_220TERMPROJECT_QUEUE_H

template <class ItemType>
class Queue {

public:
    virtual ~Queue(){}
    virtual void enqueue(ItemType item)=0;
    virtual ItemType dequeue()=0;
    virtual bool isEmpty()=0;
};

#endif //INC_220TERMPROJECT_QUEUE_H
