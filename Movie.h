//
// Created by Daniel Akimchuk on 11/4/16.
// Movie.h
// A model for a Movie.
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
    /**
     * Default constructor.
     * @return a new Movie object. All data members default to "", -1, or nullptr
     */
    Movie();
    /**
     * Constructor
     * @param title the title of the movie
     * @param price the price of the movie
     * @param year the year the movie was released
     * @param inStock the amount of the movie in stock
     * @param wantInStock the amount of the movie wanted in stock
     * @return A new Movie object with these values. The waitlist defaults
     * to an empty LinkedQueue.
     */
    Movie(std::string title, double price, int year, int inStock, int wantInStock);
    /**
     * Copy constructor
     * @param movie the movie to be copied.
     * @return a deep copy of movie.
     */
    Movie(const Movie& movie);
    /**
     * Overrides the assignment operator.
     * @param toCopy the movie to be copied.
     * @return a deep copy of toCopy.
     */
    Movie& operator=(Movie toCopy);
    /**
     * Destructor
     */
    ~Movie();

    /**
     * Setter for title
     * @param title the new title to replace this->title
     */
    void setTitle(std::string title);
    /**
     * Setter for price
     * @param price the new price to replace this->price
     */
    void setPrice(double price);
    /**
     * Discounts the movie by the amount entered.
     * this->price will now be price - amt
     * @param amt the amount to discount the movie by.
     */
    void discountAmount(double amt);
    /**
     * Discounts the movie by the percent entered.
     * this->price will now be price * percent.
     * @param percent The percent of the price that you want to be the new price
     */
    void discountPercent(double percent);
    /**
     * Setter for year
     * @param year the year that will replace this->year
     */
    void setYear(int year);
    /**
     * Setter for inStock.
     * @param inStock the amount that will replace this->inStock
     */
    void setInStock(int inStock);
    /**
     * Setter for wantInStock
     * @param wantInStock the amount that will replace this->wantInStock
     */
    void setWantInStock(int wantInStock);
    /**
     * Adds the amount inputted to inStock
     * @param amount the amount to add to inStock
     */
    void addToStock(int amount);
    /**
     * Setter for waitList
     * @param queue a pointer to the queue to replace this->waitList
     */
    void setWaitList(LinkedQueue<std::string>* queue);

    //GETTERS
    std::string getTitle();
    double getPrice();
    int getYear();
    int getInStock();
    int getWantInStock();
    LinkedQueue<std::string>* getWaitList();

    /**
     * Overrides the comparison equals operator
     * @param other a reference to the movie to compare the current movie to.
     * @return true if the movies are the same, false otherwise.
     */
    bool operator==(Movie& other);

    /**
     * Calculates the difference between the amount in stock and the amount
     * wanted in stock
     * @return the amount needed for inStock to equal wantedInStock
     */
    int getNeeded();

    /**
     * Adds the customer to the waitList for the movie
     * @param customer the name to be added to the waitlist.
     */
    void addToWaitList(std::string customer);
    /**
     * Removes the next person on the waitlist
     * @return the name of the person removed from the waitlist
     */
    std::string removeFromWaitList();

    /**
     * Gives relevant information about the movie to be printed
     * @return a summary of the movie.
     */
    std::string toString();
    /**
     * Puts all information about the movie in a string, to be saved
     * in inventory.txt when the program quits.
     * @return
     */
    std::string toStringForQuit();

};

#endif //INC_220TERMPROJECT_MOVIE_H
