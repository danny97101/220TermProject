//
// Created by Daniel Akimchuk on 11/4/16.
//

#ifndef INC_220TERMPROJECT_STOCK_H
#define INC_220TERMPROJECT_STOCK_H

#include "Movie.h"
#include "LinkedList.h"

class Stock {

private:
    LinkedList<Movie>* inventory;

public:
    Stock();
    ~Stock();

    LinkedList<Movie>* getInventory();

    void addToInventory(Movie& movie);
    void addToInventory();

    void printInventory();

    void createOrder();
    void getDelivery();

    void createReturn();
    void shipReturn();

    void sellItem();

    Movie* findMovie(std::string title);
};

#endif //INC_220TERMPROJECT_STOCK_H
