//
// Created by Daniel Akimchuk on 11/29/16.
//

#include "CommandLine.h"



static void CommandLine::run() {
    while (true) {
        std::cout << "Please enter a command (or H for help): ";
        std::getline(std::cin, command);
        if (command == "H") {
            help();
        } else if (command[0] == "I") {
            inquire(command.substr(2));
        } else if (command == "L") {
            list();
        } else if (command[0] == "A") {
            add(command.substr(2));
        } else if (command[0] == "M") {
            modify(command.substr(2));
        } else if (command[0] == "S") {
            sell(command.substr(2));
        } else if (command[0] == "O") {
            order(command.substr(2));
        } else if (command[0] == "D") {
            delivery(command.substr(2));
        } else if (command[0] == "R") {
            returnStock(command.substr(2));
        } else if (command == "Q") {
            quit();
            delete stock;
            stock = nullptr;
            return;
        } else {
            std::cout << "Please enter a valid command." << std::endl;
        }
    }
}

static void CommandLine::help() {
    std::cout << "I <title> 'Inquire': Displays all information for a specific title" << std::endl;
    std::cout << "L 'List': Lists the information for the entire inventory alphabetically" << std::endl;
    std::cout << "A <title> 'Add': Adds a movie to the inventory. Prompt for initial 'want' and 'have' value. If the "
            "title already exists, informs the user and print the information for that title." << std::endl;
    std::cout << "M <title> 'Modify': Modifies the 'want' value for the specified title. Displays current 'want' and "
            "'have' values, and prompts user for new 'want' value" << std::endl;
    std::cout << "S <title> 'Sell': Decreases the count for the specified title by 1. If the title doesn't exist yet, "
            "it is added. If the title is sold out or doesn't exist, prompts the user for the buyer's name and enters "
            "them on the wait list for that title." << std::endl;
    std::cout << "O <filename> 'Order': Creates a bulk purchase order for additional movies" << std::endl;
    std::cout << "D <filename> 'Delivery': Reads file listing the delivery shipment of movies and updates the 'have' "
            "values in the inventory. If a title doesn't exist in the inventory, it is added. "
            "If there is a wait list for a movie, the name of the person will be printed and the movie will not be "
            "counted in the inventory." << std::endl;
    std::cout << "R <filename> 'Return': Writes a return invoice to a file specifying all books to be returned." << std::endl;
    std::cout << "Q 'Quit': Saves the inventory and wait lists in a file and terminates execution" <<std::endl;
}

static void CommandLine::inquire(std::string title) {
    Movie* movie = stock->findMovie(title);
    if (movie == nullptr) {
        std::cout << "Movie not in inventory.";
    } else {
        std::cout << movie->toString();
    }
}

static void CommandLine::list() {
    stock->printInventory();
}

static void CommandLine::add(std::string title) {
    stock->addToInventory(title);
}

static void CommandLine::modify(std::string title) {
    Movie* movie = stock->findMovie(title);
    if (movie == nullptr) {
        std::cout << "Movie not in inventory.";
    } else {
        std::cout << "Current in stock: " << movie->getInStock() << std::endl;
        std::cout << "Curent wanted in stock: " << movie->getWantInStock() << std::endl;
        std::cout << "Desired new amount wanted in stock: ";
        int wanted;
        std::cin >> wanted;
        movie->setWantInStock(wanted);
    }
}

static void CommandLine::sell(std::string title) {
    Movie* movie = stock->findMovie(title);
    if (movie == nullptr) {
        movie = new Movie(title, Movie::DEFAULT_PRICE, 2016, 0, 1); //TODO: year prompt maybe?
        stock->addToInventory(*movie);
        //TODO: add to the waitlist
    } else {
        movie->addToStock(-1);
    }
}