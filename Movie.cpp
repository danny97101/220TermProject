//
// Created by Daniel Akimchuk on 11/8/16.
//

#include <string>
#include "Movie.h"
#include "LinkedQueue.h"

Movie::Movie(std::string title, double price, int year, int inStock, int wantInStock) {
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

void Movie::setTitle(std::string title) {
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

void Movie::setYear(int year) {
    this->year = year;
}

void Movie::setInStock(int inStock) {
    this->inStock = inStock;
}

void Movie::setWantInStock(int wantInStock) {
    this->wantInStock = wantInStock;
}

std::string Movie::getTitle(){
    return this->title;
}

double Movie::getPrice() {
    return this->price;
}

int Movie::getYear() {
    return this->year;
}

int Movie::getInStock() {
    return this->inStock;
}

int Movie::getWantInStock() {
    return this->wantInStock;
}

int Movie::getNeeded() {
    return this->wantInStock - this->inStock;
}

void Movie::addToWaitList(std::string customer) {
    this->waitList->enqueue(customer);
}

std::string Movie::removeFromWaitList() {
    return this->waitList->dequeue();
}


