/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Ata Seren
* Id: 21901575
* Section : 1
* Assignment : 4
* Description : header file for hash node that carries data
*/
#ifndef __HASHNODE_H
#define __HASHNODE_H
#include <iostream>
#include <string>
using namespace std;
class HashNode{
    public:
        HashNode();
        ~HashNode();

    private:
        string word;
        int id;
        HashNode* next;
        friend class WordNetwork;
};
#endif