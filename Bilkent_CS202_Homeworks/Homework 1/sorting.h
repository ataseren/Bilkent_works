/*
* Title: Sorting and Algorithm Efficiency
* Author: Ata Seren
* ID: 21901575
* Section: 1
* Assignment: 1
* Description: Prototypes for sorting functions, array functions and efficiency testing functions
*/
#ifndef __SORTING_H
#define __SORTING_H
#include <iostream>
#include <string>
using namespace std;


void selectionSort(int *arr, const int size, int &compCount, int &moveCount);
void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
void quickSort(int *arr, const int size, int &compCount, int &moveCount);
void radixSort(int *arr, const int size);

void displayArray(const int *arr, const int size);
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);

void swap(int &x, int &y);
int indexOfLargest(const int theArray[], int size);

void mergesortinside(int theArray[], int first, int last, int &compCount, int &moveCount);
void merge( int theArray[], int first, int mid, int last, int &compCount, int &moveCount);

void quicksortinside(int *arr, int first, int last, int &compCount, int &moveCount);
void partition(int *arr, int first, int last, int &pIndex, int &compCount, int &moveCount);

int getMax(int *arr,int size);
int getDigits(int max);
int myPow(int x, int p);
        
void resetArray(int*arr);

void performanceAnalysis();

#endif