/*
---GraphElement.h
---Ata Seren
---21901575
---Section 2
*/
#ifndef __GRAPHELEMENT_H
#define __GRAPHELEMENT_H
#include <string>
using namespace std;

class GraphElement
{
    public:
        GraphElement();
        GraphElement( string newStart, string newEnd, int newFlightId, int newCost);
        ~GraphElement();
        string getStart();
        string getEnd();
        int getFlightId();
        int getCost();
    private:
        string start;
        string end;
        int flightId;
        int cost; 
};
#endif
