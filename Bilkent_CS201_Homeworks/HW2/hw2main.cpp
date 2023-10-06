#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;

void resetArray(int*arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }  
}

//algorithm1
//method that takes arr1, arr2 and empty arr3, merges arr1 and arr3 and return it in arr3
void algorithm1(int *arr1, int *arr2, int* &arr3, int size)
{
    double duration;
    clock_t startTime = clock();
    for (int a = 0; a < size; a++)
    {
        arr3[a] = arr1[a];
    }
    int arr3size = size;

    for ( int b = 0 ; b < size; b++) {
        int index = 0;

        while( index < arr3size ){
            if ( arr2[b] <= arr3[index] ){
                for ( int c = arr3size-1; c >= index; c--) 
                {
                    arr3[c+1] = arr3[c];
                }
                arr3[index] = arr2[b];
                arr3size++;
                index = arr3size;
            }
            else {
                index++;
            }
        }
    }

    while (arr3size < 2*size) {
        arr3[arr3size] = arr2[arr3size-size];
        arr3size++;
    }
    
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
}

//algorithm 2
//checks pairs of ints and inserts smaller one into arr3
void algorithm2(int *arr1, int* arr2, int*& arr3, int size)
{
    double duration;
    clock_t startTime = clock();
    int index1 = 0;
    int index2 = 0;
    for (int i = 0; i < size*2; i++)
    {
        if(index1 < size && index2 < size)
        {
            if (arr1[index1] <=arr2[index2])
            {
                arr3[i] = arr1[index1];
                index1++;
            }
            else if(arr2[index2] <=arr1[index1])
            {
                arr3[i] = arr2[index2];
                index2++;
            }  
        }
        else
        {
            if(index1 >= size)
            {
                arr3[i]= arr2[index2];
                index2++;
            }
            else if(index2 >= size)
            {
                arr3[i]= arr1[index1];
                index1++;
            }
        }  
    }  
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
}

