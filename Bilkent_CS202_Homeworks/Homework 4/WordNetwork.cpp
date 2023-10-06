/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Ata Seren
* Id: 21901575
* Section : 1
* Assignment : 4
* Description : cpp file for methods to operate on word network
*/
#include "WordNetwork.h"
#include "HashNode.h"
#include "Queue.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

//Constructor for hash table and adjacent matrix
WordNetwork::WordNetwork(const string vertexFile, const string edgeFile)
{   
    hashTable = new HashNode*[73]();
    ifstream inputVertex(vertexFile.c_str());
    
    string tempS;
    int vertexIndex = 0;
    HashNode* tempVertex;
    
    //reading vertex file for hash table
    while(inputVertex >> tempS)
    {
        int hashIndex = hashFunc(tempS, 73);
        if(hashTable[hashIndex] == NULL)
        {
            hashTable[hashIndex] = new HashNode();
            hashTable[hashIndex]->word = tempS;
            hashTable[hashIndex]->id = vertexIndex;
            hashTable[hashIndex]->next = NULL;
        }
        else
        {
            tempVertex = hashTable[hashIndex];
            while(tempVertex->next != NULL)
            {
                tempVertex = tempVertex->next;
            }
            tempVertex->next = new HashNode();
            tempVertex->next->word = tempS;
            tempVertex->next->id = vertexIndex;
            tempVertex->next->next = NULL;
        }
        vertexIndex++;
    }
    inputVertex.close();
    size = vertexIndex; //if you use different sized files
    
    //2d array for adjacent matrix
    adjMat = new int*[size];
    for(int i = 0; i < size; ++i) 
    {
        adjMat[i] = new int[size]();
    }

    ifstream inputEdge(edgeFile.c_str());
    string edge1;
    string edge2;
    int edgeIndex1;
    int edgeIndex2;
    int testnum = 0;

    //reading edge file for adjacent matrix
    while(inputEdge >> tempS)
    {
        edge1 = tempS.substr(0,5);
        edge2 = tempS.substr(6,5);
        edgeIndex1 = getIndex(edge1);
        edgeIndex2 = getIndex(edge2);
        
        adjMat[edgeIndex1][edgeIndex2] = 1;
        adjMat[edgeIndex2][edgeIndex1] = 1;

    }
    inputEdge.close();
    cout<<"Adjacency matrix and hash table are constructed using data in text files."<<endl;
}

//destructor to delete adjacent matrix and hash table
WordNetwork::~WordNetwork()
{
    for(int i = 0; i < size; i++) 
    {
        delete [] adjMat[i];
    }
    delete[] adjMat;

    HashNode* temp;
    for (int i = 0; i < 73; i++)
    {
        temp = hashTable[i];
        while (temp)
        {
            HashNode* old = temp;
            temp = temp->next;
            delete old;
        }
    }
    delete temp;
    delete[] hashTable;
}

//gets index of a word in adjacent matrix
int WordNetwork::getIndex(string key)
{   
    HashNode* indexPtr;
    bool found = false;
    int hashIndex = hashFunc(key,73);
    if(hashTable[hashIndex]->word == key)
    {
        return hashTable[hashIndex]->id;
    }
    else
    {
        indexPtr = hashTable[hashIndex]->next;
        while(indexPtr != NULL)
        {   
            if(indexPtr->word == key)
            {
                found = true;
                break;
            }
            indexPtr = indexPtr->next;
        }
        if(found)
        {
            return indexPtr->id;
        }
        else
        {   
            //just in case
            return -1;
        }
    }
}

//hashing function from slide
int WordNetwork::hashFunc(const string &key, int tableSize)
{
    int hashVal = 0; 
	
    for (int i = 0; i < key.length(); i++)
    {
        hashVal = 37 * hashVal + key[i];
    }

    hashVal %=tableSize; 

    if (hashVal < 0)
    {   
        hashVal += tableSize; 
    }

    return hashVal; 	
}

//a function I used to solve some issues
int WordNetwork::test(int first, int second)
{
    return adjMat[first][second];
}

//another function I used to solve some issues
void WordNetwork::test2(int first, int second)
{
    cout<< first <<endl;
    cout<< hashTable[first]->next->word <<endl;
}

//lists neighbors of a word
void WordNetwork::listNeighbors (const string word)
{
    bool exist = false;
    int index = getIndex(word);
    if(index == -1)
    {   
        cout<<"There is no such word in word network."<<endl;
    }
    else
    {
        cout<<"Neighbors of "<<word<<":"<<endl;
        for (int i = 0; i < size; i++)
        {
            if(adjMat[index][i] == 1)
            {   
                exist = true;
                cout<<getWord(i)<<endl;
            }
        }
    }   
    if(!exist)
    {
        cout<<"There isn't any neighbor of this word."<<endl;
    }  
}

