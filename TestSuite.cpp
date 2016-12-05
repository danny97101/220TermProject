//
// Created by Daniel Akimchuk on 12/2/16.
//

#include <fstream>
#include "LinkedList.h"
#include "TestSuite.h"
#include "LinkedQueue.h"
#include "Movie.h"
#include "Stock.h"

void printPassFail(std::string testName, bool passes) {
    if (passes) {
        std::cout << "\t" << testName << ": pass" << std::endl;
    } else {
        std::cout << "\t" << testName << ": FAIL" << std::endl;
    }
}

void LinkedListTestAddToEnd() {
    bool passes = true;
    int a = 10;
    LinkedList<int> testList = LinkedList<int>();
    testList.addToEnd(a); //when list is empty - also this error is a known error in CLion when passing literals to a function expecting a reference
    if (testList.get(0) != 10 || testList.size() != 1) {
        passes = false;
    }

    a = 20;
    testList.addToEnd(a); //when list is not empty
    if (testList.get(0) != 10 || testList.get(1) != 20 || testList.size() != 2) {
        passes = false;
    }

    printPassFail("addToEnd", passes);
}

void LinkedListTestAddToFront() {
    bool passes = true;
    int a = 10;
    LinkedList<int> testList = LinkedList<int>();
    testList.addToFront(a); //when list is empty
    if (testList.get(0) != 10 || testList.size() != 1) {
        passes = false;
    }
    a = 20;
    testList.addToFront(a); //when list is not empty
    if (testList.get(1) != 10 || testList.get(0) != 20 || testList.size() != 2) {
        passes = false;
    }

    printPassFail("addToFront", passes);
}

void LinkedListTestAdd() {
    bool passes = true;
    LinkedList<int> testList = LinkedList<int>();
    int a = 0;
    testList.add(a, 0); //empty list
    if (testList.get(0) != 0 || testList.size() != 1) {
        passes = false;
    }

    a = 10;
    testList.add(a, 0); //add to front
    if (testList.get(0) != 10 || testList.get(1) != 0 || testList.size() != 2) {
        passes = false;
    }

    a = 20;
    testList.add(a, 2); //add to end
    if (testList.get(0) != 10 || testList.get(1) != 0 || testList.get(2) != 20 || testList.size() != 3) {
        passes = false;
    }

    a = 0;
    try {
        testList.add(a, -1); //negative index
        passes = false;
    } catch (std::out_of_range e) {}

    try {
        testList.add(a, 6); //too large index
        passes = false;
    } catch (std::out_of_range e) {}

    printPassFail("add", passes);
}

void LinkedListTestGet() {
    bool passes = true;
    LinkedList<int> testList = LinkedList<int>();
    int a = 6;
    testList.addToEnd(a);
    a = 8;
    testList.addToEnd(a);
    a = 10;
    testList.addToEnd(a);
    if(testList.get(0) != 6) { //using an index in the list
        passes = false;
    }

    try {
        testList.get(5); //an index too big
        passes = false;
    } catch (std::out_of_range) {}

    try {
        testList.get(-1); //negative index
        passes = false;
    } catch (std::out_of_range) {}

    printPassFail("get", passes);
}

void LinkedListTestRemove() {
    bool passes = true;
    LinkedList<int> testList = LinkedList<int>();
    int a = 5;
    testList.addToEnd(a);
    a = 6;
    testList.addToEnd(a);
    if (testList.remove(0) != 5) { //an index in the list
        passes = false;
    }
    if (testList.get(0) != 6) { //make sure everything got shifted accordingly
        passes = false;
    }

    try {
        testList.remove(-1); //negative index
        passes = false;
    } catch (std::out_of_range) {}

    try {
        testList.remove(8); //index too high
        passes = false;
    } catch (std::out_of_range) {}

    printPassFail("remove", passes);
}

void LinkedListTestIsEmpty() {
    bool passes = true;
    LinkedList<int> testList = LinkedList<int>();
    if (!testList.isEmpty()) { //empty list
        passes = false;
    }
    int a = 6;
    testList.addToEnd(a);
    if (testList.isEmpty()) { //non empty list
        passes = false;
    }

    printPassFail("isEmpty", passes);
}

