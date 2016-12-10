//
// Created by Erika Rumbold on 12/3/16.
// List.h
// An ADT for a List data structure. Implemented here so the current
// implementation using a LinkedList for inventory can easily be switched.
//

#ifndef INC_220TERMPROJECT_LIST_H
#define INC_220TERMPROJECT_LIST_H

#include <string>

template <class ItemType>
class List {

public:
    /**
     * Destructor
     */
    virtual ~List(){}
    /**
     * Adds itemToAdd to the end of the list.
     * @param itemToAdd item to be added to the end of the list.
     */
    virtual void addToEnd(ItemType& itemToAdd)=0;
    /**
     * Adds itemToAdd to index 0 of the list, pushing everything else
     * up an index.
     * @param itemToAdd the item to be added to the front of the list
     */
    virtual void addToFront(ItemType& itemToAdd)=0;
    /**
     * Adds an item to the inputted index of the list, shifting everything
     * after it up an index.
     * @param itemToAdd the item to be added
     * @param index the index where the item should be added
     */
    virtual void add(ItemType& itemToAdd, int index)=0;
    /**
     * Accesses the item saved at the inputted index of the list
     * @param index the index that should be accessed
     * @return a reference to the item at that index of the list.
     */
    virtual ItemType& get(int index)=0;
    /**
     * Removes the item at the specified index of the list. All items after it
     * should be shifted down an index.
     * @param index the index where the item that is going to be removed is stored
     * @return the item that was removed.
     */
    virtual ItemType remove(int index)=0;
    /**
     * Checks if the list is empty.
     * @return true if the list is empty, false otherwise.
     */
    virtual bool isEmpty()=0;
    /**
     * gets the current size of the list
     * @return the number of items in the list.
     */
    virtual int size()=0;
    /**
     * Clears the list.
     */
    virtual void clearList()=0;
    /**
     * finds the first occurrence of itemToFind in the list
     * @param itemToFind the item to be searched for
     * @return the index of the first occurrence of itemToFind in the list.
     * If it is not in the list, return -1.
     */
    virtual int find(ItemType& itemToFind)=0;
    /**
       * finds the last occurrence of itemToFind in the list
       * @param itemToFind the item to be searched for
       * @return the index of the last occurrence of itemToFind in the list.
       * If it is not in the list, return -1.
       */
    virtual int findLast(ItemType& itemToFind)=0;

    virtual long getTotalLinesRun()=0;
    virtual void resetTotalLinesRun()=0;
    virtual int calcSizeOf()=0;
};

#endif //INC_220TERMPROJECT_LIST_H
