#include "Flight.h"
#include <iostream>
using namespace std;

//constructors and destructor
Flight::Flight()
{
    this->flightNumber = 0;
    this->rowNumber = 0;
    this->colNumber = 0;
    this->reservedSeats = 0;
}

Flight::Flight(int flightNum, int rowNum, int colonNum)
{
    this->flightNumber = flightNum;
    this->rowNumber = rowNum;
    this->colNumber = colonNum;
    this->reservedSeats = 0;
}

Flight::~Flight()
{
}

//set flight number and amount of seats determined by row and colon numbers
void Flight::setFlightInfo(int newFlightNum, int newRowNum, int newColonNum)
{
    this->flightNumber = newFlightNum;
    this->rowNumber = newRowNum;
    this->colNumber = newColonNum;
}

//returns flight number
int Flight::getFlightNum()
{
    return this->flightNumber;
}

//returns row number
int Flight::getRowNum()
{
    return this->rowNumber;
}

//returns colon number
int Flight::getColNum()
{
    return this->colNumber;
}

//returns number of seats
int Flight::getAllSeats()
{
    return rowNumber * colNumber;
}

//return number of available seats
int Flight::getAvailableSeats()
{
    return ((rowNumber * colNumber) - reservedSeats);
}

//returns number of reserved seats
int Flight::getReservedSeats()
{
    return reservedSeats;
}

//increases number of reserved seats
void Flight::addSeat(int resAmount)
{
    this->reservedSeats = this->reservedSeats + resAmount;
}

//decreases number of reserved seats
void Flight::subtractSeat(int resAmount)
{
    this->reservedSeats = this->reservedSeats - resAmount;
}

//empty all seats
void Flight::clearSeats()
{
    this->reservedSeats = 0;
}