void LinkedListTestSize() {
    bool passes = true;
    LinkedList<int> testList = LinkedList<int>();
    if (testList.size() != 0) { //empty list
        passes = false;
    }
    int a = 6;
    testList.addToEnd(a);
    if (testList.size() != 1) { //nonempty
        passes = false;
    }

    printPassFail("size", passes);
}

void LinkedListTestClearList() {
    bool passes = true;
    LinkedList<int> testList = LinkedList<int>();
    testList.clearList();
    if (!testList.isEmpty()) { //empty list
        passes = false;
    }
    int a = 4;
    testList.addToEnd(a);
    testList.clearList();
    if (!testList.isEmpty()) { //nonempty list
        passes = false;
    }

    testList.addToEnd(a);
    testList.addToEnd(a);
    testList.clearList();
    if (!testList.isEmpty()) { //list with multiple things
        passes = false;
    }

    printPassFail("clearList", passes);
}

void LinkedListTestFind() {
    bool passes = true;
    LinkedList<int> testList = LinkedList<int>();
    int a = 5;
    testList.addToEnd(a);
    a = 10;
    testList.addToEnd(a);
    a = 15;
    testList.addToEnd(a);
    a = 5;
    testList.addToEnd(a);
    a = 10;
    if (testList.find(a) != 1) { //in list once
        passes = false;
    }

    a = 5;
    if (testList.find(a) != 0) { //in list multiple times
        passes = false;
    }

    a = 3920;
    if (testList.find(a) != -1) { //not in list
        passes = false;
    }

    printPassFail("find", passes);
}

void LinkedListTestFindLast() {
    bool passes = true;
    LinkedList<int> testList = LinkedList<int>();
    int a = 5;
    testList.addToEnd(a);
    a = 10;
    testList.addToEnd(a);
    a = 15;
    testList.addToEnd(a);
    a = 5;
    testList.addToEnd(a);
    a = 10;
    if (testList.findLast(a) != 1) { //in list once
        passes = false;
    }

    a = 5;
    if (testList.findLast(a) != 3) { //in list multiple times
        passes = false;
    }

    a = 3920;
    if (testList.findLast(a) != -1) { //not in list
        passes = false;
    }

    printPassFail("findList", passes);
}

void LinkedQueueTestEnqueueDequeue() {
    bool passes = true;
    LinkedQueue<int> testQueue = LinkedQueue<int>();
    testQueue.enqueue(6);
    testQueue.enqueue(7);
    try {
        if (testQueue.dequeue() != 6) { //list still has other things
            passes = false;
        }
    } catch (std::out_of_range) {}
    try {
        if (testQueue.dequeue() != 7) { //list will have nothing else
            passes = false;
        }
    } catch (std::out_of_range) {}
    try {
        testQueue.dequeue();
        passes = false;
    } catch (std::out_of_range) {
    }

    printPassFail("enqueue and dequeue", passes);
}

void LinkedQueueTestIsEmpty() {
    bool passes = true;
    LinkedQueue<int> testList = LinkedQueue<int>();
    if (!testList.isEmpty()) { //empty list
        passes = false;
    }
    int a = 6;
    testList.enqueue(a);
    if (testList.isEmpty()) { //non empty list
        passes = false;
    }

    printPassFail("isEmpty", passes);
}

void MovieTestCopyConstructor() {
    bool passes = true;
    Movie movie1 = Movie("bee movie", 20, 2006, 2, 10000);
    Movie movie2 = Movie(movie1);
    if (movie2.getTitle() != movie1.getTitle() || movie2.getPrice() != movie1.getPrice()
            || movie2.getYear() != movie1.getYear() || movie2.getInStock() != movie1.getInStock()
            || movie2.getWantInStock() != movie1.getWantInStock()) {
        passes = false;
    }
    if (movie2.getWaitList() == movie1.getWaitList()){ //make sure they dont point to the same thing
        passes = false;
    }

    printPassFail("copy constructor", passes);
}

