/*
---City.h
---Ata Seren
---21901575
---Section 2
*/
#ifndef __CITY_H
#define __CITY_H
#include <string>
#include <iostream>
using namespace std;

class City
{
    public:
        City();
        City(string cityName, bool cityVisit);
        ~City();
        void setName(string newName);
        void setVisit(bool visit);
        string getName();
        bool getVisit();
    private:
        string name;
        bool visited;      
};
#endif