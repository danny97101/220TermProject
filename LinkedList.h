//
// Created by Daniel Akimchuk on 11/8/16.
// LinkedList.h
// This is an implementation of List which uses LinkedNodes for each
// entry of the List. Implements the ADT List.h. Is a template.
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
    //A pointer to the first entry of the list.
    LinkedNode<ItemType>* start;
    //A pointer to the last entry of the list.
    LinkedNode<ItemType>* end;
    int totalLinesRun = 0;
    /**
     * A recursive function that will empty a lislt from start onwards.
     * Should only be called via the stub funciton clearList()
     * @param start The node to start deleting from. Every time
     * the function is called it will be the next node of the list.
     */
    void clearList(LinkedNode<ItemType>* start);
    /**
     * A recursive function that will return the index of the last occurrence of itemToFind
     * Should only be called via the stub function findLast(ItemType itemToFind).
     * @param itemToFind The item that is being searched for
     * @param start The node to start searching at. Each time this is called,
     * this node will increment to the next node.
     * @param index The current last index where the item was found.
     * @return The index of the last occurrence of itemToFind.
     */
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
