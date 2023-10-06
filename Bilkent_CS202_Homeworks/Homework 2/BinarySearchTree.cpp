/*
* Title: Binary Search Trees
* Author: Ata Seren
* ID: 21901575
* Section: 1
* Assignment: 2
* Description: Contains methods of a binary search tree
*/

#include "BinaryNode.h"
#include "BinarySearchTree.h"
using namespace std;

//constructor
BinarySearchTree::BinarySearchTree():root(NULL) 
{
    
}

//copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree& tree):root(tree.root)
{

}

//destructor
BinarySearchTree::~BinarySearchTree() 
{
    destructorHelper(root);
}

//helper for destructor
void BinarySearchTree::destructorHelper(BinaryNode *node) 
{
    if (node != NULL) 
    {
        destructorHelper(node->leftChildPtr);
        destructorHelper(node->rightChildPtr);
        delete node;
        node = NULL;
    }
}

//checks if tree is empty
bool BinarySearchTree::isEmpty()
{
    return root == NULL;
}

//gets height of a tree
int BinarySearchTree::getHeight() {
    return getHeightHelper(root);
} 

//helper for getHeight
int BinarySearchTree::getHeightHelper(BinaryNode *node) {
    if (node == NULL)
    {
        return 0;
    }
    
    int leftSide = getHeightHelper(node->leftChildPtr);
    int rightSide = getHeightHelper(node->rightChildPtr);
    
    return 1 + max(leftSide, rightSide);
}

//gets number of nodes in a tree
int BinarySearchTree::getNumberOfNodes()
{
    return getNumberOfNodesHelper(root);
}

//helper for getNumberOfNodes
int BinarySearchTree::getNumberOfNodesHelper(BinaryNode* node)
{
    if(node == 0)
    {
        return 0;
    }
    return 1 + getNumberOfNodesHelper(node->leftChildPtr) + getNumberOfNodesHelper(node->rightChildPtr);
}

//adds an item to tree
bool BinarySearchTree::add(const int newEntry) 
{
	return addHelper(root, newEntry);
}

//helper for add
bool BinarySearchTree::addHelper(BinaryNode*& node, int newItem) 
{
	if (node == NULL)
    {
        node = new BinaryNode(newItem, NULL, NULL);
        return true;
    }
    else if (newItem < node->item && node->item != newItem)
    {
        return addHelper(node->leftChildPtr, newItem);
    }
    else if (newItem > node->item && node->item != newItem)
    {
        return addHelper(node->rightChildPtr, newItem);
    }
    return false;
}

//removes an item to tree
bool BinarySearchTree::remove(const int anEntry)
{
    return removeHelper(root, anEntry);
}

//helper for remove
bool BinarySearchTree::removeHelper(BinaryNode*& node, int searchItem)
{
    if (node == NULL)
    {
        return false;
    }
    else if (searchItem == node->item)
    {
        removeNodeItem(node);
        return true;
    }
    else if (searchItem < node->item)
    {
        return removeHelper(node->leftChildPtr, searchItem);
    }
    else
    {
        return removeHelper(node->rightChildPtr, searchItem);
    }
    return false;
}

//another helper for remove (used inside removeHelper)
void BinarySearchTree::removeNodeItem(BinaryNode*& node)
{
    BinaryNode *delPtr;
	int replacementItem;

    //Test for a leaf
	if ( (node->leftChildPtr == NULL) && (node->rightChildPtr == NULL) ) 
    {
		delete node;
		node = NULL;
	}
    //Test for no left child
	else if (node->leftChildPtr == NULL)
    {
		delPtr = node;
		node = node->rightChildPtr;
		delPtr->rightChildPtr = NULL; 
		delete delPtr;
	}
    //Test for no right child
	else if (node->rightChildPtr == NULL) 
    {
        delPtr = node;
        node = node->leftChildPtr;
        delPtr->leftChildPtr = NULL;
        delete delPtr;
    }
	//There are two children:
	//Retrieve and delete the inorder successor
	else 
    {
		processLeftmost(node->rightChildPtr, replacementItem);
		node->item = replacementItem;
	}
}


