//
// Created by Daniel Akimchuk on 11/8/16.
//

#include <iostream>

template <class ItemType>
LinkedList<ItemType>::LinkedList() {
    //start both pointers off as null because list is empty
    totalLinesRun+=2;
    start = nullptr;
    end = nullptr;
}

template <class ItemType>
LinkedList<ItemType>::~LinkedList() {
    totalLinesRun++;
    while (!isEmpty()) {
        //delete all nodes in list
        totalLinesRun+=4;
        LinkedNode<ItemType>* next = start->getNext();
        delete start; //during the last iteration, will also delete end
        start = next; //during the last iteration, start = nullptr
    }
    totalLinesRun++;
    end = nullptr;
}

template <class ItemType>
void LinkedList<ItemType>::addToEnd(ItemType& itemToAdd) {
    totalLinesRun+=2;
    LinkedNode<ItemType>* newNode = new LinkedNode<ItemType>(itemToAdd);
    if (isEmpty()) {
        //when the list is empty, adding to the end is also like adding to the front so start is newNode as well
        totalLinesRun++;
        start = newNode;
    }
    totalLinesRun++;
    if (end != nullptr) {
        //if the list isn't empty, make sure you set the previous end to point to the new end
        totalLinesRun++;
        end->setNext(newNode);
    }
    totalLinesRun++;
    //end now points to the new end
    end = newNode;
}

template <class ItemType>
void LinkedList<ItemType>::addToFront(ItemType& itemToAdd) {
    totalLinesRun+=4;
    LinkedNode<ItemType>* newNode = new LinkedNode<ItemType>(itemToAdd);
    newNode->setNext(start);
    if (isEmpty()) {
        //when the list is empty, adding to the front is also like adding to the end so end is newNode
        totalLinesRun++;
        end = newNode;
    }
    start = newNode;
}

template <class ItemType>
void LinkedList<ItemType>::add(ItemType& itemToAdd, int index) {
    totalLinesRun+=4;
    if (index < 0) {
        totalLinesRun++;
        throw std::out_of_range("Invalid index: can't be less than 0");
    }

    LinkedNode<ItemType>* newNode = new LinkedNode<ItemType>(itemToAdd);
    LinkedNode<ItemType>* nodeAtIndex = start;

    if (index == 0) {
        totalLinesRun++;
        addToFront(itemToAdd);
    } else {
        totalLinesRun+=2;
        for (int i = 0; i < index - 1; i++) {
            totalLinesRun+=4;
            if (nodeAtIndex->getNext() == nullptr) {
                totalLinesRun++;
                throw std::out_of_range("Invalid index: can't be greater than current number of items");
            }
            nodeAtIndex = nodeAtIndex->getNext(); //do this to get to the node at the index where you want to add the newNode
        }
        totalLinesRun+=3;
        LinkedNode<ItemType>* tempNext = nodeAtIndex->getNext(); //store temporarily
        nodeAtIndex->setNext(newNode);
        newNode->setNext(tempNext);
    }
}

template <class ItemType>
ItemType& LinkedList<ItemType>::get(int index) {
    totalLinesRun+=5;
    if (index < 0) {
        totalLinesRun++;
        throw std::out_of_range("Invalid index: can't be less than 0");
    }
    if (isEmpty()) {
        totalLinesRun++;
        throw std::out_of_range("List is empty");
    }

    LinkedNode<ItemType>* nodeAtIndex = start;
    for (int i = 0; i < index; i++) {
        totalLinesRun+=4;
        if (nodeAtIndex->getNext() == nullptr) {
            totalLinesRun++;
            throw std::out_of_range("invalid index: can't be greater than number of items in list");
        }
        nodeAtIndex = nodeAtIndex->getNext();
    }
    totalLinesRun++;
    return nodeAtIndex->getItem();
}

