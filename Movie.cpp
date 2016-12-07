//
// Created by Daniel Akimchuk on 11/8/16.
//

#include <string>
#include "Movie.h"
#include "LinkedQueue.h"

Movie::Movie() {
    this->title = "";
    this->year = -1;
    this->inStock = -1;
    this->wantInStock = -1;
    this->waitList = nullptr;
}

Movie::Movie(std::string title, double price, int year, int inStock, int wantInStock) {
    this->title = title;
    this->year = year;
    this->price = price;
    this->inStock = inStock;
    this->wantInStock = wantInStock;
    this->waitList = new LinkedQueue<std::string>();
}

Movie::Movie(const Movie& movie) {
    this->title = movie.title;
    this->price = movie.price;
    this->year = movie.year;
    this->inStock = movie.inStock;
    this->wantInStock = movie.wantInStock;

    this->waitList = new LinkedQueue<std::string>(*(movie.waitList)); //MAKE SURE WE OVERLOAD ASSIGNMENT OPERATOR AND COPY CONSTRUCTOR
}

Movie& Movie::operator=(Movie movie) {
    if (this != &movie) {
        //delete current
        if (waitList != nullptr ) {
            delete waitList;
        }
        waitList = nullptr;

        //new values
        this->title = movie.title;
        this->price = movie.price;
        this->year = movie.year;
        this->inStock = movie.inStock;
        this->wantInStock = movie.wantInStock;

        this->waitList = new LinkedQueue<std::string>(*(movie.waitList)); //MAKE SURE WE OVERLOAD ASSIGNMENT OPERATOR AND COPY CONSTRUCTOR
    }
    return *this;
}

Movie::~Movie() {
    if (waitList != nullptr ) {
        delete waitList;
    }
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

void Movie::addToStock(int amount) {
    setInStock(getInStock() + amount);
}

std::string Movie::toString() {
    std::string str = getTitle() + ", " + std::to_string(getYear()) + ", $" + std::to_string(getPrice()) + ", " + std::to_string(getInStock()) + " in stock, " + std::to_string(getWantInStock()) + " desired in stock."; //TODO: add waitlist
    return str;
}

LinkedQueue<std::string>* Movie::getWaitList() {
    return waitList;
}


