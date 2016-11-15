//
// Created by Daniel Akimchuk on 11/15/16.
//

#include "Stock.h"

Stock::Stock() {
    this->inventory = new LinkedList<Movie>();
}

Stock::~Stock() {
    delete inventory;
}

LinkedList<Movie>* Stock::getInventory() {
    return inventory;
}

void Stock::addToInventory(Movie &movie) {

}