void MovieTestDiscountAmount() {
    bool passes = true;
    Movie movie = Movie("bee movie", 20, 2006, 2, 10000);
    movie.discountAmount(1);
    if (movie.getPrice() != 19) {
        passes = false;
    }

    printPassFail("discountAmount", passes);
}

void MovieTestDiscountPercent() {
    bool passes = true;
    Movie movie = Movie("bee movie", 20, 2006, 2, 10000);
    movie.discountPercent(.5);
    if (movie.getPrice() != 10) {
        passes = false;
    }

    printPassFail("discountPercent", passes);
}

void MovieTestAddToStock() {
    bool passes = true;
    Movie movie = Movie("bee movie", 20, 2006, 2, 10000);
    movie.addToStock(400);
    if (movie.getInStock() != 402) {
        passes = false;
    }

    printPassFail("addToStock", passes);
}

void MovieTestGetNeeded() {
    bool passes = true;
    Movie movie = Movie("bee movie", 20, 2006, 2, 10000);
    if (movie.getNeeded() != 9998) {
        passes = false;
    }

    printPassFail("getNeeded", passes);
}

void MovieTestAddToWaitList() {
    bool passes = true;
    Movie movie = Movie("bee movie", 20, 2006, 2, 10000);
    movie.addToWaitList("toby");
    LinkedQueue<std::string>* waitList = movie.getWaitList();
    if (waitList->dequeue() != "toby" || !waitList->isEmpty()) {
        passes = false;
    }

    printPassFail("addToWaitList", passes);
}

void MovieTestRemoveFromWaitList() {
    bool passes = true;
    Movie movie = Movie("bee movie", 20, 2006, 2, 10000);
    movie.addToWaitList("toby");
    if (movie.removeFromWaitList() != "toby") {
        passes = false;
    }

    printPassFail("removeFromWaitList", passes);
}

void StockTestAddToInventory() {
    bool passes = true;
    Stock stock = Stock();
    Movie movie = Movie("bee movie", 20, 2006, 2, 10000);
    stock.addToInventory(movie);
    if (stock.getInventory()->get(0).getTitle() != "bee movie" || stock.getInventory()->size() != 1) { //first entry
        passes = false;
    }
    Movie movie2 = Movie("another movie", 2, 2, 2, 2);
    stock.addToInventory(movie2);
    if (stock.getInventory()->get(0).getTitle() != "bee movie" || stock.getInventory()->get(1).getTitle() != "another movie" || stock.getInventory()->size() != 2) { //another entry
        passes = false;
    }

    printPassFail("addToInventory", passes);
}

void StockTestCreateOrder() {
    bool passes = true;
    Stock stock = Stock();
    Movie movie2 = Movie("another movie", 2, 2, 2, 2);
    stock.addToInventory(movie2);
    Movie movie = Movie("bee movie", 20, 2006, 2, 10000);
    stock.addToInventory(movie);
    Movie movie3 = Movie("another movie2", 2, 2, 10, 2);
    stock.addToInventory(movie3);
    stock.createOrder("testOrder.txt");
    std::ifstream input("testOrder.txt");
    std::string line;
    getline(input, line);
    if (line != "bee movie") {
        passes = false;
    }
    getline(input, line);
    if (line != "9998") {
        passes = false;
    }
    if (getline(input, line)) { //make sure there's nothing left
        passes = false;
    }

    printPassFail("createOrder", passes);
}

void StockTestGetDelivery() {
    bool passes = true;
    Stock stock = Stock();
    Movie movie2 = Movie("another movie", 2, 2, 2, 2);
    stock.addToInventory(movie2);
    Movie movie = Movie("bee movie", 20, 2006, 2, 10000);
    stock.addToInventory(movie);
    Movie movie3 = Movie("another movie2", 2, 2, 10, 2);
    stock.addToInventory(movie3);
    stock.createOrder("testOrder.txt");
    stock.getDelivery("testOrder.txt");
    LinkedList<Movie>* inventory = stock.getInventory();
    for (int i = 0; i < inventory->size(); i++) {
        if (inventory->get(i).getNeeded() > 0) {
            passes = false;
        }
    }

    printPassFail("getDelivery", passes);
}

