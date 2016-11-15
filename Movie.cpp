//
// Created by Daniel Akimchuk on 11/8/16.
//

#include "Movie.h"

Movie::Movie(String title, double price, int year, int inStock, int wantInStock) {
    this->title = title;
    this->year = year;
    this->inStock = inStock;
    this->wantInStock = wantInStock;
    this->waitList = new LinkedQueue<std::string>();
}

Movie::Movie(Movie movie) {
    this->title = movie.title;
    this->price = movie.price;
    this->year = movie.year;
    this->inStock = movie.inStock;
    this->wantInStock = movie.wantInStock;
    this->waitList = movie.waitList; //MAKE SURE WE OVERLOAD ASSIGNMENT OPERATOR AND COPY CONSTRUCTOR
}

Movie::~Movie() {
    delete waitList;
    waitList = nullptr;
}

void Movie::setTitle(String title) {
    this->title = title;
}

void Movie::setPrice(double price) {
    this->price = price;
}

void Movie::discountAmount(double amt) {
    this->price = this->price - amt;
}

void Movie::discountPercent(double percent) {
    this->price = this->price * percent;
}
