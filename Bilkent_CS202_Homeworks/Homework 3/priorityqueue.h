/*
* Title: Heaps
* Author: Ata Seren
* ID: 21901575
* Section: 1
* Assignment: 3
* Description: header file for priority queue
*/
#ifndef __PRIORITYQUEUE_H
#define __PRIORITYQUEUE_H
#include "heap.h"// ADT heap operations
typedef HeapItemType PQItemType;

class PriorityQueue {
public:
	PriorityQueue(int size);
    ~PriorityQueue();

	// priority-queue operations:
	bool pqIsEmpty() const;
	void pqInsert(const PQItemType& newItem);
	void pqDelete(PQItemType& priorityItem);

private:
	Heap* h;
};
#endif