#ifndef FLIGHT_H
#define FLIGHT_H
#include <iostream>
using namespace std;

class Flight
{       
    public:
        Flight(int flightNum, int rowNum, int colonNum);
        Flight();
        ~Flight();

        void setFlightInfo(int newFlightNum, int newRowNum, int newColonNum);
        int getFlightNum();
        int getRowNum();
        int getColNum();
        int getAllSeats();
        int getAvailableSeats();
        void addSeat(int resAmount);
        void subtractSeat(int resAmount);
        void clearSeats();
        int getReservedSeats();

    private:
        int flightNumber;
        int rowNumber;
        int colNumber;
        int reservedSeats;

};

#endif 
