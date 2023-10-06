/*
* Title: Heaps
* Author: Ata Seren
* ID: 21901575
* Section: 1
* Assignment: 3
* Description: class file for heap-based priority queue
*/
#include "priorityqueue.h"
#include "heap.h"

PriorityQueue::PriorityQueue(int size)
{
    h = new Heap(size);
}

PriorityQueue::~PriorityQueue()
{
    delete h;
}
bool PriorityQueue::pqIsEmpty() const 
{
	return h->heapIsEmpty();
}

void PriorityQueue::pqInsert(const PQItemType& newItem)
{
	h->heapInsert(newItem);
}

void PriorityQueue::pqDelete(PQItemType& priorityItem)
{
	h->heapDelete(priorityItem);

}
