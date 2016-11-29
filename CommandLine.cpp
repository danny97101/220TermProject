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