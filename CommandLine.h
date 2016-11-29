//
// Created by Daniel Akimchuk on 11/29/16.
//

#ifndef INC_220TERMPROJECT_COMMANDLINE_H
#define INC_220TERMPROJECT_COMMANDLINE_H


class CommandLine {
private:
    static Stock* stock = new Stock();
public:
    static void run();
    static void help();
    static void inquire(std::string title);
    static void list();
    static void add(std::string title);
    static void modify(std::string title);
    static void sell(std::string title);
    static void order(std::string filename);
    static void delivery(std::string filename);
    static void returnStock(std::string filename);
    static void quit();
};


#endif //INC_220TERMPROJECT_COMMANDLINE_H
