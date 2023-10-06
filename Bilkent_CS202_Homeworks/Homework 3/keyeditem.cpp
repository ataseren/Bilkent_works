/*
* Title: Heaps
* Author: Ata Seren
* ID: 21901575
* Section: 1
* Assignment: 3
* Description: class file for keyeditem class to save requests to heap
*/
#include "keyeditem.h"
#include <iostream>

KeyedItem::KeyedItem():id(0), priority(0), sent(0),processed(0){ }
KeyedItem::KeyedItem(const int& newid, const int& newpri, const int& newsent, const int& newpro):
id(newid),priority(newpri), sent(newsent), processed(newpro){ }

int KeyedItem::getId() const{return id;} 
int KeyedItem::getPriority() const{return priority;} 
int KeyedItem::getSent() const{return sent;} 
int KeyedItem::getProcessed() const{return processed;} 
void KeyedItem::resetItem()
{
    id = 0,
    priority = 0;
    sent = 0;
    processed = 0;
}
