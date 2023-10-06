/*
* Title: Heaps
* Author: Ata Seren
* ID: 21901575
* Section: 1
* Assignment: 3
* Description: header file for max-heap
*/
#ifndef __HEAP_H
#define __HEAP_H
#include "keyeditem.h"// definition of KeyedItem
typedef KeyedItem HeapItemType;

class Heap {
public:
    //Heap();
	Heap(int newsize);
    ~Heap();				// default constructor
	// copy constructor and destructor are supplied by the compiler

	bool heapIsEmpty() const;
	void heapInsert(const HeapItemType& newItem);
	void heapDelete(HeapItemType& rootItem);

protected:
	void heapRebuild(int root);		// Converts the semiheap rooted at 
					        // index root into a heap
private:
	HeapItemType* items;	// array of heap items
    int maxsize;
	int size;            	// number of heap items
};
#endif