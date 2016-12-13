//
// Created by Daniel Akimchuk on 11/4/16.
// Stock.h
// A model for the stock in a movie store
//

#ifndef INC_220TERMPROJECT_STOCK_H
#define INC_220TERMPROJECT_STOCK_H

#include "Movie.h"
#include "LinkedList.h"

template <class ItemType>
class Stock : LinkedList<ItemType>{

private:
    LinkedList<Movie>* inventory;

    int getIndex(std::string title); //TODO: make binary

public:
    /**
     * Default constructor
     * @return a new stock object, with an empty inventory (not nullptr, an empty
     * list)
     */
    Stock();
    /**
     * Constructor that creates a new stock object based on the file
     * saved in filename.
     * @param filename the name of the file where the inventory is saved.
     * This should be a file that was produced in by the quit() function in
     * CommandLine
     * @return a new stock object with the information saved in filename.
     */
    Stock(std::string filename);
    /**
     * Destructor
     */
    ~Stock();

    /**
     * Getter for inventory
     * @return a pointer to the inventory object
     */
    LinkedList<Movie>* getInventory();

    /**
     * Adds the movie to the inventory.
     * @param movie the movie to be added to the inventory
     */
    void addToInventory(Movie movie);
    /**
     * Prompts the user for all the information about the movie,
     * creates a new movie object using this information, and then
     * adds that movie to the inventory.
     */
    void addToInventory();
    /**
     * Prompts the user for all information besides title,
     * Creates a movie object with this information, and then
     * adds that movie to the inventory.
     * @param title
     */
    void addToInventory(std::string title);

    /**
     * Prints information of every movie in the inventory.
     */
    void printInventory();

    /**
     * Calculates the amount needed to purchase of every movie in the stock to
     * get the amount in stock to equal the amount wanted in stock. Saves
     * this information to a file.
     * @param filename The name of the file to save the order to.
     */
    void createOrder(std::string filename);
    /**
     * Reads in an order file and adds the amounts saved in the file
     * to the amount in stock of every movie in the file.
     * @param filename The name of the order file. This should have been
     * generated in the order() function
     */
    void getDelivery(std::string filename);

    /**
     * Calculates the amount needed to return of every movie in the stock to
     * get the amount in stock to equal the amount wanted in stock. Saves
     * this information to a file.
     * @param filename The name of the file to save the return to.
     */
    void createReturn(std::string filename);
    /**
     * Reads in a return file and removes the amounts saved in the file
     * from the in stock of every movie in the file.
     * @param filename The name of the return file. this should have been generated
     * in the createReturn() function.
     */
    void shipReturn(std::string filename);

    /**
     * Removes one from the stock of the movie entered.
     * If the stock is 0, the user will be prompted to add
     * a name for the waitlist
     * @param title the title of the movie to be sold
     */
    void sellItem(std::string title);

    /**
     * finds the movie entered in the inventory
     * @param title the title of the movie to be found
     * @return a pointer to the movie in the inventory.
     * If the movie is not in the inventory, nullptr.
     */
    Movie* findMovie(std::string title);

    /**
     * Saves all information about the inventory to the filename.
     * @param filename the name of the file to save the inventory to.
     */
    void saveInventory(std::string filename);
};

#endif //INC_220TERMPROJECT_STOCK_H