//gets word from adjacent matrix according to its index in adjacent matrix
string WordNetwork::getWord(int index)
{
    HashNode* temp;
    for (int i = 0; i < 73; i++)
    {
        temp = hashTable[i];
        while(temp != NULL)
        {
            if(temp->id == index)
            {
                return temp->word;
            }
            temp = temp->next;
        }
    }
    return "Error of finding word in hash!!!";
}

//lists neighbors of a word in a distance
void WordNetwork::listNeighbors (const string word, const int distance)
{
    int* visited = new int[size]();
    int index = getIndex(word);
    if(index == -1)
    {
        cout<<"There is no such word in word network."<<endl;
    }
    else
    {
        visited[index] = 1;
        cout<<"Neighbors of "<<word<<" in distance "<<distance<<":"<<endl;
        if(!listHelper(word,1, distance, visited, false))
        {
            cout<<"There isn't any neighbor of this word."<<endl;
        }
    }
    delete[] visited;
} 

//helper method for recursion to list neighbors in a distance
bool WordNetwork::listHelper(string word, int distance, int limit, int*&visited, bool exist)
{ 
    bool nExist = exist;
    if(distance <= limit)
    {
        int index = getIndex(word);
        for (int i = 0; i < size; i++)
        {
            if(adjMat[index][i] == 1 && visited[i] == 0)
            {
                nExist = true;
                cout<<getWord(i)<<endl;
                visited[i] = 1;
                listHelper(getWord(i), distance+1, limit, visited, nExist);
            }
        }
    }
    return nExist;
}

/*
lists every connected component
IMPORTANT NOTE: I considered a component as at least 2 vertices connected to each other.
For example, word "roger" has several neigbors. However, word "nexus" doesn't have any neighbors.
Therefore, there is a component with connections of "roger" but "nexus" is not considered as component.
I only printed these valid components but easily, I can print other type of components too.
*/
void WordNetwork::listConnectedComponents()
{   
    int component = 1;
    int* visited = new int[size]();

    for (int i = 0; i < size; i++)
    {
        if(visited[i] == 0 &&listHelper2(getWord(i), 1, size, visited, false))
        {
            cout<<"Connected component "<< component << ":"<<endl;
            cout<<getWord(i)<<endl;
            visited[i] = 1;
            listHelper(getWord(i), 1, size, visited, false);
            component++;
            //cout<<"testinloop"<<endl;
        }
        //cout<<"testoutloop"<<endl;
    }
    
    delete[]visited;
}

// I used this helper method to established component definiton above.
bool WordNetwork::listHelper2(string word, int distance, int limit, int*&visited, bool exist)
{ 
    bool nExist = false;

    int index = getIndex(word);
    for (int i = 0; i < size; i++)
    {
        if(adjMat[index][i] == 1)
        {
            return true;
        }
    }
    return nExist;
}

//I used breadth first traversal to find a shortest path
void WordNetwork::findShortestPath (const string word1, const string word2)
{
    cout<<"Shortest path from "<< word1<<" to " << word2<<":"<<endl;
    int* predec= new int [size];
    int start = getIndex(word2);
    int end = getIndex(word1);
    if (breadthFirstSearch(start, end, size, predec) == false) 
    {
        cout << "Words are not connected"<<endl;
        return;
    }
 
    Queue finalQ;
    
    int endTemp = end;
    finalQ.enqueue(endTemp);
    while (predec[endTemp] != -1) 
    {
        finalQ.enqueue(predec[endTemp]);
        endTemp = predec[endTemp];
    }
 
    int tempIndex;
    while(!finalQ.isEmpty())
    {
        finalQ.dequeue(tempIndex);
        cout << getWord(tempIndex) << endl;
    }
    delete[] predec;
}

//modified breadth first traversal function
bool WordNetwork::breadthFirstSearch( int src, int dest, int v, int* predec)
{
    Queue q;

    int* visited = new int[size]();
 
    //initialize default values
    for (int i = 0; i < v; i++) 
    {
        visited[i] = 0;
        predec[i] = -1;
    }
 
    visited[src] = 1;
    q.enqueue(src);
 
    // standard breadth first traversal algorithm with a modification for destination vertex
    while (!q.isEmpty()) 
    {
        int u;
        q.dequeue(u);
        for (int i = 0; i < size; i++) 
        {
            if (adjMat[u][i] == 1 && visited[i] == false) 
            {
                visited[i] = true;
                predec[i] = u;
                q.enqueue(i);

                if (i == dest)
                {
                    delete [] visited;
                    return true;
                }
            }
        }
    }
    delete [] visited;
    return false;
}

 