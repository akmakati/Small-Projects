#include <iostream>
#include <sstream>
#include <iomanip>
#include "CalcList.hpp"
#include "CalcListInterface.hpp"
#include <string>
using namespace std;

//Just returns the total that's stored
double CalcList::total() const
{
    return nTotal;
}

//Used to create new nodes
Node* CalcList::addNode() 
{
    Node* newNode = new Node();
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->elem.prevTotal = 0;
    return newNode;
}

void CalcList::newOperation(const FUNCTIONS func, const double operand) 
{
    //Creates new node that is going to be used
    Node* newNode = addNode();
    //Addition case
    if (func == ADDITION)
    {
        newNode->elem.operation = "+";
        newNode->elem.operand = operand;
        //If head is null, sets total to zero and changes updatedTotal to added amount
        if (head == NULL)
        {
            newNode->elem.prevTotal = 0;
            newNode->elem.updatedTotal = operand;
            head = newNode;
        }
        else 
        {
            //Traverse list
            Node* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            //Adds operand to total and changes updatedTotal
            newNode->elem.prevTotal = temp->elem.updatedTotal;
            newNode->elem.updatedTotal = newNode->elem.prevTotal + operand;
            temp->next = newNode;
            newNode->prev = temp;
        }
        //Updates nTotal
        nTotal = newNode->elem.updatedTotal;
    }
    //Subtraction case
    else if (func == SUBTRACTION)
    {
        newNode->elem.operation = "-";
        newNode->elem.operand = operand;
        //If head is null, sets updatedTotal to 0 - operand
        if (head == NULL)
        {
            newNode->elem.prevTotal = 0;
            newNode->elem.updatedTotal = 0 - operand;
            head = newNode;
        }
        else 
        {
            //Traverse list
            Node* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            //Subtracts operand from total and stores
            newNode->elem.prevTotal = temp->elem.updatedTotal;
            newNode->elem.updatedTotal = newNode->elem.prevTotal - operand;
            temp->next = newNode;
            newNode->prev = temp;
        }
        //Updates nTotal
        nTotal = newNode->elem.updatedTotal;
    }
    //Multiplication case
    else if (func == MULTIPLICATION)
    {
        newNode->elem.operation = "*";
        newNode->elem.operand = operand;
        //Can't multiply by 0, accounts for that
        if (head == NULL)
        {
            newNode->elem.prevTotal = 0;
            newNode->elem.updatedTotal = 0;
            head = newNode;
        }
        else 
        {
            //Traverse list
            Node* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            //Does multiplication
            newNode->elem.prevTotal = temp->elem.updatedTotal;
            newNode->elem.updatedTotal = newNode->elem.prevTotal * operand;
            temp->next = newNode;
            newNode->prev = temp;
        }
        nTotal = newNode->elem.updatedTotal;
    }
    else if (func == DIVISION)
    {
        newNode->elem.operation = "/";
        newNode->elem.operand = operand;
        //Throws if operand is 0 because you cannot divide by 0
        if (operand == 0)
        {
            throw operand;
        }
        //Cannot divide 0
        if (head == NULL)
        {
            newNode->elem.prevTotal = 0;
            newNode->elem.updatedTotal = 0;
            head = newNode;
        }
        else 
        {
            //Traverse list
            Node* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            newNode->elem.prevTotal = temp->elem.updatedTotal;
            newNode->elem.updatedTotal = newNode->elem.prevTotal / operand;
            temp->next = newNode;
            newNode->prev = temp;
        }
        nTotal = newNode->elem.updatedTotal;
    }
}

void CalcList::removeLastOperation()
{
    //Throws if you try to removeLastOperation without performing any operations
    if (head == NULL)
    {
        throw "Exception thrown.";
        return;
    }
    else 
    {
        //Traverse list
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        if (temp->prev == NULL)
        {
            nTotal = temp->elem.prevTotal;
            head = NULL;
            delete temp;
        }
        else if (temp->prev != NULL)
        {
            temp->prev->next = NULL;        
            nTotal = temp->prev->elem.updatedTotal;
            delete temp;
        }
    }
}

string CalcList::toString(unsigned short precision) const
{
    if (head == NULL)
    {
        return " ";
    }
    else 
    {
        ostringstream oss;
        string operationList;
        oss << setprecision(precision) << fixed;
        int i = 1;
        //Traverse list
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
            i++;
        }
        //Reads operation list backwards and lists prevTotal, operation, operand and updatedTotal
        while (temp != NULL)
        {
            oss << i << ": "<< temp->elem.prevTotal << temp->elem.operation << temp->elem.operand << "="<< temp->elem.updatedTotal << "\n";
            temp = temp->prev;
            i--;
        }
        operationList = oss.str();
        return operationList;
    }
}

/*
int main()
{
    CalcList calc; // Total == 0 
    calc.newOperation(DIVISION, 5);
    cout << calc.toString(1) << endl;
    
    return 0;
}*/