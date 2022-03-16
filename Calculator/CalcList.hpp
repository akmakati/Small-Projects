#ifndef __CALCLIST_H
#define __CALCLIST_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "CalcListInterface.hpp"
using namespace std;

struct Elem {
    string operation;
    double operand;
    double prevTotal;
    double updatedTotal;
};

struct Node {
    Elem elem;
    Node* prev;
    Node* next;
};

class CalcList : public CalcListInterface {
public:
    double total() const;
    Node* addNode();
    void newOperation(const FUNCTIONS func, const double operand);
    void removeLastOperation();
    string toString(unsigned short precision) const;
    Node* head = NULL;
    double nTotal = 0;
};

#endif
