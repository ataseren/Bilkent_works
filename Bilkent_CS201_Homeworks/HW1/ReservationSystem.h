#ifndef RESERVATIONSYSTEM_H
#define RESERVATIONSYSTEM_H
#include <iostream>
#include "Flight.h"
#include "Reservation.h"
using namespace std;

class ReservationSystem
{
    public:
        ReservationSystem();
        ~ReservationSystem();

        
        void addFlight(const int flightNo, const int rowNo, const int seatNo);
        void cancelFlight(const int flightNo);
        
        void showAllFlights();
        void showFlight(const int flightNo);
        
        int makeReservation(const int flightNo, const int numPassengers, const int *seatRow, const char *seatCol);
        void cancelReservation(const int resCode);
        void showReservation(const int resCode);
    
    private:
        Flight* flightArray;
        Reservation reservation;
        int flightAmount;
        int resAmount;
        
        void showSeatInfo(int flightNo);
        int totalReservations(int flightNo);
        char intConverter(int n);
};

#endif // RESERVATIONSYSTEM_H
