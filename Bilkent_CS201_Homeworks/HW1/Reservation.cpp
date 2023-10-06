#include "Reservation.h"
#include <iostream>
#include <string>
using namespace std;

//constructor and destructor
Reservation::Reservation()
{
    passengerArr = NULL;
    flightNumArr = NULL;  
    rowArr = NULL;
    colArr = NULL;
    totalReservations = 0;
}

Reservation::~Reservation()
{
        if(passengerArr != NULL)
        {
            delete[] passengerArr;
        }

        if(flightNumArr != NULL)
        {
            delete[] flightNumArr;
        }

        for(int i = 0; i < totalReservations; i++)
        {
            if(rowArr[i] != NULL)
            {
                delete[] rowArr[i];
            }

            if(colArr[i] != NULL)
            {
                delete[] colArr[i];
            }
        }
        if(rowArr != NULL)
            {
                delete[] rowArr;
            }
        if(colArr != NULL)
            {
                delete[] colArr;
            }
}

//deletes reservations under a flight
void Reservation::wipeReservations(const int flightNo)
{
    if(totalReservations > 0)
    {
        for (int i  = 0; i < totalReservations; i++)
        {
            if(flightNumArr[i] == flightNo)
            {
                cancelResNoReturn(i  + 1);
            }
        }
    }
    else
    {
        cout <<"There are no flights."<< endl;
    }
}

//cancels a specific reservation under a reservation code
void Reservation::cancelReservation(int resCode)
{
    resCode--;
    if(resCode >= 0 && resCode <= totalReservations)
    {
        cout <<"Reservation for the seats ";

        for(int i = 0; i < passengerArr[resCode]; i++)
        {
            cout  << rowArr[resCode][i] << intConverter(colArr[resCode][i]) << " ";
        }

        cout <<"canceled in flight "<< flightNumArr[resCode] << endl;
        
        passengerArr[resCode] = 0;
        flightNumArr[resCode] = 0;
        
        if(rowArr[resCode] != NULL )
        {
            delete[] rowArr[resCode];
        }
        if(colArr[resCode] != NULL)
        {
            delete[] colArr[resCode];
        }
        rowArr[resCode] = NULL;
        colArr[resCode] = NULL;
    }
    else
    {
        cout <<"No reservation under code: "<< resCode + 1 << endl;
    }
}

//cancelReservation() but doesn't return a sentence
void Reservation::cancelResNoReturn(int resCode)
{
    if(resCode > 0 && resCode <= totalReservations)
    {
        passengerArr[resCode - 1] = 0;
        flightNumArr[resCode - 1] = 0;
        
        if(rowArr[resCode - 1] != NULL )
        {
            delete[] rowArr[resCode - 1];
        }
        if(colArr[resCode - 1] != NULL)
        {
            delete[] colArr[resCode - 1];
        }
        rowArr[resCode - 1] = NULL;
        colArr[resCode - 1]  = NULL;
    }
}

//shows information of a reservation under a reservation code
void Reservation::showReservation(const int resCode)
{
    if( passengerArr[resCode - 1] != 0)
    {
        if(resCode -  1 <= totalReservations )
        {
            cout <<"Reservations under code "<< resCode <<" in flight "<< flightNumArr[resCode - 1] <<": "<<endl;

            for(int i = 0; i < passengerArr[resCode - 1]; i++)
            {
                cout << rowArr[resCode - 1][i] << intConverter(colArr[resCode - 1][i]) ;
                if(i != passengerArr[resCode - 1] - 1)
                {
                    cout << endl;
                }
            }
            cout << endl;
        }
        else
        {
            cout <<"No reservation under code "<< resCode << endl;
        }
    }
    else
    {
        cout <<"No reservation under code "<< resCode << endl;
    }
}

