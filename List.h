//
// Created by Erika Rumbold on 12/3/16.
//

#ifndef INC_220TERMPROJECT_LIST_H
#define INC_220TERMPROJECT_LIST_H

#include <string>

template <class ItemType>
class List {

public:
    virtual ~List(){}
    virtual void addToEnd(ItemType& itemToAdd)=0;
    virtual void addToFront(ItemType& itemToAdd)=0;
    virtual void add(ItemType& itemToAdd, int index)=0;
    virtual ItemType& get(int index)=0;
    virtual ItemType remove(int index)=0;
    virtual bool isEmpty()=0;
    virtual int size()=0;
    virtual void clearList()=0;
    virtual int find(ItemType& itemToFind)=0;
    virtual int findLast(ItemType& itemToFind)=0;
    virtual long getTotalLinesRun()=0;
    virtual void resetTotalLinesRun()=0;
    virtual int calcSizeOf()=0;
};

#endif //INC_220TERMPROJECT_LIST_H
