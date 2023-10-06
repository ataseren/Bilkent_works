/*
* Title: Heaps
* Author: Ata Seren
* ID: 21901575
* Section: 1
* Assignment: 3
* Description: header file for printer simulation
*/
#ifndef __SIMULATOR_H
#define __SIMULATOR_H
#include <iostream>
#include <string>
#include "priorityqueue.h"
using namespace std;

class Simulator {
public:
    Simulator();
	double simulate(int printerAmount, string textname);
    void simulateWithText(int printerAmount, string textname);
};
#endif