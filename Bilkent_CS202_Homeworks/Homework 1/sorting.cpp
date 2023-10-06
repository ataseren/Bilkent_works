/*
* Title: Sorting and Algorithm Efficiency
* Author: Ata Seren
* ID: 21901575
* Section: 1
* Assignment: 1
* Description: Contains methods of sorting ,array and performance analysis
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "sorting.h"
using namespace std;



void selectionSort(int *arr, const int size, int &compCount, int &moveCount) 
{
    for (int last = size-1; last >= 1; --last) 
    {
        int largest = indexOfLargest(arr, last+1);
        compCount = compCount + last;
        swap(arr[largest], arr[last]);
        moveCount = moveCount + 3;
    }
}

void swap(int &x, int &y) 
{
   int temp = x;
   x = y;
   y = temp;
}

int indexOfLargest(const int theArray[], int size)
{
    int indexSoFar = 0; 
    for (int currentIndex=1; currentIndex<size;++currentIndex)
    {
        if (theArray[currentIndex] > theArray[indexSoFar])
        {
            indexSoFar = currentIndex;
        }
    }
    return indexSoFar; 
}

void mergeSort(int *arr, const int size, int &compCount, int &moveCount)
{
    int first = 0;
    int last = size - 1;
    mergesortinside(arr, first, last, compCount, moveCount);
}

void mergesortinside(int theArray[], int first, int last,  int &compCount, int &moveCount)
{
    if (first < last) 
    {
        int mid = (first + last)/2; 

        mergesortinside(theArray, first, mid, compCount, moveCount);

        mergesortinside(theArray, mid+1, last, compCount, moveCount);

        merge(theArray, first, mid, last, compCount, moveCount);
   }
}

void merge( int theArray[], int first, int mid, int last, int &compCount, int &moveCount)
{
    int temp[last+1];
   
	int first1 = first; 	
    int last1 = mid; 		
    int first2 = mid + 1;	
    int last2 = last;		
    moveCount+=4;
    
    int index = first1;

    for ( ; (first1 <= last1) && (first2 <= last2); ++index) 
    {
        if (theArray[first1] < theArray[first2]) 
        {  
            temp[index] = theArray[first1];
            ++first1;
        }
        else 
        {  
            temp[index] = theArray[first2];
            ++first2;
        }
        moveCount+=1;
		compCount++;
    }
    // finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, ++index)
    {
        temp[index] = theArray[first1];
        moveCount+=1;
    }
    // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index)
    {
        temp[index] = theArray[first2];
        moveCount+=1;
    }
    // copy the result back into the original array
    for (index = first; index <= last; ++index)
    {
        theArray[index] = temp[index];
        moveCount++;
    }
}

void quickSort(int *arr, const int size, int &compCount, int &moveCount)
{
    quicksortinside(arr, 0, size-1, compCount, moveCount);
}



void quicksortinside(int *theArray, int first, int last, int &compCount, int &moveCount) {
// Precondition: theArray[first..last] is an array.
// Postcondition: theArray[first..last] is sorted.

    int pivotIndex;

    if (first < last) {

        // create the partition: S1, pivot, S2
        partition(theArray, first, last, pivotIndex, compCount, moveCount);

        // sort regions S1 and S2
        quicksortinside(theArray, first, pivotIndex-1, compCount, moveCount);
        quicksortinside(theArray, pivotIndex+1, last, compCount, moveCount);
   }
   compCount++;
}

void partition(int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount) 
{
    int pivot = arr[first]; 
    moveCount++;
    int lastS1 = first;
    int firstUnknown = first + 1; 
    for (; firstUnknown <= last; ++firstUnknown) 
    {
        compCount++; 
        if (arr[firstUnknown] < pivot) 
        { 
            ++lastS1;
            swap(arr[firstUnknown], arr[lastS1]);
            moveCount+=3;
        }
    }
    swap(arr[first], arr[lastS1]);
    moveCount+=3;
    pivotIndex = lastS1;
}

void radixSort(int *arr, int size)
{
    int n = size;
    int max = getMax(arr,size);
    int d = getDigits(max);

    for(int j = 1; j <= d; j++)
    {
        int groups[10][size];
        for( int a = 0; a < 10; a++)
        {
            for( int b = 0; b < size; b++)
            {
                groups[a][b] = 0;
            }
        }

        int counter[10] = {0,0,0,0,0,0,0,0,0,0};
        for(int i = 0; i < n; i++)
        {
            int k = 0;
            if(j == 1 )
            {
                k = arr[i]%10;
            }
            else 
            {
                k = arr[i]/myPow(10,j-1);
                k = k % myPow(10,j-1);
            }

            if (k > 9)
            {
                groups[0][counter[0]] = arr[i];
                counter[0] += 1;
            }
            else
            {
                groups[k][counter[k]] = arr[i];
                counter[k] += 1;
            }
        }

        int index = 0;
        for(int i = 0; i <10;i++)
        {
            for(int j = 0; j < counter[i]; j++)
            {
                arr[index] = groups[i][j];
                index++;
            }
        }
    }
}

int getMax(int * arr,int size)
{
    int max = -999;
    for(int i = 0;i < size;i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

int getDigits(int max)
{
    if(max < 10)
    {
        return 1;
    }
    else
    {
        return 1 + getDigits(max/10);
    }
}

int myPow(int x, int p) 
{
    int result = 1;
    if(p == 0)
    {
        return 1;
    }
    for( int i = 0;i < p;i++)
    {
        result = result * x;
    }
    return result;
}


void displayArray(const int *arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size)
{
    for (int i = 0; i < size; i++)
    {
        int element = rand();
        arr1[i] = element;
        arr2[i] = element;
        arr3[i] = element;
        arr4[i] = element;
    }  
}


void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size)
{
    for (int i = 0; i < size; i++)
    {
        arr1[i] = i;
        arr2[i] = i;
        arr3[i] = i;
        arr4[i] = i;
    }
}


void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size)
{
    for (int i = 0; i < size; i++)
    {
        arr1[i] = size-i;
        arr2[i] = size-i;
        arr3[i] = size-i;
        arr4[i] = size-i;
    }
}


void resetArray(int *arr)
{
    int arrDefault[] = {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
    for (int i = 0; i < 16; i++)
    {
        arr[i] = arrDefault[i];
    }   
}


void performanceAnalysis()
{
    int compCount = 0; int moveCount = 0;
    
    int *arr6000_1 = new int[6000]; int *arr6000_2 = new int[6000]; int *arr6000_3 = new int[6000]; int *arr6000_4 = new int[6000]; 
    int *arr10000_1 = new int[10000]; int *arr10000_2 = new int[10000]; int *arr10000_3 = new int[10000]; int *arr10000_4 = new int[10000]; 
    int *arr14000_1 = new int[14000]; int *arr14000_2 = new int[14000]; int *arr14000_3 = new int[14000]; int *arr14000_4 = new int[14000]; 
    int *arr18000_1 = new int[18000]; int *arr18000_2 = new int[18000]; int *arr18000_3 = new int[18000]; int *arr18000_4 = new int[18000]; 
    int *arr22000_1 = new int[22000]; int *arr22000_2 = new int[22000]; int *arr22000_3 = new int[22000]; int *arr22000_4 = new int[22000]; 
    int *arr26000_1 = new int[26000]; int *arr26000_2 = new int[26000]; int *arr26000_3 = new int[26000]; int *arr26000_4 = new int[26000];
    int *arr30000_1 = new int[30000]; int *arr30000_2 = new int[30000]; int *arr30000_3 = new int[30000]; int *arr30000_4 = new int[30000]; 

    createRandomArrays(arr6000_1, arr6000_2, arr6000_3, arr6000_4, 6000);
    createRandomArrays(arr10000_1, arr10000_2, arr10000_3, arr10000_4, 10000);
    createRandomArrays(arr14000_1, arr14000_2, arr14000_3, arr14000_4, 14000);
    createRandomArrays(arr18000_1, arr18000_2, arr18000_3, arr18000_4, 18000);
    createRandomArrays(arr22000_1, arr22000_2, arr22000_3, arr22000_4, 22000);
    createRandomArrays(arr26000_1, arr26000_2, arr26000_3, arr26000_4, 26000);
    createRandomArrays(arr30000_1, arr30000_2, arr30000_3, arr30000_4, 30000);
    
    cout<<"For random arrays:"<<endl;
    cout<<"Analysis of Selection Sort"<<endl;
    cout << "Array Size" << setw(16) << "Elapsed time" << setw(20) << "compCount" << setw(20) << "moveCount" <<endl;
    clock_t startTime = clock();
    selectionSort(arr6000_1, 6000, compCount, moveCount);
    double duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 6000 << setw(16) << duration <<" ms"<< setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    selectionSort(arr10000_1, 10000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 10000 << setw(16) << duration <<" ms"<< setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    selectionSort(arr14000_1, 14000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 14000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    selectionSort(arr18000_1, 18000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 18000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    selectionSort(arr22000_1, 22000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 22000 << setw(16) << duration <<" ms"<< setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    selectionSort(arr26000_1, 26000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 26000 << setw(16) << duration <<" ms"<< setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    selectionSort(arr30000_1, 30000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 30000 << setw(16) << duration <<" ms"<< setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    cout<<"Analysis of Merge Sort"<<endl;
    cout << "Array Size" << setw(16) << "Elapsed time" << setw(20) << "compCount" << setw(20) << "moveCount" <<endl;

    startTime = clock();
    mergeSort(arr6000_2, 6000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 6000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    mergeSort(arr10000_2, 10000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 10000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    mergeSort(arr14000_2, 14000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 14000 << setw(16) << duration <<" ms"<< setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    mergeSort(arr18000_2, 18000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 18000 << setw(16) << duration <<" ms"<< setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    mergeSort(arr22000_2, 22000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 22000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    mergeSort(arr26000_2, 26000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 26000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    mergeSort(arr30000_2, 30000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 30000 << setw(16) << duration <<" ms"<< setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;
    
    cout<<"Analysis of Quick Sort"<<endl;
    cout << "Array Size" << setw(16) << "Elapsed time" << setw(20) << "compCount" << setw(20) << "moveCount" <<endl;

    startTime = clock();
    quickSort(arr6000_3, 6000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 6000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    quickSort(arr10000_3, 10000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 10000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    quickSort(arr14000_3, 14000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 14000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    quickSort(arr18000_3, 18000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 18000 << setw(16) << duration <<" ms"<< setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    quickSort(arr22000_3, 22000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 22000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    quickSort(arr26000_3, 26000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 26000 << setw(16) << duration <<" ms"<< setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    quickSort(arr30000_3, 30000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 30000 << setw(16) << duration <<" ms"<< setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    cout<<"Analysis of Radix Sort"<<endl;
    cout << "Array Size" << setw(16) << "Elapsed time" <<endl;

    startTime = clock();
    radixSort(arr6000_4, 6000);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 6000 << setw(16) << duration <<" ms"<<endl;

    startTime = clock();
    radixSort(arr10000_4, 10000);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 10000 << setw(16) << duration <<" ms"<<endl;

    startTime = clock();
    radixSort(arr14000_4, 14000);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 14000 << setw(16) << duration <<" ms"<<endl;

    startTime = clock();
    radixSort(arr18000_4, 18000);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 18000 << setw(16) << duration <<" ms"<<endl;

    startTime = clock();
    radixSort(arr22000_4, 22000);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 22000 << setw(16) << duration <<" ms"<<endl;

    startTime = clock();
    radixSort(arr26000_4, 26000);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 26000 << setw(16) << duration << " ms"<<endl;

    startTime = clock();
    radixSort(arr30000_4, 30000);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 30000 << setw(16) << duration <<" ms"<<endl;
    cout<<endl;
    
    createAscendingArrays(arr6000_1, arr6000_2, arr6000_3, arr6000_4, 6000);
    createAscendingArrays(arr10000_1, arr10000_2, arr10000_3, arr10000_4, 10000);
    createAscendingArrays(arr14000_1, arr14000_2, arr14000_3, arr14000_4, 14000);
    createAscendingArrays(arr18000_1, arr18000_2, arr18000_3, arr18000_4, 18000);
    createAscendingArrays(arr22000_1, arr22000_2, arr22000_3, arr22000_4, 22000);
    createAscendingArrays(arr26000_1, arr26000_2, arr26000_3, arr26000_4, 26000);
    createAscendingArrays(arr30000_1, arr30000_2, arr30000_3, arr30000_4, 30000);

    cout<<"For ascending arrays:"<<endl;
    cout<<"Analysis of Selection Sort"<<endl;
    cout << "Array Size" << setw(16) << "Elapsed time" << setw(20) << "compCount" << setw(20) << "moveCount" <<endl;
    startTime = clock();
    selectionSort(arr6000_1, 6000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 6000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    selectionSort(arr10000_1, 10000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 10000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    selectionSort(arr14000_1, 14000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 14000 << setw(16) << duration <<" ms"<< setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    selectionSort(arr18000_1, 18000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 18000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    selectionSort(arr22000_1, 22000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 22000 << setw(16) << duration <<" ms"<< setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    selectionSort(arr26000_1, 26000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 26000 << setw(16) << duration <<" ms"<< setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    selectionSort(arr30000_1, 30000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 30000 << setw(16) << duration <<" ms"<< setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    cout<<"Analysis of Merge Sort"<<endl;
    cout << "Array Size" << setw(16) << "Elapsed time" << setw(20) << "compCount" << setw(20) << "moveCount" <<endl;

    startTime = clock();
    mergeSort(arr6000_2, 6000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 6000 << setw(16) << duration <<" ms"<< setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    mergeSort(arr10000_2, 10000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 10000 << setw(16) << duration <<" ms"<< setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    mergeSort(arr14000_2, 14000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 14000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    mergeSort(arr18000_2, 18000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 18000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    mergeSort(arr22000_2, 22000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 22000 << setw(16) << duration <<" ms"<< setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    mergeSort(arr26000_2, 26000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 26000 << setw(16) << duration <<" ms"<< setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    mergeSort(arr30000_2, 30000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 30000 << setw(16) << duration <<" ms"<< setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;
    
    cout<<"Analysis of Quick Sort"<<endl;
    cout << "Array Size" << setw(16) << "Elapsed time" << setw(20) << "compCount" << setw(20) << "moveCount" <<endl;

    startTime = clock();
    quickSort(arr6000_3, 6000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 6000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    quickSort(arr10000_3, 10000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 10000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    quickSort(arr14000_3, 14000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 14000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    quickSort(arr18000_3, 18000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 18000 << setw(16) << duration <<" ms"<< setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    quickSort(arr22000_3, 22000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 22000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    quickSort(arr26000_3, 26000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 26000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    quickSort(arr30000_3, 30000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 30000 << setw(16) << duration <<" ms"<< setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    cout<<"Analysis of Radix Sort"<<endl;
    cout << "Array Size" << setw(16) << "Elapsed time" <<endl;

    startTime = clock();
    radixSort(arr6000_4, 6000);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 6000 << setw(16) << duration <<" ms"<<endl;

    startTime = clock();
    radixSort(arr10000_4, 10000);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 10000 << setw(16) << duration <<" ms"<<endl;

    startTime = clock();
    radixSort(arr14000_4, 14000);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 14000 << setw(16) << duration <<" ms"<<endl;

    startTime = clock();
    radixSort(arr18000_4, 18000);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 18000 << setw(16) << duration <<" ms"<<endl;

    startTime = clock();
    radixSort(arr22000_4, 22000);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 22000 << setw(16) << duration <<" ms"<<endl;

    startTime = clock();
    radixSort(arr26000_4, 26000);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 26000 << setw(16) << duration << " ms"<<endl;

    startTime = clock();
    radixSort(arr30000_4, 30000);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 30000 << setw(16) << duration <<" ms"<<endl;
    cout<<endl;

    createDescendingArrays(arr6000_1, arr6000_2, arr6000_3, arr6000_4, 6000);
    createDescendingArrays(arr10000_1, arr10000_2, arr10000_3, arr10000_4, 10000);
    createDescendingArrays(arr14000_1, arr14000_2, arr14000_3, arr14000_4, 14000);
    createDescendingArrays(arr18000_1, arr18000_2, arr18000_3, arr18000_4, 18000);
    createDescendingArrays(arr22000_1, arr22000_2, arr22000_3, arr22000_4, 22000);
    createDescendingArrays(arr26000_1, arr26000_2, arr26000_3, arr26000_4, 26000);
    createDescendingArrays(arr30000_1, arr30000_2, arr30000_3, arr30000_4, 30000);

    cout<<"For descending arrays:"<<endl;
    cout<<"Analysis of Selection Sort"<<endl;
    cout << "Array Size" << setw(16) << "Elapsed time" << setw(20) << "compCount" << setw(20) << "moveCount" <<endl;
    startTime = clock();
    selectionSort(arr6000_1, 6000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 6000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    selectionSort(arr10000_1, 10000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 10000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    selectionSort(arr14000_1, 14000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 14000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    selectionSort(arr18000_1, 18000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 18000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    selectionSort(arr22000_1, 22000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 22000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    selectionSort(arr26000_1, 26000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 26000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    selectionSort(arr30000_1, 30000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 30000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    cout<<"Analysis of Merge Sort"<<endl;
    cout << "Array Size" << setw(16) << "Elapsed time" << setw(20) << "compCount" << setw(20) << "moveCount" <<endl;

    startTime = clock();
    mergeSort(arr6000_2, 6000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 6000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    mergeSort(arr10000_2, 10000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 10000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    mergeSort(arr14000_2, 14000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 14000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    mergeSort(arr18000_2, 18000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 18000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    mergeSort(arr22000_2, 22000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 22000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    mergeSort(arr26000_2, 26000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 26000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    mergeSort(arr30000_2, 30000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 30000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;
    
    cout<<"Analysis of Quick Sort"<<endl;
    cout << "Array Size" << setw(16) << "Elapsed time" << setw(20) << "compCount" << setw(20) << "moveCount" <<endl;

    startTime = clock();
    quickSort(arr6000_3, 6000, compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 6000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    quickSort(arr10000_3, 10000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 10000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    quickSort(arr14000_3, 14000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 14000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    quickSort(arr18000_3, 18000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 18000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    quickSort(arr22000_3, 22000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 22000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    quickSort(arr26000_3, 26000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 26000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    startTime = clock();
    quickSort(arr30000_3, 30000,compCount, moveCount);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 30000 << setw(16) << duration << " ms"<<setw(20) << compCount << setw(20) << moveCount <<endl;
    compCount = 0; moveCount = 0;

    cout<<"Analysis of Radix Sort"<<endl;
    cout << "Array Size" << setw(16) << "Elapsed time" <<endl;

    startTime = clock();
    radixSort(arr6000_4, 6000);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 6000 << setw(16) << duration <<" ms"<<endl;

    startTime = clock();
    radixSort(arr10000_4, 10000);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 10000 << setw(16) << duration <<" ms"<<endl;

    startTime = clock();
    radixSort(arr14000_4, 14000);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 14000 << setw(16) << duration <<" ms"<<endl;

    startTime = clock();
    radixSort(arr18000_4, 18000);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 18000 << setw(16) << duration <<" ms"<<endl;

    startTime = clock();
    radixSort(arr22000_4, 22000);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 22000 << setw(16) << duration <<" ms"<<endl;

    startTime = clock();
    radixSort(arr26000_4, 26000);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 26000 << setw(16) << duration <<" ms"<< endl;

    startTime = clock();
    radixSort(arr30000_4, 30000);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << 30000 << setw(16) << duration <<" ms"<<endl;
    cout<<endl;

    delete []arr6000_1; delete []arr6000_2; delete []arr6000_3; delete []arr6000_4;
    delete []arr10000_1; delete []arr10000_2; delete []arr10000_3; delete []arr10000_4;
    delete []arr14000_1; delete []arr14000_2; delete []arr14000_3; delete []arr14000_4;
    delete []arr18000_1; delete []arr18000_2; delete []arr18000_3; delete []arr18000_4;
    delete []arr22000_1; delete []arr22000_2; delete []arr22000_3; delete []arr22000_4;
    delete []arr26000_1; delete []arr26000_2; delete []arr26000_3; delete []arr26000_4;
    delete []arr30000_1; delete []arr30000_2; delete []arr30000_3; delete []arr30000_4;
}