//adds a reservation
int Reservation::addReservation(const int flightNo, const int numPassengers, const int* seatRow, const char* seatCol)
{
    if(totalReservations == 0)
    {
        
        passengerArr = new int[1];
        flightNumArr = new int[1]; 
        rowArr = new int*[1];
        colArr = new int*[1];
        
        passengerArr[totalReservations] = numPassengers;
        flightNumArr[totalReservations] = flightNo;
        
        rowArr[totalReservations] = new int[numPassengers];
        colArr[totalReservations] = new int[numPassengers];

        for(int i = 0; i < numPassengers; i++)
        {
            rowArr[totalReservations][i] = seatRow[i];
            colArr[totalReservations][i] = letterConverter(seatCol[i]);
        }
        totalReservations++;
        return totalReservations;
    }
    else
    {
        int reservedCounter = 0;
        bool checkReserved = false;

        for(int i = 0; i < numPassengers; i++)
        {
            if(isReserved(flightNo,seatRow[i] , letterConverter(seatCol[i])))
            {
                checkReserved = true;
                reservedCounter++;
                cout << seatRow[i] << seatCol[i] << " " ;
            }
        }
        if(!checkReserved)
        {
            int* tempFlightNoArr = flightNumArr;
            int* tempPassengerArr = passengerArr;
            int** tempRowArr = rowArr;
            int** tempColArr = colArr;

            flightNumArr = new int[totalReservations + 1];
            passengerArr = new int[totalReservations + 1];
            rowArr = new int*[totalReservations + 1];
            colArr = new int*[totalReservations + 1];

            for(int i = 0; i < totalReservations; i++)
            {
                passengerArr[i] = tempPassengerArr[i];
                flightNumArr[i] = tempFlightNoArr[i];
                
                rowArr[i] = new int[passengerArr[i]];
                colArr[i] = new int[passengerArr[i]];

                for(int j = 0; j < passengerArr[i]; j++)
                {
                    rowArr[i][j] = tempRowArr[i][j];
                    colArr[i][j]  = tempColArr[i][j];
                }
            }

            flightNumArr[totalReservations] = flightNo;
            passengerArr[totalReservations] = numPassengers;

            rowArr[totalReservations] = new int[numPassengers];
            colArr[totalReservations] = new int[numPassengers];

            for(int i = 0; i < numPassengers; i++)
            {
                rowArr[totalReservations][i] = seatRow[i];
                colArr[totalReservations][i] = letterConverter(seatCol[i]);
            }

            delete[] tempPassengerArr;
            delete[] tempFlightNoArr;

            for (int i = 0; i < totalReservations; i++)
            {
                delete[] tempRowArr[i];
                delete[] tempColArr[i];
            }

            delete[] tempRowArr;
            delete[] tempColArr;

            totalReservations++;
            return totalReservations;
        }
        else
        {
            if(reservedCounter == 1)
            {
                cout <<"is not available."<< endl;
                return -1;
            }
            else
            {
                cout <<"are not available."<< endl;
                return -1;
            }

        }
    }
}

//checks a specific flight if there is a reservation under it
bool Reservation::checkFlightForReservation(const int flightNo)
{
    if(totalReservations == 0) 
    {
        return false;
    }

    for(int i = 0; i < totalReservations; i++)
    {
        if(flightNumArr[i] == flightNo) 
        {
            return true;
        }
    }

    return false;
}

//converts given char to int for seat information
int Reservation::letterConverter(const char input)
{
    return (input - 'A') + 1;
}

bool Reservation::isReserved(const int flightNo, const int rowInput, const int colInput)
{
    if(totalReservations == 0)
    {
        return false;
    }
    else
    {
        for(int i = 0; i < totalReservations; i++)
        {
            if(flightNumArr[i] == flightNo)
            {
                for(int j = 0; j < passengerArr[i]; j++)
                {
                    if(rowArr[i][j] == rowInput && colArr[i][j] == colInput)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

//converts given int to char for seat information
char Reservation::intConverter(const int input)
{
    if (input >= 1 && input <= 26 )
    {
        return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[input - 1];
    }
    return '-';
}

