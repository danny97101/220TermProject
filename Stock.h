//
// Created by Daniel Akimchuk on 11/4/16.
//

#ifndef INC_220TERMPROJECT_STOCK_H
#define INC_220TERMPROJECT_STOCK_H

class Stock {

private:
    LinkedList<Movie>* inventory;
public:
    LinkedList<Movie>* getInventory();

    void createOrder();
    void getDelivery();

    void createReturn();
    void shipReturn();

    void sellItem();
};

#endif //INC_220TERMPROJECT_STOCK_H
