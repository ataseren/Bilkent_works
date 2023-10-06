/*
---FlightMap.h
---Ata Seren
---21901575
---Section 2
*/
#ifndef __FLIGHTMAP_H
#define __FLIGHTMAP_H
#include <string>
#include "City.h"
#include "GraphElement.h"
using namespace std;

class FlightMap {
public:
    FlightMap( const string cityFile, const string flightFile );
    ~FlightMap();
    void displayAllCities() const;
    void displayAdjacentCities( const string cityName ) const;
    void displayFlightMap() const;
    void findFlights( const string deptCity, const string destCity ) const;
    void findLeastCostFlight( const string deptCity, const string destCity )const;
    void runFlightRequests( const string requestFile ) const;
private:
    int sizeCounter(const string file);
    void addEdge(int a, int b, string origin, string destination, int id, int cost);
    bool findEdge(City* origin, City* dest, int &id, int &cost ) const;
    void unvisitAll() const; 
    bool boolAdjacent( string origin, City* destination) const;
    bool canReach(City* origin) const;
    void findPath(const string deptCity, const string destCity) const;
    City* findAdjCities(City* origin )const;

    int cityNum, edgeNum;
    City** cityArr;
    GraphElement*** graphList;

};
#endif