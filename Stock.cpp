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
    int* goodVal = nullptr;

    std::cout << "Enter Movie Title: ";
    std::string titleString;
    std::cin>>titleString;
    while (titleString == ""){
        std::cout<<"Enter Movie Title: ";
        std::cin>>titleString;
    }
    title = titleString;
    while(goodVal == nullptr){
        std::cout << "Enter Movie Price: ";
        std::string priceString;
        std::cin>>priceString;
        try {
            std::stoi(priceString);
            goodVal = new int(std::stoi(priceString));
            price = *goodVal;
        } catch(std::invalid_argument){
            std::cout<<"Invalid input, please try again"<<std::endl;
        } catch(std::out_of_range){
            std::cout<<"Invalid input, please try again"<<std::endl;
        }
    }
    goodVal = nullptr;
    while(goodVal == nullptr){
        std::cout << "Enter Movie Year: ";
        std::string yearString;
        std::cin>>yearString;
        try {
            std::stoi(yearString);
            goodVal = new int(std::stoi(yearString));
            year = *goodVal;
        } catch(std::invalid_argument){
            std::cout<<"Invalid input, please try again"<<std::endl;
        } catch(std::out_of_range){
            std::cout<<"Invalid input, please try again"<<std::endl;
        }
    }
    goodVal = nullptr;
    while(goodVal == nullptr){
        std::cout << "Enter Amount In Stock: ";
        std::string inStockString;
        std::cin>>inStockString;
        try {
            std::stoi(inStockString);
            goodVal = new int(std::stoi(inStockString));
            inStock = *goodVal;
        } catch(std::invalid_argument){
            std::cout<<"Invalid input, please try again"<<std::endl;
        } catch(std::out_of_range){
            std::cout<<"Invalid input, please try again"<<std::endl;
        }
    }
    goodVal = nullptr;
    while(goodVal == nullptr){
        std::cout << "Enter Amount Wanted In Stock: ";
        std::string wantInStockString;
        std::cin>>wantInStockString;
        try {
            std::stoi(wantInStockString);
            goodVal = new int(std::stoi(wantInStockString));
            wantInStock = *goodVal;
        } catch(std::invalid_argument){
            std::cout<<"Invalid input, please try again"<<std::endl;
        } catch(std::out_of_range){
            std::cout<<"Invalid input, please try again"<<std::endl;
        }
    }
    goodVal = nullptr;

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
    if (movie != nullptr) {
        if (movie->getInStock() > 0) {
            movie->addToStock(-1);
        }
        else {
            std::string customer;
            std::cout << "This movie is out of stock. Please enter your name for the wait list: ";
            std::cin >> customer;
            movie->addToWaitList(customer);
        }
    } else {
        std::cout << "This movie doesn't exist." << std::endl;
    }
}

void Stock::addToInventory(std::string title){
    int year;
    int wantInStock;
    double price;
    int inStock;
    int* goodVal = nullptr;
    while(goodVal == nullptr){
        std::cout << "What year is " << title << " from? ";
        std::string yearString;
        std::cin>>yearString;
        try {
            std::stoi(yearString);
            goodVal = new int(std::stoi(yearString));
            year = *goodVal;
        } catch(std::invalid_argument){
            std::cout<<"Invalid year, please try again"<<std::endl;
        } catch(std::out_of_range){
            std::cout<<"Invalid year, please try again"<<std::endl;
        }
    }
    goodVal = nullptr;
    while(goodVal == nullptr){
        std::cout << "How many do you have in stock? ";
        std::string inStockString;
        std::cin>>inStockString;
        try {
            std::stoi(inStockString);
            goodVal = new int(std::stoi(inStockString));
            inStock = *goodVal;
        } catch(std::invalid_argument){
            std::cout<<"Invalid input, please try again"<<std::endl;
        } catch(std::out_of_range){
            std::cout<<"Invalid input, please try again"<<std::endl;
        }
    }
    goodVal = nullptr;
    while(goodVal == nullptr){
        std::cout << "How many do you want in stock? ";
        std::string wantStockString;
        std::cin>>wantStockString;
        try {
            std::stoi(wantStockString);
            goodVal = new int(std::stoi(wantStockString));
            wantInStock = *goodVal;
        } catch(std::invalid_argument){
            std::cout<<"Invalid input, please try again"<<std::endl;
        } catch(std::out_of_range){
            std::cout<<"Invalid input, please try again"<<std::endl;
        }
    }
    goodVal = nullptr;
    while(goodVal == nullptr){
        std::cout << "What is the price? ";
        std::string priceString;
        std::cin>>priceString;
        try {
            std::stoi(priceString);
            goodVal = new int(std::stof(priceString));
            price = *goodVal;
        } catch(std::invalid_argument){
            std::cout<<"Invalid input, please try again"<<std::endl;
        } catch(std::out_of_range){
            std::cout<<"Invalid input, please try again"<<std::endl;
        }
    }
    Movie* movie = new Movie(title, price, year, inStock, wantInStock);
    addToInventory(*movie);

}