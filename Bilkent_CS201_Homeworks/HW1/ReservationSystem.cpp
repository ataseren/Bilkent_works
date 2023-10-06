#include "ReservationSystem.h"
#include "Flight.h"
#include "Reservation.h"
#include <iostream>
#include <string>
using namespace std;

//constructor and destructor
ReservationSystem::ReservationSystem()
{
    flightAmount = 0;
    resAmount = 0;

    flightArray = NULL;
}

ReservationSystem::~ReservationSystem()
{
    if(flightArray != NULL)
    {
        delete[] flightArray;
    }
}

//adds a flight with given flight number and amount of seats determined by row and colon number
void ReservationSystem::addFlight(const int flightNo, const int rowNo, const int colNo)
{
    if(flightArray == NULL)
    {
        flightArray = new Flight[1];
        flightArray[flightAmount].setFlightInfo(flightNo, rowNo, colNo);
        cout << "Flight " << flightNo << " has been added" << endl;

        flightAmount++;
    }
    else
    {
        bool sameFlight = false;
        for(int i = 0; i < flightAmount; i++)
        {
            if(flightArray[i].getFlightNum() == flightNo)
            {
                sameFlight = true;
            }
        }
        if(sameFlight)
        {
            cout << "Flight " << flightNo << " already exists" << endl;
        }
        else
        {
            Flight* tempArray = flightArray;
            flightArray = new Flight[flightAmount + 1];

            for(int i = 0; i < flightAmount; i++)
            {
                flightArray[i] = tempArray[i];
            }
            flightArray[flightAmount].setFlightInfo(flightNo, rowNo, colNo);

            cout << "Flight " << flightNo << " has been added" << endl;

            flightAmount++;

            delete[] tempArray;
        }
    }
}

//cancels flight and reservations under it
void ReservationSystem::cancelFlight(const int flightNo)
{
    bool checkFlight = false;
    for(int a = 0; a < flightAmount; a++)
    {
        if(flightArray[a].getFlightNum() == flightNo)
        {
            checkFlight = true;
        }
    }

    if(!checkFlight)
    {
        cout << "Flight " << flightNo << " does not exist." << endl;
    }
    else
    {
        for(int i = 0; i < flightAmount; i++)
        {
            if(flightArray[i].getFlightNum() == flightNo)
            {
                Flight* tempArray = flightArray;
                flightArray = new Flight[flightAmount - 1];

                for(int j = 0; j < i; j++)
                {
                    flightArray[j] = tempArray[j];
                }
                for(int j = i + 1; j < flightAmount; j++)
                {
                    flightArray[(j - 1)] = tempArray[j];
                }
                
                reservation.wipeReservations(flightNo);

                cout << "Flight " << flightNo << " and all of its reservations are canceled." << endl;

                delete[] tempArray;
                flightAmount--;
                break;
            }
        }
    }  
}
 
//show all added flights
void ReservationSystem::showAllFlights()
{
    if(flightAmount  == 0)
    {
        cout << "No flights exist." << endl;
    }
    else
    {
        cout <<  "Flights currently operated: " << endl;
        for(int i = 0; i < flightAmount; i++)
        {
            cout << "Flight " << flightArray[i].getFlightNum() << " (" << flightArray[i].getAvailableSeats() << " available seats.)" << endl;
        }
    }
}

//shows information of available seats, also a plan of seats for a flight
void ReservationSystem::showFlight( const int flightNo)
{
     if(flightAmount  == 0)
    {
        cout << "No flight exists." << endl;
    }
    else
    {
        bool check = false;

        for(int i = 0; i < flightAmount; i++)
        {
            if(flightArray[i].getFlightNum() == flightNo)
            {
                cout << "Flight " << flightNo << " has " << flightArray[i].getAllSeats() - totalReservations(flightNo) <<  " available seats" << endl;
                showSeatInfo(flightNo);
                check = true;
                break;
            }
        }

        if(!check)
        {
            cout << "Flight " << flightNo << " does not exist." << endl;
        }
    }
}

//makes a reservation under a flight
int ReservationSystem::makeReservation (const int flightNo, const int numPassengers, const int* seatRow, const char* seatCol)
{
    return reservation.addReservation(flightNo, numPassengers, seatRow, seatCol);
}

//shows a reservation under a reservation code
void ReservationSystem::showReservation(const int resCode)
{
    reservation.showReservation(resCode);
}

//shows detailed seat plan for a flight
void ReservationSystem::showSeatInfo(int flightNo)
{
    if(flightAmount != 0)
    {
        for(int i = 0; i < flightAmount; i++)
        {
            if(flightArray[i].getFlightNum() == flightNo)
            {
                for(int j = 0; j < flightArray[i].getColNum() + 1; j++)
                {
                    if( j == 0 )
                    {
                        cout << "  ";
                    }
                    else
                    {
                        cout << intConverter(j) << " " ;
                    }
                }
                cout << endl;

                for(int k = 0; k < flightArray[i].getRowNum(); k++)
                {
                   cout <<  k + 1 << " " ;

                    if(!reservation.checkFlightForReservation(flightNo))
                    {
                        for(int z = 0; z < flightArray[i].getColNum(); z++)
                        {
                            cout << "O ";
                        }
                        cout << endl;
                    }
                    else
                    {
                        for(int z = 0; z < flightArray[i].getColNum(); z++)
                        {
                            if(reservation.isReserved(flightNo, k + 1, z + 1))
                            {
                                cout << "X ";
                            }
                            else
                            {
                                cout <<"O ";
                            }
                        }
                        cout << endl;
                    }
                }

            }
        }
    }
}

//cancels a reservation under a reservation code
void ReservationSystem::cancelReservation(int resCode)
{
    reservation.cancelReservation(resCode);
}

//shows all reservations
int ReservationSystem::totalReservations(int flightNo)
{
    int reservedSeats = 0;

    if(flightAmount != 0)
    {
        for(int i = 0; i < flightAmount; i++)
        {
            if( flightArray[i].getFlightNum() == flightNo )
            {
                for(int j = 0; j < flightArray[i].getRowNum(); j++)
                {
                    for(int k = 0; k < flightArray[i].getColNum(); k++)
                    {
                        if(reservation.isReserved(flightNo, j + 1, k + 1))
                        {
                            reservedSeats++;
                        }
                    }
                }
            }
        }
    }
    return reservedSeats;
}

//converts given int to char for seat information
char ReservationSystem::intConverter( int n )
{
    if (n >= 1 && n <= 26 )
    {
        return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[n-1];
    }
    return '-';
}






