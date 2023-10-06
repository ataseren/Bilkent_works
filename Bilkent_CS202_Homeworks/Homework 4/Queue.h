/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Ata Seren
* Id: 21901575
* Section : 1
* Assignment : 4
* Description : header file for queue to implement bft
*/
#ifndef __QUEUE_H
#define __QUEUE_H
class Queue
{
    public:
        Queue();                     // default constructor
        Queue(const Queue& Q);       // copy constructor
        ~Queue();                    // destructor

        // Queue operations:
        bool isEmpty() const;
        bool enqueue(int newItem);
        bool dequeue();
        bool dequeue(int& queueFront);
        bool getFront(int& queueFront) const;

    private:
        // The queue is implemented as a linked list with one external 
        // pointer to the front of the queue and a second external 
        // pointer to the back of the queue.

        struct QueueNode{
            int  item;
            QueueNode     *next;
        };
        QueueNode *backPtr;
        QueueNode *frontPtr;
};
#endif
