/*
---FlightMap.cpp
---Ata Seren
---21901575
---Section 2
*/
#include "FlightMap.h"
#include "GraphElement.h"
#include "City.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

FlightMap::FlightMap(const string cityFile, const string flightFile)
{
    ifstream cityfile(cityFile.c_str());
    ifstream flightfile(flightFile.c_str());
    while ( cityfile.eof() == false )
    {
        
    //initializing arrays
    cityNum = sizeCounter(cityFile);
    edgeNum = sizeCounter(flightFile);

    cityArr = new City*[cityNum];
    string city;
    for( int i = 0; getline(cityfile,city); i++)
    {
        cityArr[i] = new City(city,false);
    }
    }

    graphList = new GraphElement**[cityNum];

    for( int i = 0; i < cityNum; i++) 
    {
        graphList[i] = new GraphElement*[cityNum];
        for( int j = 0; j < cityNum; j++) 
        {
            graphList[i][j] = new GraphElement();
        }
    }

    //adding edges
    string stringId;
    string stringCost;
    string departure;
    string destination;
    int id;
    int cost;

    stringstream ssid;
    stringstream sscost;
    while ( flightfile.eof() == false )
    {
        string line;
        for( int i = 0; getline(flightfile,line); i++)
        {
            stringstream   linestream(line);
            string         text;

            getline(linestream,departure,',');  
            getline(linestream,destination,',');
            getline(linestream,stringId,',');
            getline(linestream,stringCost,'\n'); 

            //string to int stuff
            ssid << stringId;
            ssid >> id;

            sscost << stringCost;
            sscost >> cost;

            for (int a = 0; a < cityNum; a++) 
            {
                for (int b = 0; b < cityNum; b++) 
                {
                    if ( cityArr[a] -> getName() == departure && cityArr[b] -> getName() == destination) 
                    {
                        addEdge(a, b, departure, destination, id, cost);
                    }
                }
            }
        }
    }
    cityfile.close();
    flightfile.close();
}

FlightMap::~FlightMap()
{
    for ( int i = 0; i < edgeNum; i++) 
    {
        delete graphList[i];
    }

    if ( graphList != NULL) 
    {
        delete[] graphList;
    }
}

void FlightMap::displayAllCities() const
{
    for (int i = 0; i < cityNum; i++) 
    {
        cout << cityArr[i]-> getName() << ", ";
    }
    cout << endl;
}
void FlightMap::displayAdjacentCities( const string cityName ) const
{
    cout << cityName << " -> ";

    for( int i = 0; i < cityNum; i++)
    {
        if( boolAdjacent(cityName, cityArr[i]))
        {
            cout << cityArr[i] -> getName()<< ", ";
        }
    }
}
void FlightMap::displayFlightMap() const
{
    for (int i = 0; i < cityNum; i++) 
    {
        string cityName = cityArr[i]-> getName();

        cout << cityName << " -> ";

        for( int i = 0; i < cityNum; i++)
        {
            if( boolAdjacent(cityName, cityArr[i]))
            {
                cout << cityArr[i]-> getName() << ", ";
            }
        }
        cout << endl;
    }
}

//most important func, searchs the paths
void FlightMap::findFlights( const string deptCity, const string destCity ) const
{
    int index2 = -1;
    for ( int i = 0; i < cityNum; i++){
        if ( destCity == (*cityArr[i]).getName() )
        {
            index2 = i;
            break;
        }
    }

    int count = 0;

    cout << "Request is to fly from " << deptCity << " to " << destCity << ":" << endl;

    findPath(deptCity, destCity);

    unvisitAll();

}

void FlightMap::findLeastCostFlight(const string deptCity, const string destCity)const
{
}

void FlightMap::runFlightRequests( const string requestFile ) const
{
    ifstream request(requestFile.c_str());
    string deptCity;
    string destCity;
    string line;
    for( int i = 0; getline(request,line); i++)
    {
        stringstream linestream(line);
        getline(linestream, deptCity, ',');
        getline(linestream, destCity);
        findFlights(deptCity,destCity);
    }

    request.close();
}

// private functions
int FlightMap::sizeCounter(const string file) 
{
    ifstream fileForCount(file.c_str());
    int count = 0;
    string line1;
    while(getline(fileForCount, line1))
    {
        count++;
    }
    fileForCount.close();

    return count;
}

void FlightMap::addEdge(int a, int b, string dept, string dest, int id, int cost)
{
    graphList[a][b] = new GraphElement(dept, dest, id, cost);
    graphList[b][a] = new GraphElement(dept, dest, id, cost);
}

