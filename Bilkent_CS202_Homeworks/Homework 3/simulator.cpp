/*
* Title: Heaps
* Author: Ata Seren
* ID: 21901575
* Section: 1
* Assignment: 3
* Description: class file for printer simulation
*/
#include "simulator.h"
#include "keyeditem.h"
#include "priorityqueue.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Simulator::Simulator(){}

double Simulator::simulate(int printerAmount, string textname)
{   
    //open file for reading
    ifstream input(textname.c_str());
    int requestAmount;
    input>>requestAmount;
    PriorityQueue* queue = new PriorityQueue(requestAmount);
    
    //variables for data
    int id;
    int priority;
    int sent;
    int processed;
    int time = 1;
    int wait = 0;
    KeyedItem temp;
    KeyedItem* printer = new KeyedItem[printerAmount];
    int* printerTime = new int[printerAmount];
    
    //start reading
    while(input>>id>>priority>>sent>>processed)
    {
        if(time == sent)
        {
            //insert queue
            KeyedItem newItem(id, priority, sent, processed);
            queue->pqInsert(newItem);
        }
        else
        {
            do{ 
                //empty printers when time comes
                for (int i = 0; i < printerAmount; i++)
                {
                    if(time == printerTime[i] + printer[i].getProcessed())
                    {
                        printer[i].resetItem();
                        printerTime[i] = 0;
                    }
                }

                if(time == sent)
                {
                    //insert queue
                    KeyedItem newItem(id, priority, sent, processed);
                    queue->pqInsert(newItem);
                }

                for (int i = 0; i < printerAmount; i++)
                {
                    if(printer[i].getId() == 0)
                    {
                        if(!(queue->pqIsEmpty()))
                        {   
                            //take from queue
                            queue->pqDelete(temp);
                            printer[i] = temp;
                            printerTime[i] = time;
                            wait = wait + time - temp.getSent();
                        }
                    }
                }

            //increase time    
            }while(time++ != sent);
        }
    }
    input.close();

    //even file ends, there may be requests in queue
    //to process them, we use this while loop
    while(!(queue->pqIsEmpty()))
    {
        //empty printers when time comes
        for (int i = 0; i < printerAmount; i++)
        {
            if(time == printerTime[i] + printer[i].getProcessed())
            {
                printer[i].resetItem();
                printerTime[i] = 0;
            }
        }
        
        //take from queue
        for (int i = 0; i < printerAmount; i++)
        {
            if(printer[i].getId() == 0)
            {
                if(!queue->pqIsEmpty())
                {
                    queue->pqDelete(temp);
                    printer[i] = temp;
                    printerTime[i] = time;
                    wait = wait + time - temp.getSent();
                }
            }
        }
        time++;
    }
    
    //calculate average
    double result = (double) wait; 
    result = result/requestAmount;
    delete queue;
    delete[] printer;
    delete[] printerTime;
    return result;
}

//this function is very similar to above
//only difference is that it prints to show process of simulation
void Simulator::simulateWithText(int printerAmount, string textname)
{
    cout<<"Minimum number of printers required: "<<printerAmount<<endl;
    cout<<endl;
    ifstream input(textname.c_str());
    int requestAmount;
    input>>requestAmount;
    PriorityQueue* queue = new PriorityQueue(requestAmount);
    
    int id;
    int priority;
    int sent;
    int processed;
    int time = 1;
    int wait = 0;
    KeyedItem temp;
    KeyedItem* printer = new KeyedItem[printerAmount];
    int* printerTime = new int[printerAmount];
    cout<<"Simulation with "<<printerAmount<<" printers:"<<endl;
    cout<<endl;
    while(input>>id>>priority>>sent>>processed)
    {
        if(time == sent)
        {
            KeyedItem newItem(id, priority, sent, processed);
            queue->pqInsert(newItem);
        }
        else
        {
            do{
                for (int i = 0; i < printerAmount; i++)
                {
                    if(time == printerTime[i] + printer[i].getProcessed())
                    {
                        printer[i].resetItem();
                        printerTime[i] = 0;
                    }
                }

                if(time == sent)
                {
                    KeyedItem newItem(id, priority, sent, processed);
                    queue->pqInsert(newItem);
                }

                for (int i = 0; i < printerAmount; i++)
                {
                    if(printer[i].getId() == 0)
                    {
                        if(!(queue->pqIsEmpty()))
                        {
                            queue->pqDelete(temp);
                            printer[i] = temp;
                            printerTime[i] = time;
                            wait = wait + time - temp.getSent();
                            cout<<"Printer "<< i << " prints print request "<< temp.getId()<< " at minute "<< time <<" (wait: "<<time - temp.getSent()<<" mins)"<<endl;
                        }
                    }
                }

                
            }while(time++ != sent);
        }
    }
    input.close();

    while(!(queue->pqIsEmpty()))
    {
        for (int i = 0; i < printerAmount; i++)
        {
            if(time == printerTime[i] + printer[i].getProcessed())
            {
                printer[i].resetItem();
                printerTime[i] = 0;
            }
        }
        
        for (int i = 0; i < printerAmount; i++)
        {
            if(printer[i].getId() == 0)
            {
                if(!queue->pqIsEmpty())
                {
                    queue->pqDelete(temp);
                    printer[i] = temp;
                    printerTime[i] = time;
                    wait = wait + time - temp.getSent();
                    cout<<"Printer "<< i << " prints print request "<< temp.getId()<< " at minute "<< time <<" (wait: "<<time - temp.getSent()<<" mins)"<<endl;
                }
            }
        }
        time++;
    }
    double result = (double) wait; 
    result = result/requestAmount;
    delete queue;
    delete[] printer;
    delete[] printerTime;
    cout<<endl;
    cout<<"Average waiting time: "<< result <<" minutes"<<endl;
}