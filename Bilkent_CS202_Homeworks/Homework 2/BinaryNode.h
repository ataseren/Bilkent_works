/*
* Title: Binary Search Trees
* Author: Ata Seren
* ID: 21901575
* Section: 1
* Assignment: 2
* Description: Header file of binary nodes
*/
#ifndef __BINARYNODE_H
#define __BINARYNODE_H
#include <iostream>

class BinaryNode {            // node in the tree
private:
    BinaryNode();
    BinaryNode(const int& nodeItem, BinaryNode *left = NULL, BinaryNode *right = NULL);
    BinaryNode(const BinaryNode &node);

    int item;       // data portion
    BinaryNode *leftChildPtr;  // pointer to left child
    BinaryNode *rightChildPtr; // pointer to right child

    friend class BinarySearchTree;
}; 
#endif