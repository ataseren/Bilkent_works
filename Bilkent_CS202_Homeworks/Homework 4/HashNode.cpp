/**
* Title : Balanced Search Trees , Hashing and Graphs
* Author : Ata Seren
* Id: 21901575
* Section : 1
* Assignment : 4
* Description : class file for hash node that carries data
*/

#include <iostream>
#include <string>
#include "HashNode.h"
using namespace std;

HashNode::HashNode()
{
    id = -1;
    word = "";
    next = NULL;
}

HashNode::~HashNode()
{

}
