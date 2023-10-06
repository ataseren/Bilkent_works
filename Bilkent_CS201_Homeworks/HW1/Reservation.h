#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include "Flight.h"
using namespace std;

class Reservation
{ 
    public:
        Reservation();
        ~Reservation();

        int addReservation(const int flightNo, const int numPassengers, const int *seatRow, const char *seatCol);
        void wipeReservations(const int flightNo);
        void cancelReservation(int resCode);
        void cancelResNoReturn(int resCode);
        void showReservation(const int resCode);
        
        bool checkFlightForReservation(const int flightNo);
        bool isReserved(const int flightNo, const int rowInput, const int colInput);
        char intConverter(const int n);
        int letterConverter(const char input);


    private:
        int totalReservations;
        int* passengerArr;
        int* flightNumArr;
        int** rowArr;
        int** colArr;
};

#endif



