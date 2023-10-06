#include "FlightMap.h"
#include <iostream>

int main() {
    FlightMap fm( "cityFile.txt", "flightFile.txt" );
    cout << "The list of the cities that HPAir serves is given below:" << endl;
    fm.displayAllCities();
    cout << endl;
    cout << "The cities adjacent to W are:" << endl;
    fm.displayAdjacentCities( "W" );
    cout << endl;
    cout << "The whole flight map is shown below:" << endl;
    fm.displayFlightMap();
    cout << endl;
    fm.findFlights( "W", "Z" );
    cout << endl;
    fm.findFlights( "S", "P" );
    cout << endl;
    fm.findLeastCostFlight( "Y", "Z" );
    cout << endl;
    fm.findLeastCostFlight( "P", "X" );
    cout << endl;
    fm.runFlightRequests( "requestFile.txt" );
return 0;
}