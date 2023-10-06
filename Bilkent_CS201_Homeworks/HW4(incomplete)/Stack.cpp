/*
---Stack.cpp
---Ata Seren
---21901575
---Section 2
*/
#include "Stack.h"
#include "City.h"
#include <iostream>
using namespace std;

//constructor
Stack::Stack() : topPtr(NULL)
{

}

//destructor
Stack::~Stack()
{
    while (!isEmpty())
    {
        pop();
    }
}

// checks if stack is empty
bool Stack::isEmpty() const
{
    return (topPtr == NULL);
}

// inserts a new item to stack
bool Stack::push(City newItem)
{
    StackNode *newPtr = new StackNode;
    newPtr->item = newItem;
    newPtr->next = topPtr;
    topPtr = newPtr;
    return true;
}

//deletes the top item in stack
bool Stack::pop(){
    if (isEmpty())
    {
        return false;
    }
    else
    {
        StackNode *temp = topPtr;
        topPtr = topPtr->next;
        temp->next = NULL;
        delete temp;
        return true;
    }
}

//deletes a specific item in stack
bool Stack::pop(City& stackTop){
    if (isEmpty())
    {
        return false;
    }
    else
    {
        stackTop = topPtr->item;
        StackNode *temp = topPtr;
        topPtr = topPtr->next;
        temp->next = NULL; 
        delete temp;
        return true;
    }
}

//retrieves the top element in stack
bool Stack::getTop(City& stackTop) const{
    if (isEmpty())
    {
        return false;
    }
    else 
    {
        stackTop = topPtr->item;
        return true;
    }
}
