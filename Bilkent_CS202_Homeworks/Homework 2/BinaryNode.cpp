/*
* Title: Binary Search Trees
* Author: Ata Seren
* ID: 21901575
* Section: 1
* Assignment: 2
* Description: Necessary methods for binary nodes
*/

#include "BinaryNode.h"
#include <iostream>

BinaryNode::BinaryNode():item(0), leftChildPtr(NULL), rightChildPtr(NULL)
{

}

BinaryNode::BinaryNode(const int& nodeItem, BinaryNode *left, BinaryNode *right):item(nodeItem), leftChildPtr(left), rightChildPtr(right)
{

}

BinaryNode::BinaryNode(const BinaryNode &node):item(node.item), leftChildPtr(node.leftChildPtr), rightChildPtr(node.rightChildPtr) 
{
    
}