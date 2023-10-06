/*
---Stack.h
---Ata Seren
---21901575
---Section 2
*/
#ifndef __STACK_H
#define __STACK_H
#include "City.h"


class Stack 
{
	public:
		Stack();
		~Stack();
		bool isEmpty() const;
		bool push( City newItem );
		bool pop();
		bool pop( City& stackTop );
		bool getTop( City& stackTop ) const;
		City** getItems(int length);  
		
	private:
		struct StackNode
		{
			City item;
			StackNode *next;
		};
		StackNode *topPtr;
		
};
#endif
