/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Ata Seren
* Id: 21901575
* Section : 1
* Assignment : 4
* Description : header file for functions that will be used on graph
*/
#ifndef __WORDNETWORK_H
#define __WORDNETWORK_H
#include <iostream>
#include <fstream>
#include <string>
#include "HashNode.h"
#include "Queue.h"
using namespace std;
class WordNetwork {
    public:
        WordNetwork (const string vertexFile, const string edgeFile);
        ~WordNetwork();
        void listNeighbors (const string word);
        void listNeighbors (const string word, const int distance);
        void listConnectedComponents();
        void findShortestPath (const string word1, const string word2);

        int test(int first, int second);
        void test2(int first, int second);
        int hashFunc (const string &key, int tableSize);
        string getWord(int index);
        bool listHelper(string word, int distance, int limit, int*&visited, bool exist);
        bool listHelper2(string word, int distance, int limit, int*&visited, bool exist);
        bool breadthFirstSearch( int src, int dest, int v, int* predec);
    private:
        int **adjMat; 
        int size;
        int getIndex(string key);
        HashNode **hashTable;
};
#endif