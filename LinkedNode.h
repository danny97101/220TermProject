//
// Created by Toby Dragon on 10/24/16.
//

#ifndef LINKEDNODE_H
#define LINKEDNODE_H
#include<iostream>

template<class ItemType>
class LinkedNode {

private:
    ItemType item;
    LinkedNode<ItemType>* next;

public:
    //template<class ItemType>
    LinkedNode<ItemType>(ItemType item){
        this->item = item;
        next = nullptr;
    }

    //template<class ItemType>
    ItemType getItem(){
        return item;
    }

    //template<class ItemType>
    LinkedNode<ItemType>* getNext(){
        return next;
    }

    //template<class ItemType>
    void setItem(ItemType newItem){
        item = newItem;
    }

    //template<class ItemType>
    void setNext(LinkedNode<ItemType>* newNext){
        next = newNext;
    }
};


#endif //LINKEDNODE_H
