/*
* Title: Heaps
* Author: Ata Seren
* ID: 21901575
* Section: 1
* Assignment: 3
* Description: class file for max-heap
*/
#include "keyeditem.h"
#include "heap.h"

Heap::Heap(int newsize) 
{
    items = new HeapItemType[newsize];
    maxsize = newsize;
    size = 0;
}

Heap::~Heap() 
{
    delete[] items;
}

bool Heap::heapIsEmpty() const 
{
	return (size == 0);
}

void Heap::heapInsert(const HeapItemType&newItem){

	if (size < maxsize)
	{
        // Place the new item at the end of the heap
        items[size] = newItem;

        // Trickle new item up to its proper position
        int place = size;
        int parent = (place - 1)/2;
        while ( (place > 0) && (items[place].getPriority() > items[parent].getPriority()) ) {
            HeapItemType temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;

            place = parent;
            parent = (place - 1)/2;
        }
        ++size;
    }
}

void Heap::heapDelete(HeapItemType&rootItem)
{
	if (!heapIsEmpty())
	{
		rootItem = items[0];
		items[0] = items[--size];
		heapRebuild(0);
	}
}

void Heap::heapRebuild(int root) 
{   
	int child = 2 * root + 1; 	// index of root's left child, if any
	if ( child < size ) 
    {		
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ( (rightChild < size) && (items[rightChild].getPriority() >items[child].getPriority()) )
        {
			child = rightChild; 	// index of larger child
        }
		// If root’s item is smaller than larger child, swap values
		if ( items[root].getPriority() < items[child].getPriority() ) 
        {
			HeapItemType temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
    	}
		else if(items[root].getPriority() == items[child].getPriority())
		{
			if(items[root].getSent() > items[child].getSent())
			{
				HeapItemType temp = items[root];
				items[root] = items[child];
				items[child] = temp;

				// transform the new subtree into a heap
				heapRebuild(child);
			}
		}
    }
}
