//
// Created by Daniel Akimchuk on 11/4/16.
//

#ifndef INC_220TERMPROJECT_MOVIE_H
#define INC_220TERMPROJECT_MOVIE_H

#include "Queue.h"

class Movie {

private:
    std::string title;
    double price;
    int year;
    int inStock;
    int wantInStock;
    Queue<std::string>* waitList;

public:
    Movie(std::string title, double price, int year, int inStock, int wantInStock);
    Movie(Movie movie);
    ~Movie();

    void setTitle(std::string title);
    void setPrice(double price);
    void discountAmount(double amt);
    void discountPercent(double percent);
    void setYear(int year);
    void setInStock(int inStock);
    void setWantInStock(int wantInStock);

    std::string getTitle();
    double getPrice();
    int getYear();
    int getInStock();
    int getWantInStock();

    int getNeeded();

    void addToWaitList(std::string customer);
    std::string removeFromWaitList();


};

#endif //INC_220TERMPROJECT_MOVIE_H
