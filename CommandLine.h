//
// Created by Daniel Akimchuk on 11/29/16.
// CommandLine.h
// This is a set of functions that act as the UI for the user of the app.
//

#ifndef INC_220TERMPROJECT_COMMANDLINE_H
#define INC_220TERMPROJECT_COMMANDLINE_H

#include <string>
#include "Stock.h"

/**
 * Loads the stock from inventory.txt and handles user input.
 * User can input H (help), I <title> (inquire), L (list),
 * A <title> (add), M <title> (modify), S <title> (sell),
 * O <filename> (order), D <filename> (delivery), R <filename> (return)
 * Q (quit). Will loop until the user enters Q.
 */
void run();
/**
 * Prints out all possible commands the user can enter and a description
 * of what it will do.
 */
void help();
/**
 * Finds the movie with the title entered in the stock and prints
 * its title, year, price, amount in stock, and amount wanted in stock.
 * If no movie can be found, the user will be informed it's not in the inventory.
 * @param title The title of the movie to be inquired about
 * @param stock The stock that will be searched for the movie.
 */
void inquire(std::string title, Stock* stock);
/**
 * Lists the title, year, price, amount in stock, and amount wanted in stock
 * for every movie in the stock.
 * @param stock The stock that will be listed.
 */
void list(Stock* stock);
/**
 * Adds a movie with the title entered to the stock.
 * The user will be prompted to input year, amount in stock, and
 * amount wanted in stock.
 * @param title The title of the movie to be entered
 * @param stock The stock that the movie will be added to.
 */
void add(std::string title, Stock* stock);
/**
 * Allows the user to update the amount wanted in stock for the movie
 * entered. The movie's current amount in stock and amount wanted in stock
 * will be outputted, then the user will be prompted to enter a new amount
 * wanted.
 * @param title The title of the movie to be modified.
 * @param stock The stock that the movie to be modified is in.
 */
void modify(std::string title, Stock* stock);
/**
 * Sells one copy of the movie entered. If it's out of stock, the user
 * will be prompted for a name to be put on the waitlst.
 * @param title The title of the movie to be sold
 * @param stock The stock to sell the movie from.
 */
void sell(std::string title, Stock* stock);
/**
 * Calculates the amount needed to purchase of every movie in the stock to
 * get the amount in stock to equal the amount wanted in stock. Saves
 * this information to a file.
 * @param filename The name of the file to save the order to.
 * @param stock The stock to calculate the order for.
 */
void order(std::string filename, Stock* stock);
/**
 * Reads in an order file and adds the amounts saved in the file
 * to the amount in stock of every movie in the file.
 * @param filename The name of the order file. This should have been
 * generated in the order() function
 * @param stock The stock to update.
 */
void delivery(std::string filename, Stock* stock);
/**
 * Similar to order/delivery. Calculates the amount of surplus of every
 * movie in the stock (the amount needed to return in order to get amount
 * in stock to equal amount wanted in stock. Saves this to a file, and then
 * updates the stock.
 * @param filename The name of the file to save the return to.
 * @param stock The stock to be updated.
 */
void returnStock(std::string filename, Stock* stock);
/**
 * Saves the current inventory to inventory.txt and ends the software.
 * This file will be read in upon start.
 * @param stock The stock to be saved.
 */
void quit(Stock* stock);
/**
 * A helper function for string comparisons. Returns the lower case
 * version of the string entered, so string comparisons become much more
 * simple.
 * @param title The string to be converted.
 * @return The lower case version of title.
 */
std::string toLower(std::string title);


#endif //INC_220TERMPROJECT_COMMANDLINE_H