int main()
{
   // declaration of arrays
    int *arr10_1 = new int [10];
    int *arr10_2 = new int [10];
    int *arr100_1 = new int [100];
    int *arr100_2 = new int [100];
    int *arr1000_1 = new int [1000];
    int *arr1000_2 = new int [1000];
    int *arr5000_1 = new int [5000]; 
    int *arr5000_2 = new int [5000];
    int *arr10000_1 = new int [10000];
    int *arr10000_2 = new int [10000];
    int *arr50000_1 = new int [50000];
    int *arr50000_2 = new int [50000];
    int *arr100000_1 = new int [100000];
    int *arr100000_2 = new int [100000];
    int *arr200000_1 = new int [200000];
    int *arr200000_2 = new int [200000];
    int *arr500000_1 = new int [500000];
    int *arr500000_2 = new int [500000];
    int *arr1000000_1 = new int [1000000];
    int *arr1000000_2 = new int [1000000];
    int *arr5000000_1 = new int [5000000];
    int *arr5000000_2 = new int [5000000];

    int* arr10_3 = new int[20];
    int* arr100_3 = new int[200];
    int* arr1000_3 = new int[2000];
    int* arr5000_3 = new int[10000];
    int* arr10000_3 = new int[20000];
    int* arr50000_3 = new int[100000];
    int* arr100000_3 = new int[200000];
    int* arr200000_3 = new int[400000];
    int* arr500000_3 = new int[1000000];
    int* arr1000000_3 = new int[2000000];
    int* arr5000000_3 = new int[10000000];

    //initialization of arr3's
    resetArray(arr10_3,20);
    resetArray(arr100_3,200);
    resetArray(arr1000_3,2000);
    resetArray(arr5000_3,10000);
    resetArray(arr10000_3,20000);
    resetArray(arr50000_3,100000);
    resetArray(arr100000_3,200000);
    resetArray(arr200000_3,400000);
    resetArray(arr500000_3,1000000);
    resetArray(arr1000000_3,2000000);

    //case1 n=10
    cout<<"case1 for n=10"<<endl;
    for (int a = 0; a < 10; a++)
    {
        arr10_1[a] = rand()%20;
        arr10_2[a] = rand()%20+20;
    }
    sort(arr10_1,arr10_1+10);
    sort(arr10_2,arr10_2+10);

    cout<<"arr1 and arr2 initialized "<<endl;
    cout<<endl;
    
    cout<<"algorithm1 done "<<endl;
    algorithm1(arr10_1,arr10_2,arr10_3,10);
    
    cout<<endl;

    cout<<endl;
    resetArray(arr10_3,20);
    cout<<endl;

    cout<<"algorithm 2 done "<<endl;
    algorithm2(arr10_1,arr10_2,arr10_3,10);
    cout<<endl;

    resetArray(arr10_3,20);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    
    //case2 n=10
    cout<<"case2 for n=10"<<endl;
    for (int a = 0; a < 10; a++)
    {
        arr10_1[a] = rand()%20+20;
        arr10_2[a] = rand()%20;
    }
    sort(arr10_1,arr10_1+10);
    sort(arr10_2,arr10_2+10);

    cout<<"arr1 and arr2 initialized "<<endl;
    cout<<endl;

    cout<<"algorithm 1 done "<<endl;
    algorithm1(arr10_1,arr10_2,arr10_3,10);
    cout<<endl;

    cout<<endl;
    resetArray(arr10_3,20);
    cout<<endl;

    cout<<"algorithm 2 done "<<endl;
    algorithm2(arr10_1,arr10_2,arr10_3,10);
    cout<<endl;

    resetArray(arr10_3,20);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case3 n=10
    cout<<"case3 for n=10"<<endl;
    for (int a = 0; a < 10; a++)
    {
        arr10_1[a] = rand()%20;
        arr10_2[a] = rand()%20;
    }
    sort(arr10_1,arr10_1+10);
    sort(arr10_2,arr10_2+10);

    cout<<"arr1 and arr2 initialized "<<endl;
    cout<<endl;

    cout<<"algorithm 1 done "<<endl;
    algorithm1(arr10_1,arr10_2,arr10_3,10);
    cout<<endl;

    cout<<endl;
    resetArray(arr10_3,20);
    cout<<endl;

    cout<<"algorithm 2 done "<<endl;
    algorithm2(arr10_1,arr10_2,arr10_3,10);
    cout<<endl;

    resetArray(arr10_3,20);
    delete[] arr10_1;
    delete[] arr10_2;
    delete[] arr10_3;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case1 n=100
    cout<<"case1 for n=100"<<endl;
    for (int a = 0; a < 100; a++)
    {
        arr100_1[a] = rand()%200;
        arr100_2[a] = rand()%200+200;
    }
    sort(arr100_1,arr100_1+100);
    sort(arr100_2,arr100_2+100);
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
    
    cout<<"algorithm 1 done "<<endl;
    algorithm1(arr100_1,arr100_2,arr100_3,100);
    cout<<endl;
   
    resetArray(arr100_3,200);

    cout<<"algorithm 2 done "<<endl;
    algorithm2(arr100_1,arr100_2,arr100_3,100);
    cout<<endl;
    
    resetArray(arr100_3,200);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case2 n=100
    cout<<"case2 for n=100"<<endl;
    for (int a = 0; a < 100; a++)
    {
        arr100_1[a] = rand()%200+200;
        arr100_2[a] = rand()%200;
    }
    sort(arr100_1,arr100_1+100);
    sort(arr100_2,arr100_2+100);
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;

    cout<<"algorithm 1 done "<<endl;
    algorithm1(arr100_1,arr100_2,arr100_3,100);
    cout<<endl;

    resetArray(arr100_3,200);

    cout<<"algorithm 2 done "<<endl;
    algorithm2(arr100_1,arr100_2,arr100_3,100);
    cout<<endl;

    resetArray(arr100_3,200);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case3 n=100
    cout<<"case3 for n=100"<<endl;
    for (int a = 0; a < 100; a++)
    {
        arr100_1[a] = rand()%200;
        arr100_2[a] = rand()%200;
    }
    sort(arr100_1,arr100_1+100);
    sort(arr100_2,arr100_2+100);
    cout<<endl;
    cout<<"arr1 and arr2 initialized  "<<endl;

    cout<<"algorithm 1 done "<<endl;
    algorithm1(arr100_1,arr100_2,arr100_3,100);
    cout<<endl;

    resetArray(arr100_3,200);

    cout<<"algorithm 2 done "<<endl;
    algorithm2(arr100_1,arr100_2,arr100_3,100);
    cout<<endl;

    resetArray(arr100_3,200);
    delete[] arr100_1;
    delete[] arr100_2;
    delete[] arr100_3;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case1 n=1000 (i won't print arrays in and after this case because they are very big)
    cout<<"case1 for n=1000"<<endl;
    for (int a = 0; a < 1000; a++)
    {
        arr1000_1[a] = rand()%2000;
        arr1000_2[a] = rand()%2000+2000;
    }
    sort(arr1000_1,arr1000_1+1000);
    sort(arr1000_2,arr1000_2+1000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
   

    cout<<"algorithm 1 done for case1 "<<endl;
    algorithm1(arr1000_1,arr1000_2,arr1000_3,1000);
    cout<<endl;

    resetArray(arr1000_3,2000);

    cout<<"algorithm 2 done for case 1 "<<endl;
    algorithm2(arr1000_1,arr1000_2,arr1000_3,1000);
    cout<<endl;

    resetArray(arr1000_3,2000);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case2 n=1000
    cout<<"case2 for n=1000"<<endl;
    for (int a = 0; a < 1000; a++)
    {
        arr1000_1[a] = rand()%2000+2000;
        arr1000_2[a] = rand()%2000;
    }
    sort(arr1000_1,arr1000_1+1000);
    sort(arr1000_2,arr1000_2+1000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
   
    cout<<"algorithm 1 done for case2 "<<endl;
    algorithm1(arr1000_1,arr1000_2,arr1000_3,1000);
    cout<<endl;

    resetArray(arr1000_3,2000);

    cout<<"algorithm 2 done for case 2 "<<endl;
    algorithm2(arr1000_1,arr1000_2,arr1000_3,1000);
    cout<<endl;
    

    resetArray(arr1000_3,2000);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case3 n=1000
    cout<<"case3 for n=1000"<<endl;
    for (int a = 0; a < 1000; a++)
    {
        arr1000_1[a] = rand()%2000;
        arr1000_2[a] = rand()%2000;
    }
    sort(arr1000_1,arr1000_1+1000);
    sort(arr1000_2,arr1000_2+1000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
   
    cout<<"algorithm1 done for case3 "<<endl;
    algorithm1(arr1000_1,arr1000_2,arr1000_3,1000);
    cout<<endl;
    
    resetArray(arr1000_3,2000);
    
    cout<<"algorithm2 done for case3 "<<endl;
    algorithm2(arr1000_1,arr1000_2,arr1000_3,1000);
    cout<<endl;

    resetArray(arr1000_3,2000);
    delete[] arr1000_1;
    delete[] arr1000_2;
    delete[] arr1000_3;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case1 n=5000
    cout<<"case1 for n=5000"<<endl;
    for (int a = 0; a < 5000; a++)
    {
        arr5000_1[a] = rand()%5000;
        arr5000_2[a] = rand()%5000+5000;
    }
    sort(arr5000_1,arr5000_1+5000);
    sort(arr5000_2,arr5000_2+5000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
   
    cout<<"algorithm1 done for case1 "<<endl;
    algorithm1(arr5000_1,arr5000_2,arr5000_3,5000);
    cout<<endl;

    
    resetArray(arr5000_3,10000);

    cout<<"algorithm2 done for case1 "<<endl;
    algorithm2(arr5000_1,arr5000_2,arr5000_3,5000);
    cout<<endl;

    resetArray(arr5000_3,10000);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case2 n=5000
    cout<<"case2 for n=5000"<<endl;
    for (int a = 0; a < 5000; a++)
    {
        arr5000_1[a] = rand()%5000+5000;
        arr5000_2[a] = rand()%5000;
    }
    sort(arr5000_1,arr5000_1+5000);
    sort(arr5000_2,arr5000_2+5000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
   
    cout<<"algorithm1 done for case2 "<<endl;
    algorithm1(arr5000_1,arr5000_2,arr5000_3,5000);
    cout<<endl;

    resetArray(arr5000_3,10000);

    cout<<"algorithm2 done for case2 "<<endl;
    algorithm2(arr5000_1,arr5000_2,arr5000_3,5000);
    cout<<endl;

    resetArray(arr5000_3,10000);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case3 n=5000
    cout<<"case3 for n=5000"<<endl;
    for (int a = 0; a < 5000; a++)
    {
        arr5000_1[a] = rand()%5000;
        arr5000_2[a] = rand()%5000;
    }
    sort(arr5000_1,arr5000_1+5000);
    sort(arr5000_2,arr5000_2+5000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
   
    cout<<"algorithm1 done for case3 "<<endl;
    algorithm1(arr5000_1,arr5000_2,arr5000_3,5000);
    cout<<endl;

    resetArray(arr5000_3,10000);

    cout<<"algorithm2 done for case3 "<<endl;
    algorithm2(arr5000_1,arr5000_2,arr5000_3,5000);
    cout<<endl;

    resetArray(arr5000_3,10000);
    delete[] arr5000_1;
    delete[] arr5000_2;
    delete[] arr5000_3;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case1 n=10000
    cout<<"case1 for n=10000"<<endl;
    for (int a = 0; a < 10000; a++)
    {
        arr10000_1[a] = rand()%10000;
        arr10000_2[a] = rand()%10000+10000;
    }
    sort(arr10000_1,arr10000_1+10000);
    sort(arr10000_2,arr10000_2+10000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
   
    cout<<"algorithm1 done for case1 "<<endl;
    algorithm1(arr10000_1,arr10000_2,arr10000_3,10000);
    cout<<endl;

    resetArray(arr10000_3,20000);

    cout<<"algorithm2 done for case1 "<<endl;
    algorithm2(arr10000_1,arr10000_2,arr10000_3,10000);
    cout<<endl;

    resetArray(arr10000_3,20000);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case2 n=10000
    cout<<"case2 for n=10000"<<endl;
    for (int a = 0; a < 10000; a++)
    {
        arr10000_1[a] = rand()%10000+10000;
        arr10000_2[a] = rand()%10000;
    }
    sort(arr10000_1,arr10000_1+10000);
    sort(arr10000_2,arr10000_2+10000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
   
    cout<<"algorithm1 done for case2 "<<endl;
    algorithm1(arr10000_1,arr10000_2,arr10000_3,10000);
    cout<<endl;
    
    resetArray(arr10000_3,20000);

    cout<<"algorithm2 done for case2 "<<endl;
    algorithm2(arr10000_1,arr10000_2,arr10000_3,10000);
    cout<<endl;

    resetArray(arr10000_3,20000);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case3 n=10000
    cout<<"case3 for n=10000"<<endl;
    for (int a = 0; a < 10000; a++)
    {
        arr10000_1[a] = rand()%10000;
        arr10000_2[a] = rand()%10000;
    }
    sort(arr10000_1,arr10000_1+10000);
    sort(arr10000_2,arr10000_2+10000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
   
    cout<<"algorithm1 done for case3 "<<endl;
    algorithm1(arr10000_1,arr10000_2,arr10000_3,10000);
    cout<<endl;
    
    resetArray(arr10000_3,20000);

    cout<<"algorithm2 done for case3 "<<endl;
    algorithm2(arr10000_1,arr10000_2,arr10000_3,10000);
    cout<<endl;

    resetArray(arr10000_3,20000);
    delete[] arr10000_1;
    delete[] arr10000_2;
    delete[] arr10000_3;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case1 n=50000
    cout<<"case1 for n=50000"<<endl;
    for (int a = 0; a < 50000; a++)
    {
        arr50000_1[a] = rand()%50000;
        arr50000_2[a] = rand()%50000+50000;
    }
    sort(arr50000_1,arr50000_1+50000);
    sort(arr50000_2,arr50000_2+50000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
   
    cout<<"algorithm1 done for case1 "<<endl;
    algorithm1(arr50000_1,arr50000_2,arr50000_3,50000);
    cout<<endl;

    resetArray(arr50000_3,100000);

    cout<<"algorithm2 done for case1 "<<endl;
    algorithm2(arr50000_1,arr50000_2,arr50000_3,50000);
    cout<<endl;

    resetArray(arr50000_3,100000);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case2 n=50000
    cout<<"case2 for n=50000"<<endl;
    for (int a = 0; a < 50000; a++)
    {
        arr50000_1[a] = rand()%50000+50000;
        arr50000_2[a] = rand()%50000;
    }
    sort(arr50000_1,arr50000_1+50000);
    sort(arr50000_2,arr50000_2+50000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
   
    cout<<"algorithm1 done for case2 "<<endl;
    algorithm1(arr50000_1,arr50000_2,arr50000_3,50000);
    cout<<endl;
    
    resetArray(arr50000_3,100000);

    cout<<"algorithm2 done for case2 "<<endl;
    algorithm2(arr50000_1,arr50000_2,arr50000_3,50000);
    cout<<endl;

    resetArray(arr50000_3,100000);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case3 n=50000
    cout<<"case3 for n=50000"<<endl;
    for (int a = 0; a < 50000; a++)
    {
        arr50000_1[a] = rand()%50000;
        arr50000_2[a] = rand()%50000;
    }
    sort(arr50000_1,arr50000_1+50000);
    sort(arr50000_2,arr50000_2+50000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
   
    cout<<"algorithm1 done for case3 "<<endl;
    algorithm1(arr50000_1,arr50000_2,arr50000_3,50000);
    cout<<endl;
    
    resetArray(arr50000_3,100000);

    cout<<"algorithm2 done for case3 "<<endl;
    algorithm2(arr50000_1,arr50000_2,arr50000_3,50000);
    cout<<endl;

    resetArray(arr50000_3,100000);
    delete[] arr50000_1;
    delete[] arr50000_2;
    delete[] arr50000_3;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    

    //case1 n=100000
    cout<<"case1 for n=100000"<<endl;
    for (int a = 0; a < 100000; a++)
    {
        arr100000_1[a] = rand()%100000;
        arr100000_2[a] = rand()%100000+100000;
    }
    sort(arr100000_1,arr100000_1+100000);
    sort(arr100000_2,arr100000_2+100000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
   
    cout<<"algorithm1 done for case1 "<<endl;
    algorithm1(arr100000_1,arr100000_2,arr100000_3,100000);
    cout<<endl;

    resetArray(arr100000_3,200000);

    cout<<"algorithm2 done for case1 "<<endl;
    algorithm2(arr100000_1,arr100000_2,arr100000_3,100000);
    cout<<endl;

    resetArray(arr100000_3,200000);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case2 n=100000
    cout<<"case2 for n=100000"<<endl;
    for (int a = 0; a < 100000; a++)
    {
        arr100000_1[a] = rand()%100000+100000;
        arr100000_2[a] = rand()%100000;
    }
    sort(arr100000_1,arr100000_1+100000);
    sort(arr100000_2,arr100000_2+100000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
   
    cout<<"algorithm1 done for case2 "<<endl;
    algorithm1(arr100000_1,arr100000_2,arr100000_3,100000);
    cout<<endl;
    
    resetArray(arr100000_3,200000);

    cout<<"algorithm2 done for case2 "<<endl;
    algorithm2(arr100000_1,arr100000_2,arr100000_3,100000);
    cout<<endl;

    resetArray(arr100000_3,200000);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case3 n=100000
    cout<<"case3 for n=100000"<<endl;
    for (int a = 0; a < 100000; a++)
    {
        arr100000_1[a] = rand()%100000;
        arr100000_2[a] = rand()%100000;
    }
    sort(arr100000_1,arr100000_1+100000);
    sort(arr100000_2,arr100000_2+100000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
   
    cout<<"algorithm1 done for case3 "<<endl;
    algorithm1(arr100000_1,arr100000_2,arr100000_3,100000);
    cout<<endl;
    
    resetArray(arr100000_3,200000);

    cout<<"algorithm2 done for case3 "<<endl;
    algorithm2(arr100000_1,arr100000_2,arr100000_3,100000);
    cout<<endl;

    resetArray(arr100000_3,200000);
    delete[] arr100000_1;
    delete[] arr100000_2;
    delete[] arr100000_3;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    
    //case1 n=200000
    cout<<"case1 for n=200000"<<endl;
    for (int a = 0; a < 200000; a++)
    {
        arr200000_1[a] = rand()%200000;
        arr200000_2[a] = rand()%200000+200000;
    }
    sort(arr200000_1,arr200000_1+200000);
    sort(arr200000_2,arr200000_2+200000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
   
    cout<<"algorithm1 done for case1 "<<endl;
    algorithm1(arr200000_1,arr200000_2,arr200000_3,200000);
    cout<<endl;

    resetArray(arr200000_3,400000);

    cout<<"algorithm2 done for case1 "<<endl;
    algorithm2(arr200000_1,arr200000_2,arr200000_3,200000);
    cout<<endl;

    resetArray(arr200000_3,400000);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case2 n=200000
    cout<<"case2 for n=200000"<<endl;
    for (int a = 0; a < 200000; a++)
    {
        arr200000_1[a] = rand()%200000+200000;
        arr200000_2[a] = rand()%200000;
    }
    sort(arr200000_1,arr200000_1+200000);
    sort(arr200000_2,arr200000_2+200000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
   
    cout<<"algorithm1 done for case2 "<<endl;
    algorithm1(arr200000_1,arr200000_2,arr200000_3,200000);
    cout<<endl;
    
    resetArray(arr200000_3,400000);

    cout<<"algorithm2 done for case2 "<<endl;
    algorithm2(arr200000_1,arr200000_2,arr200000_3,200000);
    cout<<endl;

    resetArray(arr200000_3,400000);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case3 n=200000
    cout<<"case3 for n=200000"<<endl;
    for (int a = 0; a < 200000; a++)
    {
        arr200000_1[a] = rand()%200000;
        arr200000_2[a] = rand()%200000;
    }
    sort(arr200000_1,arr200000_1+200000);
    sort(arr200000_2,arr200000_2+200000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
   
    cout<<"algorithm1 done for case3 "<<endl;
    algorithm1(arr200000_1,arr200000_2,arr200000_3,200000);
    cout<<endl;
    
    resetArray(arr200000_3,400000);

    cout<<"algorithm2 done for case3 "<<endl;
    algorithm2(arr200000_1,arr200000_2,arr200000_3,200000);
    cout<<endl;

    resetArray(arr200000_3,400000);
    delete[] arr200000_1;
    delete[] arr200000_2;
    delete[] arr200000_3;
    cout<<endl;
    cout<<endl;
    cout<<endl; 

    //case1 n=500000 (I didn't use algorithm 1 above size n=250000 because it becomes very slow)
    cout<<"case1 for n=500000"<<endl;
    for (int a = 0; a < 500000; a++)
    {
        arr500000_1[a] = rand()%500000;
        arr500000_2[a] = rand()%500000+500000;
    }
    sort(arr500000_1,arr500000_1+500000);
    sort(arr500000_2,arr500000_2+500000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;

    cout<<"algorithm2 done for case1 "<<endl;
    algorithm2(arr500000_1,arr500000_2,arr500000_3,500000);
    cout<<endl;

    resetArray(arr500000_3,1000000);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case2 n=500000
    cout<<"case2 for n=500000"<<endl;
    for (int a = 0; a < 500000; a++)
    {
        arr500000_1[a] = rand()%500000+500000;
        arr500000_2[a] = rand()%500000;
    }
    sort(arr500000_1,arr500000_1+500000);
    sort(arr500000_2,arr500000_2+500000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;

    cout<<"algorithm2 done for case2 "<<endl;
    algorithm2(arr500000_1,arr500000_2,arr500000_3,500000);
    cout<<endl;

    resetArray(arr500000_3,1000000);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case3 n=500000
    cout<<"case3 for n=500000"<<endl;
    for (int a = 0; a < 500000; a++)
    {
        arr500000_1[a] = rand()%500000;
        arr500000_2[a] = rand()%500000;
    }
    sort(arr500000_1,arr500000_1+500000);
    sort(arr500000_2,arr500000_2+500000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
    
    resetArray(arr500000_3,1000000);

    cout<<"algorithm2 done for case3 "<<endl;
    algorithm2(arr500000_1,arr500000_2,arr500000_3,500000);
    cout<<endl;

    resetArray(arr500000_3,1000000);
    delete[] arr500000_1;
    delete[] arr500000_2;
    delete[] arr500000_3;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case1 n=1000000
    cout<<"case1 for n=1000000"<<endl;
    for (int a = 0; a < 1000000; a++)
    {
        arr1000000_1[a] = rand()%1000000;
        arr1000000_2[a] = rand()%1000000+1000000;
    }
    sort(arr1000000_1,arr1000000_1+1000000);
    sort(arr1000000_2,arr1000000_2+1000000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;

    cout<<"algorithm2 done for case1 "<<endl;
    algorithm2(arr1000000_1,arr1000000_2,arr1000000_3,1000000);
    cout<<endl;

    resetArray(arr1000000_3,2000000);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case2 n=1000000
    cout<<"case2 for n=1000000"<<endl;
    for (int a = 0; a < 1000000; a++)
    {
        arr1000000_1[a] = rand()%1000000+1000000;
        arr1000000_2[a] = rand()%1000000;
    }
    sort(arr1000000_1,arr1000000_1+1000000);
    sort(arr1000000_2,arr1000000_2+1000000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
    
    resetArray(arr1000000_3,2000000);

    cout<<"algorithm2 done for case2 "<<endl;
    algorithm2(arr1000000_1,arr1000000_2,arr1000000_3,1000000);
    cout<<endl;

    resetArray(arr1000000_3,2000000);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case3 n=1000000
    cout<<"case3 for n=1000000"<<endl;
    for (int a = 0; a < 1000000; a++)
    {
        arr1000000_1[a] = rand()%1000000;
        arr1000000_2[a] = rand()%1000000;
    }
    sort(arr1000000_1,arr1000000_1+1000000);
    sort(arr1000000_2,arr1000000_2+1000000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
    
    resetArray(arr1000000_3,2000000);

    cout<<"algorithm2 done for case3 "<<endl;
    algorithm2(arr1000000_1,arr1000000_2,arr1000000_3,1000000);
    cout<<endl;

    resetArray(arr1000000_3,2000000);
    delete[] arr1000000_1;
    delete[] arr1000000_2;
    delete[] arr1000000_3;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case1 n=5000000
    cout<<"case1 for n=5000000"<<endl;
    for (int a = 0; a < 5000000; a++)
    {
        arr5000000_1[a] = rand()%5000000;
        arr5000000_2[a] = rand()%5000000+5000000;
    }
    sort(arr5000000_1,arr5000000_1+5000000);
    sort(arr5000000_2,arr5000000_2+5000000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;

    cout<<"algorithm2 done for case1 "<<endl;
    algorithm2(arr5000000_1,arr5000000_2,arr5000000_3,5000000);
    cout<<endl;

    resetArray(arr5000000_3,10000000);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case2 n=5000000
    cout<<"case2 for n=5000000"<<endl;
    for (int a = 0; a < 5000000; a++)
    {
        arr5000000_1[a] = rand()%5000000+5000000;
        arr5000000_2[a] = rand()%5000000;
    }
    sort(arr5000000_1,arr5000000_1+5000000);
    sort(arr5000000_2,arr5000000_2+5000000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
    
    resetArray(arr5000000_3,10000000);

    cout<<"algorithm2 done for case2 "<<endl;
    algorithm2(arr5000000_1,arr5000000_2,arr5000000_3,5000000);
    cout<<endl;

    resetArray(arr5000000_3,10000000);
    cout<<endl;
    cout<<endl;
    cout<<endl;

    //case3 n=5000000
    cout<<"case3 for n=5000000"<<endl;
    for (int a = 0; a < 5000000; a++)
    {
        arr5000000_1[a] = rand()%5000000;
        arr5000000_2[a] = rand()%5000000;
    }
    sort(arr5000000_1,arr5000000_1+5000000);
    sort(arr5000000_2,arr5000000_2+5000000);
 
    cout<<"arr1 and arr2 initialized  "<<endl;
    cout<<endl;
    
    resetArray(arr5000000_3,10000000);

    cout<<"algorithm2 done for case3 "<<endl;
    algorithm2(arr5000000_1,arr5000000_2,arr5000000_3,5000000);
    cout<<endl;

    resetArray(arr5000000_3,10000000);
    delete[] arr5000000_1;
    delete[] arr5000000_2;
    delete[] arr5000000_3;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    return 0;
}