template <class ItemType>
ItemType LinkedList<ItemType>::remove(int index) {
    totalLinesRun+=4;
    if (isEmpty()) {
        totalLinesRun++;
        throw std::out_of_range("List is empty");
    }

    LinkedNode<ItemType>* nodeAtIndex = start;
    int removed;
    if (index < 0) {
        totalLinesRun++;
        throw std::out_of_range("Invalid index: can't be less than 0");
    } else if (index == 0) {
        totalLinesRun+=5;
        LinkedNode<ItemType>* temp = start->getNext();
        if (start == nullptr) {
            totalLinesRun++;
            throw std::out_of_range("Invalid index: must be between 0 and number of current items");
        }
        removed = start->getItem();
        if (size() == 1) {
            totalLinesRun+=2;
            delete end; //deletes start and end because they're the same
            end = temp;
        }
        totalLinesRun++;
        start = temp;
    } else {
        totalLinesRun+=3;
        for (int i = 0; i < index - 1; i++) {
            totalLinesRun+=4;
            nodeAtIndex = nodeAtIndex->getNext();
            if (nodeAtIndex == nullptr) {
                totalLinesRun++;
                throw std::out_of_range("Invalid index: must be between 0 and number of current items");
            }
        }
        totalLinesRun++;
        if (nodeAtIndex->getNext() == nullptr) {
            totalLinesRun++;
            throw std::out_of_range("Invalid index: must be between 0 and number of current items");
        } else {
            totalLinesRun++;
            if (nodeAtIndex->getNext() == end) {
                totalLinesRun++;
                end = nodeAtIndex;
            }
        }

        totalLinesRun+=4;
        LinkedNode<ItemType>* tempNext = nodeAtIndex->getNext()->getNext();
        removed = nodeAtIndex->getNext()->getItem();
        delete nodeAtIndex->getNext();
        nodeAtIndex->setNext(tempNext);
    }
    totalLinesRun++;
    return removed;
}

template <class ItemType>
bool LinkedList<ItemType>::isEmpty() {
    totalLinesRun++;
    return start == nullptr;}

template <class ItemType>
int LinkedList<ItemType>::size() {
    totalLinesRun+=3;
    LinkedNode<ItemType>* currentNode = start;
    int counter = 0;
    while (currentNode != nullptr) { //go until the node is nullptr because getNext() on the end is nullptr, the rest point to another node
        totalLinesRun+=3;
        counter++;
        currentNode = currentNode->getNext();
    }
    totalLinesRun++;
    return counter;
}

template <class ItemType>
void LinkedList<ItemType>::clearList(LinkedNode<ItemType> *start) {
    if (start == nullptr) {
        return;
    } else {
        clearList(start->getNext()); //goes until start is nullptr, then deletes in backwards order.
        delete start;
    }
}

template <class ItemType>
void LinkedList<ItemType>::clearList() {
    clearList(start);
    start = nullptr;
    end = nullptr;
}

template <class ItemType>
int LinkedList<ItemType>::find(ItemType& itemToFind) {
    totalLinesRun+=3;
    LinkedNode<ItemType>* current = start;
    int index = 0;
    while (current != nullptr) {
        totalLinesRun++;
        if (current->getItem() == itemToFind) {
            totalLinesRun++;
            return index;
        }
        totalLinesRun+=3;
        index++;
        current = current->getNext();
    }
    totalLinesRun++;
    return -1;
}

template <class ItemType>
int LinkedList<ItemType>::findLast(ItemType& itemToFind, LinkedNode<ItemType>* start, int index) {
    totalLinesRun++;
    if (start == nullptr) {
        totalLinesRun++;
        return -1;
    } else {
        totalLinesRun+=2;
        int currentAnswer = findLast(itemToFind, start->getNext(), index + 1); //find the last occurence in the section from this point on
        if (currentAnswer == -1) { //if it doesn't exist, see if it's here.
            totalLinesRun++;
            if (start->getItem() == itemToFind) {
                totalLinesRun++;
                return index;
            }
        }
        totalLinesRun++;
        return currentAnswer;
    }
}

template <class ItemType>
int LinkedList<ItemType>::findLast(ItemType& itemToFind) {
    totalLinesRun++;
    return findLast(itemToFind, start, 0);
}

template <class ItemType>
std::string LinkedList<ItemType>::toString() {
    totalLinesRun+=3;
    std::string output = "{";
    LinkedNode<ItemType>* current = start;
    while (current != nullptr) {
        totalLinesRun+=2;
        output += std::to_string(current->getItem());
        if (current->getNext() != nullptr) {
            totalLinesRun++;
            output += ", ";
        }
        totalLinesRun+=2;
        current = current->getNext();
    }
    totalLinesRun+=2;
    output += "}";
    return output;
}

template <class ItemType>
long LinkedList<ItemType>::getTotalLinesRun() {return totalLinesRun;}

template <class ItemType>
void LinkedList<ItemType>::resetTotalLinesRun() {totalLinesRun = 0;}

template <class ItemType>
int LinkedList<ItemType>::calcSizeOf() {
    LinkedNode<ItemType>* current = start;
    int size = 0;
    while (current != nullptr) {
        size += sizeof(current->getItem());
        size += sizeof(current->getNext());
        current = current->getNext();
    }
    size += sizeof(start);
    size += sizeof(end);
    return size;
}

#include "LinkedNode.h"

