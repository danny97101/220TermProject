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
    if (inventory->isEmpty()) {
        inventory->addToEnd(movie);
    } else {
        //TODO: make this do it in alphabetical order.
        inventory->addToEnd(movie);
    }
}

void Stock::addToInventory() {
    std::string title;
    double price;
    int year;
    int inStock;
    int wantInStock;

    std::cout << "Enter Movie Title: ";
    //TODO: right now can only handle single word titles?
    std::cin >> title;
    std::cout << "Enter Movie Price: ";
    std::cin >> price;
    std::cout << "Enter Movie Year: ";
    std::cin >> year;
    std::cout << "Enter Amount In Stock: ";
    std::cin >> inStock;
    std::cout << "Enter Amount Wanted In Stock: ";
    std::cin >> wantInStock;

    Movie movie = Movie(title, price, year, inStock, wantInStock);
    addToInventory(movie);
}

void Stock::printInventory() {
    std::cout << "Current Inventory: " << std::endl;
    for (int i = 0; i < inventory->size(); i++) {
        std::cout << inventory->get(i).getTitle() << std::endl;
    }
}