//
// Created by Daniel Akimchuk on 12/2/16.
//

#ifndef INC_220TERMPROJECT_TESTSUITE_H
#define INC_220TERMPROJECT_TESTSUITE_H

#include <iostream>

void printPassFail(std::string testName, bool passes);

void LinkedListTestAddToEnd();
void LinkedListTestAddToFront();
void LinkedListTestAdd();
void LinkedListTestGet();
void LinkedListTestRemove();
void LinkedListTestIsEmpty();
void LinkedListTestSize();
void LinkedListTestClearList();
void LinkedListTestFind();
void LinkedListTestFindLast();

void LinkedQueueTestEnqueueDequeue();
void LinkedQueueTestIsEmpty();

void MovieTestCopyConstructor();
void MovieTestDiscountAmount();
void MovieTestDiscountPercent();
void MovieTestAddToStock();
void MovieTestGetNeeded();
void MovieTestAddToWaitList();
void MovieTestRemoveFromWaitList();

void StockTestAddToInventory();
void StockTestCreateOrder();
void StockTestGetDelivery();
void StockTestCreateReturn();
void StockTestShipReturn();
void StockTestSellItem();
void StockTestFindMovie();

void testLinkedList();
void testLinkedQueue();
void testMovie();
void testStock();
void runTests();

#endif //INC_220TERMPROJECT_TESTSUITE_H
