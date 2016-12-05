//
// Created by Daniel Akimchuk on 11/15/16.
//

#include "Stock.h"
#include <fstream>

Stock::Stock() {
    this->inventory = new LinkedList<Movie>();
}

Stock::~Stock() {
    delete inventory;
}

LinkedList<Movie>* Stock::getInventory() {
    return inventory;
}

void Stock::addToInventory(Movie movie) {
    if (inventory->isEmpty()) {
        inventory->addToEnd(movie);
    } else {
        //TODO: make this do it in alphabetical order.
        inventory->addToEnd(movie);
    }
}

void Stock::addToInventory() {
    std::string title;
    double price;
    int year;
    int inStock;
    int wantInStock;

    std::cout << "Enter Movie Title: ";
    //TODO: right now can only handle single word titles?
    getline(std::cin, title);
    std::cout << "Enter Movie Price: ";
    std::cin >> price;
    std::cout << "Enter Movie Year: ";
    std::cin >> year;
    std::cout << "Enter Amount In Stock: ";
    std::cin >> inStock;
    std::cout << "Enter Amount Wanted In Stock: ";
    std::cin >> wantInStock;

    std::cin.ignore();

    Movie movie = Movie(title, price, year, inStock, wantInStock);
    addToInventory(movie);
}

void Stock::printInventory() {
    std::cout << "Current Inventory: " << std::endl;
    for (int i = 0; i < inventory->size(); i++) {
        std::cout << inventory->get(i).toString() << std::endl;
    }
}

void Stock::createOrder(std::string filename) {
    std::ofstream outputFile(filename); //TODO: test this eventually
    if (outputFile.is_open()) {
    for (int i = 0; i < inventory->size(); i++) {
        Movie& current = inventory->get(i);
        int needed = current.getNeeded();
        if (needed > 0) {
        outputFile << current.getTitle() << std::endl << std::to_string(needed) << std::endl;
        }
    }
        outputFile.close();
    }
    std::cout << "Written to " << filename << std::endl;

}

void Stock::getDelivery(std::string filename) {
    std::ifstream input(filename);
    std::string line;
    Movie* movie = nullptr;
    if (input.is_open()) {
        int count = 0;
        while (getline(input, line)) {
            if (count%2 == 0) {
                movie = findMovie(line);
                if (movie == nullptr) {
                    //TODO: make new addToInventory that takes string title
                }
            } else {
                movie->addToStock(std::stoi(line));
            }
            count++;
        }
        input.close();
    }

}

void Stock::createReturn(std::string filename) {
    std::ofstream outputFile(filename); //TODO: test this eventually
    if (outputFile.is_open()) {
        for (int i = 0; i < inventory->size(); i++) {
            Movie& current = inventory->get(i);
            int needed = current.getNeeded();
            if (needed < 0) {
                outputFile << current.getTitle() << std::endl << std::to_string(needed) << std::endl;
            }
        }
        outputFile.close();
    }

}

void Stock::shipReturn(std::string filename) {
    std::ifstream input(filename);
    std::string line;
    Movie* movie = nullptr;
    if (input.is_open()) {
        int count = 0;
        while (getline(input, line)) {
            if (count%2 == 0) {
                movie = findMovie(line);
                if (movie == nullptr) {
                    //TODO: error checking wooooo
                }
            } else {
                movie->addToStock(std::stoi(line)); //TODO: error checking don't let instock be less than 0
            }
            count++;
        }
        input.close();
    }
}


Movie* Stock::findMovie(std::string title) {
    for (int i = 0; i < inventory->size(); i++) { //TODO: binary search
        Movie& current = inventory->get(i);
        if (current.getTitle() == title) {
            return &current;
        }
    }
    return nullptr;

}

void Stock::sellItem(std::string title) {
    Movie* movie = findMovie(title);
    if (movie != nullptr && movie->getInStock() > 0) {
        movie->addToStock(-1);
    }
    if (movie->getInStock() == 0) {
        std::string customer;
        std::cout << "This movie is out of stock. Please enter your name for the wait list: ";
        std::cin >> customer;
        movie->addToWaitList(customer);
    }
}

void Stock::addToInventory(std::string title){
    int year;
    int wantInStock;
    double price;
    int inStock;
    std::cout << "What year is " << title << " from? ";
    std::cin >> year;
    std::cout << "How many do you have in stock? ";
    std::cin >> inStock;
    std::cout << "How many do you want in stock? ";
    std::cin >> wantInStock;
    std::cout << "What is the price? ";
    std::cin >> price;
    Movie* movie = new Movie(title, price, year, inStock, wantInStock);
    addToInventory(*movie);

}