//
// Created by Daniel Akimchuk on 11/29/16.
//

#ifndef INC_220TERMPROJECT_COMMANDLINE_H
#define INC_220TERMPROJECT_COMMANDLINE_H

#include <string>
#include "Stock.h"

void run();
void help();
void inquire(std::string title, Stock* stock);
void list(Stock* stock);
void add(std::string title, Stock* stock);
void modify(std::string title, Stock* stock);
void sell(std::string title, Stock* stock);
void order(std::string filename, Stock* stock);
void delivery(std::string filename, Stock* stock);
void returnStock(std::string filename, Stock* stock);
void quit(Stock* stock);
std::string toLower(std::string title);


#endif //INC_220TERMPROJECT_COMMANDLINE_H
