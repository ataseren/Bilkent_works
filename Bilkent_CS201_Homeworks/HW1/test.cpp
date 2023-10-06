#include <iostream>
#include "ReservationSystem.h"

using namespace std;

int main()
{

    ReservationSystem R;

    R.showAllFlights();
    R.addFlight(104, 4, 3);
    R.addFlight(234, 8, 3);
    R.addFlight(76, 6, 6);
    cout << endl;
    R.showAllFlights();
    cout << endl;
    R.addFlight(104, 8, 6);
    cout << endl;
    R.showAllFlights();
    cout << endl;
    R.showFlight(104);
    cout << endl;

    int rowRes1[4] = {3, 3, 1, 1};
    char colRes1[4] = {'A', 'B', 'B', 'C'};
    int code1 = R.makeReservation(104, 4, rowRes1, colRes1);

     if (code1 != -1)
        cout << "Your reservation code is " << code1 << endl;

      cout << endl;
      R.showFlight(104);
      cout << endl;

    int rowRes2[2] = {2, 4};
    char colRes2[2] = {'A', 'C'};
    int code2 = R.makeReservation(104, 2, rowRes2, colRes2);

    if (code2 != -1)
        cout << "Your reservation code is " << code2 << endl;

      cout << endl;
      R.showFlight(104);
      cout << endl;

      int rowRes3[2] = {2, 3};
      char colRes3[2] = {'B', 'A'};
      int code3 = R.makeReservation(104, 2, rowRes3, colRes3);

      if (code3 != -1)
            cout << "Your reservation code is " << code3 << endl;

      cout << endl;
      R.showFlight(104);
      cout << endl;

      int rowRes4[7] = {1, 2, 2, 3, 4, 3, 1};
      char colRes4[7] = {'A', 'B', 'C', 'C', 'A', 'B', 'B'};
      int code4 = R.makeReservation(104, 7, rowRes4, colRes4);

      if (code4 != -1)
            cout << "Your reservation code is " << code4 << endl;

      int code5 = R.makeReservation(76, 7, rowRes4, colRes4);

      if (code5 != -1)
            cout << "Your reservation code is " << code5 << endl;

      cout << endl;
      R.showFlight(104);
      cout << endl;


      cout << endl;
      R.showAllFlights();
      cout << endl;

      R.showReservation(100);
      cout << endl;
      R.showReservation(code1);
      cout << endl;
      R.cancelReservation(300);
      cout << endl;
      R.cancelReservation(code2);
      cout << endl;
      R.showFlight(104);
      cout << endl;
      R.showAllFlights();
      cout << endl;
      R.cancelFlight(234);
      R.showFlight(234);
      cout << endl;
      R.showAllFlights();
      cout << endl;
      R.cancelFlight(674);
      cout << endl;
      R.showAllFlights();
      cout << endl;
      R.cancelFlight(104);
      cout << endl;
      R.showReservation(code1);
      cout << endl;
      R.showAllFlights();

    return 0;
}