bool FlightMap::findEdge(City* dept, City* dest, int &id, int &cost )const
{
    int index = -1;
    for ( int i = 0; i < cityNum; i++)
    {
        if ( dept->getName() == cityArr[i]->getName() )
        {
            index = i;
            break;
        }
    }
    for ( int i = 0; i < cityNum; i++)
    {
        if ((graphList[index][i])->getEnd() == dest->getName())
        {
            id = (graphList[index][i])->getFlightId();
            cost = (graphList[index][i])->getCost();
            return true;
        }
    }
    return false;
}

void FlightMap::findPath(const string deptCity, const string destCity) const
{
    Stack *searchStack = new Stack();

        int startIndex = -1;
        for (int i = 0; i < cityNum; i++)
        {
            if (deptCity == cityArr[i]->getName())
            {
                startIndex = i;
                break;
            }
        }
        cityArr[startIndex]->setVisit(true);
        searchStack->push(*cityArr[startIndex]);

        int endIndex = -1;
        for ( int i = 0; i < cityNum; i++)
        {
            if (destCity == cityArr[i]->getName())
            {
                endIndex = i;
                break;
            }
        }
        int cost = 0;
        int id = 0;

        City *topCity = new City();
        string nextCity = deptCity;
        searchStack->getTop(*topCity);
        int length = 1;

        //search path
        while (!searchStack->isEmpty() && nextCity != destCity ) 
        {
            searchStack->getTop(*topCity);

            if (!canReach(topCity))
            {
                int stackIndex = -1;
                for (int i = 0; i < cityNum; i++)
                {
                    if ( topCity->getName() == cityArr[i]->getName() )
                    {
                        stackIndex = i;
                        break;
                    }
                }
                cityArr[stackIndex]->setVisit(true);
                searchStack->pop();
                length--;
            }
            else 
            {
                searchStack-> push(*findAdjCities(topCity));
                nextCity = findAdjCities(topCity) -> getName();
                findAdjCities(topCity) -> setVisit(true);
                length++;
            }
        }
        
        if (nextCity == destCity)
        {
            cityArr[endIndex] -> setVisit(true);
            
            City** path = new City*[length];
            Stack temp;
            int index = length;
            int value = length;

            for (int i = 0; i < value; i++){
                City *item = new City();
                searchStack->pop(*item);
                path[index-1] = item;
                index--;
                temp.push(*item);
            }
            for (int i = 0; i < value; i++ ){
                City *item = new City();
                temp.pop(*item);
                searchStack->push(*item);
            }

            
            int totalCost = 0;

            for ( int i = 0; i < length-1; i++) 
            {
                findEdge(path[i], path[i+1], id, cost);
                totalCost = totalCost + cost;
                cout << "Flight #" << id << " from " << path[i]->getName() << " to " << path[i+1]->getName() << " Cost: " << cost << " TL" << endl;
            }
                
            cout << "Total " << "............" << totalCost << " TL" << endl;
            cout << endl;
            for ( int i = 0; i < length; i++) 
            {
                delete path[i];
            }
            delete path;
        }
        else 
        {
            cout << "Sorry. HPAir does not fly from " << deptCity << " to " << destCity << endl;
            cout << endl;
        }
        searchStack->pop();

        delete searchStack;
        delete topCity;
}

void FlightMap::unvisitAll() const
{
    for ( int i = 0; i < cityNum; i++)
    {
       if(cityArr[i] -> getVisit())
       {
            cityArr[i] -> setVisit(false);
       }
    }
}

bool FlightMap::boolAdjacent(string departure, City* destination) const
{
    int index = -1;
    for ( int i = 0; i < cityNum; i++)
    {
        if (departure == cityArr[i]->getName())
        {
            index = i;
            i = cityNum;
        }
    }

    for (int i = 0; i < cityNum; i++)
    {
       if(graphList[index][i]->getEnd() == destination->getName() && departure != destination->getName() && !destination->getVisit())
       {
            return true;
       }
    }
    return false;
}

bool FlightMap::canReach(City* dept) const 
{
    for ( int i = 0; i < cityNum; i++)
    {
        if (boolAdjacent(dept->getName(), cityArr[i]))
        {
            return true;
        }
    }
    return false;
}

City* FlightMap::findAdjCities(City* dept )const
{
    if (dept == NULL) 
    {
        return NULL;
    }

    for ( int i = 0; i < cityNum; i++)
    {
        if (boolAdjacent(dept->getName(), cityArr[i])) 
        {
            return cityArr[i];
        }
    }
    return NULL;
}