void StockTestCreateReturn() {
    bool passes = true;
    Stock stock = Stock();
    Movie movie2 = Movie("another movie", 2, 2, 2, 2);
    stock.addToInventory(movie2);
    Movie movie = Movie("bee movie", 20, 2006, 2, 10000);
    stock.addToInventory(movie);
    Movie movie3 = Movie("another movie2", 2, 2, 10, 2);
    stock.addToInventory(movie3);
    stock.createReturn("testReturn.txt");
    std::ifstream input("testReturn.txt");
    std::string line;
    getline(input, line);
    if (line != "another movie2") {
        passes = false;
    }
    getline(input, line);
    if (line != "-8") {
        passes = false;
    }
    if (getline(input, line)) { //make sure there's nothing left
        passes = false;
    }

    printPassFail("createReturn", passes);
}

void StockTestShipReturn() {
    bool passes = true;
    Stock stock = Stock();
    Movie movie2 = Movie("another movie", 2, 2, 2, 2);
    stock.addToInventory(movie2);
    Movie movie = Movie("bee movie", 20, 2006, 2, 10000);
    stock.addToInventory(movie);
    Movie movie3 = Movie("another movie2", 2, 2, 10, 2);
    stock.addToInventory(movie3);
    stock.createReturn("testReturn.txt");
    stock.getDelivery("testReturn.txt");
    LinkedList<Movie>* inventory = stock.getInventory();
    for (int i = 0; i < inventory->size(); i++) {
        if (inventory->get(i).getNeeded() < 0) {
            passes = false;
        }
    }

    printPassFail("getDelivery", passes);
}

void StockTestSellItem() {
    bool passes = true;
    Stock stock = Stock();
    Movie movie = Movie("bee movie", 20, 2006, 1, 10000);
    stock.sellItem("bee movie");
    if (stock.findMovie("bee movie")->getInStock() != 0) { //has stock
        passes = false;
    }
    std::cout << "This should prompt you for a name because stock is 0" << std::endl;
    stock.sellItem("bee movie");

    printPassFail("sellItem", passes);
}

void StockTestFindMovie() {
    bool passes = true;
    Stock stock = Stock();
    Movie movie = Movie("bee movie", 20, 2006, 1, 10000);
    if (stock.findMovie("bee movie")->getTitle() != "bee movie") { //if the movie exists
        passes = false;
    }
    if (stock.findMovie("dsjfk") != nullptr) {
        passes = false;
    }

    printPassFail("findMovie", passes);
}



void testLinkedList() {
    std::cout << "LinkedList:" << std::endl;
    LinkedListTestAddToEnd();
    LinkedListTestAddToFront();
    LinkedListTestAdd();
    LinkedListTestGet();
    LinkedListTestRemove();
    LinkedListTestIsEmpty();
    LinkedListTestSize();
    LinkedListTestClearList();
    LinkedListTestFind();
    LinkedListTestFindLast();
}

void testLinkedQueue() {
    std::cout << "LinkedQueue:" << std::endl;
    LinkedQueueTestEnqueueDequeue();
    LinkedQueueTestIsEmpty();
}

void testMovie() {
    std::cout << "Movie:" << std::endl;
    MovieTestCopyConstructor();
    MovieTestDiscountAmount();
    MovieTestDiscountPercent();
    MovieTestAddToStock();
    MovieTestGetNeeded();
    MovieTestAddToWaitList();
    MovieTestRemoveFromWaitList();
}

void testStock() {
    std::cout << "Stock:" << std::endl;
    StockTestAddToInventory();
    StockTestCreateOrder();
    StockTestGetDelivery();
    StockTestCreateReturn();
    StockTestShipReturn();
    StockTestSellItem();
    StockTestFindMovie();
}

void runTests() {
    testLinkedList();
    testLinkedQueue();
    testMovie();
    testStock();
}
