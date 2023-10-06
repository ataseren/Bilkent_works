/*
* Title: Heaps
* Author: Ata Seren
* ID: 21901575
* Section: 1
* Assignment: 3
* Description: main file to find optimum printer amount
*/

#include "simulator.h"
#include "keyeditem.h"
#include "priorityqueue.h"
#include "heap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{   
    //convert maximum average time from command line argument
    //to a double value
    double maxavg = atof(argv[2]);
    Simulator s;
    bool optimum = false;
    int printer = 1;

    //this loop tests different numbers of printers and uses
    //optimum amount of printers and print that simulation
    while(!optimum)
    {
        if(s.simulate(printer,argv[1]) < maxavg)
        {
            optimum = true;
            s.simulateWithText(printer, argv[1]);
            break;
        }
        printer++;
    }
    return 0;
}