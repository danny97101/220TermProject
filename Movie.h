//
// Created by Daniel Akimchuk on 11/4/16.
//

#ifndef INC_220TERMPROJECT_MOVIE_H
#define INC_220TERMPROJECT_MOVIE_H

#include "LinkedQueue.h"
#include <iostream>

class Movie {

private:
    std::string title;
    double price;
    int year;
    int inStock;
    int wantInStock;
    LinkedQueue<std::string>* waitList;

public:
    Movie();
    Movie(std::string title, double price, int year, int inStock, int wantInStock);
    Movie(const Movie& movie);
    Movie& operator=(Movie toCopy);
    ~Movie();

    void setTitle(std::string title);
    void setPrice(double price);
    void discountAmount(double amt);
    void discountPercent(double percent);
    void setYear(int year);
    void setInStock(int inStock);
    void setWantInStock(int wantInStock);
    void addToStock(int amount);

    std::string getTitle();
    double getPrice();
    int getYear();
    int getInStock();
    int getWantInStock();
    LinkedQueue<std::string>* getWaitList();

    bool operator==(Movie& other);

    int getNeeded();

    void addToWaitList(std::string customer);
    std::string removeFromWaitList();

    std::string toString();


};

#endif //INC_220TERMPROJECT_MOVIE_H