//another helper for remove (used in removeNodeItem)
void BinarySearchTree::processLeftmost(BinaryNode *&nodePtr, int& treeItem)
{
    if (nodePtr->leftChildPtr == NULL) 
    {
		treeItem = nodePtr->item;
		BinaryNode *delPtr = nodePtr;
		nodePtr = nodePtr->rightChildPtr;
		delPtr->rightChildPtr = NULL; // defense
		delete delPtr;
	}
	else
    {
		processLeftmost(nodePtr->leftChildPtr, treeItem);
    }
}


//checks if given item is in tree
bool BinarySearchTree::contains(const int anEntry)
{
    return containsHelper(root, anEntry);
}

//helper for contains
bool BinarySearchTree::containsHelper(BinaryNode*& node, int anEntry)
{
    if (node == NULL) 
    {
        return false;
    }
    else if (anEntry < node->item) 
    {
        return containsHelper(node->leftChildPtr, anEntry);
    }
    else if (anEntry > node->item) 
    {
        return containsHelper(node->rightChildPtr, anEntry);
    }
    else 
    {
        return true;
    }
    return false;
}

//prints tree in preorder 
void BinarySearchTree::preorderTraverse() 
{ 
    cout<<"Items in preorder: ";
	preorder(root);
    cout<<endl;
}

//helper for preorderTraverse
void BinarySearchTree::preorder(BinaryNode* node)
{
    if (node != NULL) 
    {
		cout<< node->item <<" ";
		preorder(node->leftChildPtr);
		preorder(node->rightChildPtr);
    }
}

//prints tree in inorder 
void BinarySearchTree::inorderTraverse() 
{
    cout<<"Items in inorder: ";
	inorder(root);
    cout<<endl;
}

//helper for inorderTraverse
void BinarySearchTree::inorder(BinaryNode* node)
{
    if (node != NULL) 
    {
		inorder(node->leftChildPtr);
		cout<< node->item <<" ";
		inorder(node->rightChildPtr);
	}
}

//prints tree in postorder 
void BinarySearchTree::postorderTraverse() 
{
    cout<<"Items in postorder: ";
	postorder(root);
    cout<<endl;
}

//helper for postorderTraverse
void BinarySearchTree::postorder(BinaryNode* node)
{
    if (node != NULL) 
    {
		postorder(node->leftChildPtr);
		postorder(node->rightChildPtr);
		cout<< node->item <<" ";
	}
}

//prints tree in levelorder 
void BinarySearchTree::levelorderTraverse() 
{
    cout<<"Items in levelorder: ";
	int height = getHeightHelper(root);
    for (int i = 1; i <= height; i++)
    { 
        printLevel(root, i); 
    }
    cout<<endl;
}
 
//helper for levelorderTraverse
void BinarySearchTree::printLevel(BinaryNode* node, int level) 
{ 
    if (node != NULL) 
    {
        if (level == 1) 
        {
            cout << node->item <<" "; 
        }
        else if (level > 1) 
        { 
            printLevel(node->leftChildPtr, level-1); 
            printLevel(node->rightChildPtr, level-1); 
        } 
    }
} 

int BinarySearchTree::span(const int a, const int b)
{
    int count = 0;
    spanHelper(root, a, b, count);
    return count;
}

void BinarySearchTree::spanHelper(BinaryNode* node, int a, int b, int& count)
{
    if (node != NULL)
    {
        if (node->item >= a)
        {
            spanHelper(node->leftChildPtr, a, b, count);
        }
        if (node->item >= a && node->item <= b)
        {
            count++;
        }
        if (node->item <= b)
        {
            spanHelper(node->rightChildPtr, a, b,count);
        }
    }
}

void BinarySearchTree::mirror()
{
    mirrorHelper(root);
}

void BinarySearchTree::mirrorHelper(BinaryNode*& node)
{
    if(node != NULL)
    {
        mirrorHelper(node->leftChildPtr);
        mirrorHelper(node->rightChildPtr);
        
        BinaryNode* temp = node->leftChildPtr;
        node->leftChildPtr = node->rightChildPtr;
        node->rightChildPtr = temp;
    }
}