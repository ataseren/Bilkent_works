/*
* Title: Binary Search Trees
* Author: Ata Seren
* ID: 21901575
* Section: 1
* Assignment: 2
* Description: Header file of binary search tree, contains its methods
*/

#ifndef __BINARYSEARCHTREE_H
#define __BINARYSEARCHTREE_H
#include "BinaryNode.h"
#include <iostream>

class BinarySearchTree {            // node in the tree
    public:
        BinarySearchTree();
        BinarySearchTree(const BinarySearchTree& tree);
        ~BinarySearchTree();

        bool isEmpty();
        int getHeight();
        int getNumberOfNodes();

        bool add(const int newEntry);
        bool remove(const int anEntry);
        bool contains(const int anEntry);

        void preorderTraverse();
        void inorderTraverse();
        void postorderTraverse();
        
        void levelorderTraverse();
        int span(const int a, const int b);
        void mirror();

        //helpers
        void destructorHelper(BinaryNode* node);
        int getHeightHelper(BinaryNode* node);
        int getNumberOfNodesHelper(BinaryNode* node);
        bool addHelper(BinaryNode*& node, int newItem);
        bool removeHelper(BinaryNode*& node, int searchItem);
        void removeNodeItem(BinaryNode*& node);
        void processLeftmost(BinaryNode *&nodePtr, int& treeItem);
        bool containsHelper(BinaryNode*&, int anEntry);
        void preorder(BinaryNode* node);
        void inorder(BinaryNode* node);
        void postorder(BinaryNode* node);
        void printLevel(BinaryNode* node, int level);
        void spanHelper(BinaryNode* node, int a, int b, int& count); 
        void mirrorHelper(BinaryNode*& node);

        
    
    private:
        BinaryNode* root;

}; 
#endif