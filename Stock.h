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
    void addToInventory(std::string title); //TODO

    void printInventory();

    void createOrder(std::string filename);
    void getDelivery(std::string filename);

    void createReturn(std::string filename);
    void shipReturn(std::string filename);

    void sellItem(std::string title);

    Movie* findMovie(std::string title);
};

#endif //INC_220TERMPROJECT_STOCK_H
