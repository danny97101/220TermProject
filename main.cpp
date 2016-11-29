#include <iostream>
#include "Stock.h"

int main() {
    Stock* stock = new Stock();
    stock->addToInventory();
    stock->addToInventory();
    stock->printInventory();
    delete stock;
}