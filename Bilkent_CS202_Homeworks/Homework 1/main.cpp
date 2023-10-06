/*
* Title: Sorting and Algorithm Efficiency
* Author: Ata Seren
* ID: 21901575
* Section: 1
* Assignment: 1
* Description: Runs sorting functions and tests their efficiencies
*/
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sorting.h"
#include <iomanip>
using namespace std;

int main()
{
    int arrTest[] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    int compCount = 0;
    int moveCount = 0;

    cout<<"Array which will be sorted is: ";
    displayArray(arrTest, 16);

    cout<<"Sorting array with selection sort and its result: ";
    selectionSort(arrTest, 16, compCount, moveCount);
    displayArray(arrTest, 16);
    cout<<"Key comparison count: "<<compCount<<endl;
    cout<<"Data moves count: "<<moveCount<<endl;
    resetArray(arrTest);
    compCount = 0;
    moveCount = 0;
    cout<<endl;

    cout<<"Sorting array with merge sort and its result: ";
    mergeSort(arrTest, 16, compCount, moveCount);
    displayArray(arrTest, 16);
    cout<<"Key comparison count: "<<compCount<<endl;
    cout<<"Data moves count: "<<moveCount<<endl;
    resetArray(arrTest);
    compCount = 0;
    moveCount = 0;
    cout<<endl;

    cout<<"Sorting array with quick sort and its result: ";
    quickSort(arrTest, 16, compCount, moveCount);
    displayArray(arrTest, 16);
    cout<<"Key comparison count: "<<compCount<<endl;
    cout<<"Data moves count: "<<moveCount<<endl;
    resetArray(arrTest);
    compCount = 0;
    moveCount = 0;
    cout<<endl;

    cout<<"Sorting array with radix sort and its result: ";
    radixSort(arrTest, 16);
    displayArray(arrTest, 16);
    cout<<endl;
    cout<<endl;
    performanceAnalysis();

    return 0;
}