//
// Created by Toby Dragon on 10/24/16.
//

#include "Queue.h"
#include "LinkedQueue.h"


//TODO: ADD COPY CONSTRUCTORS AND ASSIGNMENT OPERATORS ASAP

template <class ItemType>
LinkedQueue<ItemType>::LinkedQueue(){
    this->first = nullptr;
    this->last = nullptr;
}

template <class ItemType>
LinkedQueue<ItemType>::~LinkedQueue(){

    if (first != nullptr) {
        if (first == last) { //list of one thing. need other case b/c the loop would go on forever
            delete first;
        } else {
            while (first != nullptr) {
                LinkedNode<ItemType> *temp = first->getNext();
                delete first;
                first = temp;
            }
        }
    }

    first = nullptr;
    last = nullptr;
}

template <class ItemType>
void LinkedQueue<ItemType>::enqueue(ItemType item){
    LinkedNode<ItemType>* next = new LinkedNode<ItemType>(item);
    if (isEmpty()) {
        first = next;
        last = next;
    }
    else if (last != nullptr) {
        last->setNext(next);
    }
}

template <class ItemType>
ItemType LinkedQueue<ItemType>::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
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

template <class ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue<ItemType>& queue) {

    if (queue.first != nullptr) {
        this->first = new LinkedNode<ItemType>(*queue.first);
        this->last = this->first;
        LinkedNode<ItemType>* current = queue.first;
        LinkedNode<ItemType>* currentInThis = first;
        while (current->getNext() != nullptr) {
            current = current->getNext();
            currentInThis->setNext(new LinkedNode<ItemType>(current->getItem()));
            currentInThis = currentInThis->getNext();
        }
    } else {
        this->first = nullptr;
        this->last = nullptr;
    }
}

template <class ItemType>
    LinkedQueue<ItemType>& LinkedQueue<ItemType>::operator=(LinkedQueue<ItemType> queue) {
    if (&queue != this) {
        //delete current info
        if (first != nullptr) {
            if (first == last) { //list of one thing. need other case b/c the loop would go on forever
                delete first;
            } else {
                while (first != nullptr) {
                    LinkedNode<ItemType> *temp = first->getNext();
                    delete first;
                    first = temp;
                }
            }
        }

        first = nullptr;
        last = nullptr;

        //set things equal
        if (queue.first != nullptr) {
            this->first = new LinkedNode<ItemType>(*queue.first);
            this->last = this->first;
            LinkedNode<ItemType>* current = queue.first;
            LinkedNode<ItemType>* currentInThis = first;
            while (current->getNext() != nullptr) {
                current = current->getNext();
                currentInThis->setNext(new LinkedNode<ItemType>(current->getItem()));
                currentInThis = currentInThis->getNext();
            }
        } else {
            this->first = nullptr;
            this->last = nullptr;
        }
    }
    return *this;
}