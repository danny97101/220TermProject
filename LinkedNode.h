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
    /**
     * Constructor. Creates a new LinkedNode object. The next pointer
     * defaults to nullptr.
     * @param item The item to be stored in the the node
     * @return A new LinkedNode.
     */
    LinkedNode<ItemType>(ItemType item){
        this->item = item;
        next = nullptr;
    }

    /**
     * Getter for item.
     * @return a reference to the item stored in the node.
     */
    ItemType& getItem(){
        return item;
    }

    /**
     * Getter for next.
     * @return a pointer to the next Node.
     */
    LinkedNode<ItemType>* getNext(){
        return next;
    }

    /**
     * Setter for item.
     * @param newItem Item to replace the current item.
     */
    void setItem(ItemType newItem){
        item = newItem;
    }

    /**
     * Setter for next.
     * @param newNext A pointer to the node to replace the current next.
     */
    void setNext(LinkedNode<ItemType>* newNext){
        next = newNext;
    }
};


#endif //LINKEDNODE_H
