/*
---City.cpp
---Ata Seren
---21901575
---Section 2
*/
#include "City.h"
#include <string>
#include <iostream>
using namespace std;

//constructor for specific data
City::City(std::string cityName = "", bool cityVisit = false)
{
    name = cityName;
    visited = cityVisit;
}

//empty city constructor
City::City()
{
    name = "";
    visited = false;
}

//destructor
City::~City()
{

}

//getters and setters
void City::setName(string newName) 
{
    name = newName;
}

string City::getName() 
{
    return name;
}

bool City::getVisit() 
{
    return visited;
}

void City::setVisit(bool visit) 
{
    visited = visit;
}

