//
// Created by Daniel Akimchuk on 11/8/16.
//

#ifndef INC_220TERMPROJECT_LINKEDLIST_H
#define INC_220TERMPROJECT_LINKEDLIST_H

#include <stdexcept>
#include<string>
#include "List.h"
#include "LinkedNode.h"


template <class ItemType>
class LinkedList : public List<ItemType> {
private:
    LinkedNode<ItemType>* start;
    LinkedNode<ItemType>* end;
    int totalLinesRun = 0;

    void clearList(LinkedNode<ItemType>* start);
    int findLast(ItemType& itemToFind, LinkedNode<ItemType>* start, int index);

public:
    //creates an empty LinkedList
    LinkedList();

    //Destructor
    ~LinkedList();

    //appends the new item to the end of the list
    void addToEnd(ItemType& itemToAdd);

    //inserts the item at the front of the list
    void addToFront(ItemType& itemToAdd);

    //inserts the new item into the list at the specified index
    //if the index is invalid (< 0 or > currItemCount), throws an out_of_range exception
    void add(ItemType& itemToAdd, int index);

    //returns a copy of the item at index
    //if the index is invalid, throws an out_of_range exception
    ItemType& get(int index);

    //removes the item at index from the list, then returns a copy of that item
    //if the index is invalid, throws an out_of_range exception
    ItemType remove(int index);

    //returns true if there are no valid items in the list, false otherwise
    bool isEmpty();

    //returns the number of valid items in the list
    int size();

    //makes the list entirely empty of valid items (does not change totalLinesRun)
    void clearList();

    //returns the index of the first occurrence of itemToFind in the list, or -1 if not present
    int find(ItemType& itemToFind);

    //returns the index of the last occurrence of itemToFind in the list, or -1 if not present
    int findLast(ItemType& itemToFind);

    //returns the total number of lines run by this object
    long getTotalLinesRun();

    //resets the value of totalLinesRun to 0
    void resetTotalLinesRun();

    //returns the minimum size of the object in bytes
    int calcSizeOf();
};

#include "LinkedList.cpp"


#endif //INC_220TERMPROJECT_LINKEDLIST_H
