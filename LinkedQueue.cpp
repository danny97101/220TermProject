//
// Created by Toby Dragon on 10/24/16.
//

#include "LinkedQueue.h"

//TODO: ADD COPY CONSTRUCTORS AND ASSIGNMENT OPERATORS ASAP

template <class ItemType>
LinkedQueue<ItemType>::LinkedQueue(){
    this->first = nullptr;
    this->last = nullptr;
}

template <class ItemType>
LinkedQueue<ItemType>::~LinkedQueue(){
    while (first != nullptr) {
        LinkedNode<ItemType>* temp = first->getNext();
        delete first;
        first = temp;
    }
    first = nullptr;
    last = nullptr;
}

template <class ItemType>
void LinkedQueue<ItemType>::enqueue(ItemType item){
    LinkedNode<ItemType>* next = new LinkedNode<ItemType>(item);
    last->setNext(next);
}

template <class ItemType>
ItemType LinkedQueue<ItemType>::dequeue() {
    ItemType item = first->getItem();
    LinkedNode<ItemType>* temp = first->getNext();
    delete first;
    first = temp;
    return item;
}

template <class ItemType>
bool LinkedQueue<ItemType>::isEmpty(){
    return first == nullptr;
}
