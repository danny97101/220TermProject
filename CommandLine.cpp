//
// Created by Daniel Akimchuk on 11/29/16.
//

#include <iostream>
#include "CommandLine.h"
#include "Stock.h"


void run() {
    Stock* stock = new Stock("inventory.txt");
    while (true) {
        std::string command;
        std::cout << "Please enter a command (or H for help): ";
        std::getline(std::cin, command);
        if (command == "") {
            std::getline(std::cin, command);
        }
        if (command == "H") {
            help();
        } else if (command[0] == 'I' && command[1] == ' ') {
            inquire(command.substr(2), stock);
        } else if (command == "L") {
            list(stock);
        } else if (command[0] == 'A' && command[1] == ' ') {
            add(command.substr(2), stock);
        } else if (command[0] == 'M' && command[1] == ' ') {
            modify(command.substr(2), stock);
        } else if (command[0] == 'S' && command[1] == ' ') {
            sell(command.substr(2), stock);
        } else if (command[0] == 'O' && command[1] == ' ') {
            order(command.substr(2), stock);
        } else if (command[0] == 'D' && command[1] == ' ') {
            delivery(command.substr(2), stock);
        } else if (command[0] == 'R' && command[1] == ' ') {
            returnStock(command.substr(2), stock);
        } else if (command == "Q") {
            quit(stock);
            delete stock;
            stock = nullptr;
            return;
        } else {
            std::cout << "Please enter a valid command." << std::endl;
        }
    }
}

void help() {
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

void inquire(std::string title, Stock* stock) {
    Movie* movie = stock->findMovie(title);
    if (movie == nullptr) {
        std::cout << "Movie not in inventory."<<std::endl;
    } else {
        std::cout << movie->toString() << std::endl;
    }
}

void list(Stock* stock) {
    stock->printInventory();
}

void add(std::string title, Stock* stock) {
    if (title != ""){
        stock->addToInventory(title);
    }
    else {
        std::cout<<"Please enter a valid movie title: ";
        std::string newTitle;
        std::cin >> newTitle;
        add(newTitle, stock);
    }
}

void modify(std::string title, Stock* stock) {
    while(title == ""){
        std::cout<<"Please enter a movie title: ";
        std::cin>> title;
    }
    Movie* movie = stock->findMovie(title);
    if (movie == nullptr) {
        std::cout << "Movie not in inventory.";
    } else {
        std::cout << "Current in stock: " << movie->getInStock() << std::endl;
        std::cout << "Current wanted in stock: " << movie->getWantInStock() << std::endl;
        int* goodVal = nullptr;
        while (goodVal == nullptr){
            std::cout << "Desired new amount wanted in stock: ";
            std::string wanted;
            std::cin >> wanted;
            try {
                std::stoi(wanted);
                goodVal = new int(std::stoi(wanted));
                movie->setWantInStock(*goodVal);
            } catch(std::invalid_argument){
                std::cout<<"Invalid input, please try again"<<std::endl;
            } catch(std::out_of_range){
                std::cout<<"Invalid input, please try again"<<std::endl;
            }
        }
    }
}

void sell(std::string title, Stock* stock) {
    Movie* movie = stock->findMovie(title);
    if (movie == nullptr) {
        movie = new Movie(title, 10.99, 2016, 0, 1);
        stock->addToInventory(*movie);
    }
    stock->sellItem(title);
}

void order(std::string filename, Stock* stock){
    stock->createOrder(filename);
}
void delivery(std::string filename, Stock* stock){
    stock->getDelivery(filename);
}
void returnStock(std::string filename, Stock* stock){
    stock->createReturn(filename);
    stock->shipReturn(filename);
}
void quit(Stock* stock){
    stock->saveInventory("inventory.txt");
}

std::string toLower(std::string title){
    std::string toReturn;
    for (int i = 0; i < title.size(); i++){
        if (int(title[i]) > 64 && int(title[i]) < 91){
            toReturn += (int(title[i]) + 32);
        } else {
            toReturn += title[i];
        }
    }
    return toReturn;
}

