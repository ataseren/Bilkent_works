/*
* Title: Heaps
* Author: Ata Seren
* ID: 21901575
* Section: 1
* Assignment: 3
* Description: header file for keyeditem class to save requests to heap
*/
#ifndef __KEYEDITEM_H
#define __KEYEDITEM_H
#include <iostream>

class KeyedItem {
public:
		KeyedItem(); 
		KeyedItem(const int& newid, const int& newpri, const int& newsent, const int& newpro);

		int getId() const; 
        int getPriority() const; 
        int getSent() const; 
        int getProcessed() const; 
        void resetItem();

private:
		int id;
        int priority;
        int sent;
        int processed;
};
#endif