/*
---GraphElement.cpp
---Ata Seren
---21901575
---Section 2
*/
#include "GraphElement.h"
#include <iostream>
#include <string>
using namespace std;

//constructor for empty graph element
GraphElement::GraphElement()
{
    start = "";
    end = "";
    flightId = 0;
    cost = 0;
}

//constructor for specific data
GraphElement::GraphElement( string newStart, string newEnd, int newFlightId, int newCost)
{
    start = newStart;
    end = newEnd;
    flightId = newFlightId;
    cost = newCost;
}

GraphElement::~GraphElement()
{

}

string GraphElement::getStart()
{
    return start;
}

string GraphElement::getEnd()
{
    return end;
}

int GraphElement::getFlightId()
{
    return flightId;
}

int GraphElement::getCost()
{
    return cost;
}
