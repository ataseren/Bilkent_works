/*
---SimpleLibrarySystem.cpp
---Ata Seren
---21901575
---Section 2
*/
#include <iostream>
#include <string>
#include "SimpleLibrarySystem.h"
#include "SimpleStudent.h"
using namespace std;

//constructor, destructor and copy constructor
LibrarySystem::LibrarySystem(): head(new StudentNode), size(0){
    head->next = NULL;
}

LibrarySystem::~LibrarySystem() 
{
    StudentNode* ptr = head;
    for (StudentNode* cur = ptr ; cur != NULL; cur = ptr) {
        ptr = cur->next;
        delete cur;
    }   
}

LibrarySystem::LibrarySystem(const LibrarySystem& copyLibrary): size(copyLibrary.size), head(new StudentNode)
{
    StudentNode* cur = head;
    for (StudentNode* ptr = copyLibrary.head->next; ptr != NULL; ptr = ptr->next) 
    {
        cur->next = new StudentNode;
        cur = cur->next;
        cur->data = ptr->data;
    }  
    cur->next = NULL;
}

//required for adding student, finds the node with given ID
LibrarySystem::StudentNode* LibrarySystem::findStudent(int lId) 
{
    for (StudentNode* cur = head->next; cur != NULL; cur = cur->next) {
        int currentId = cur->data.getId();
        if( currentId == lId )
        {
            return cur;
        }
    }
    return NULL;
}

//adds student to list
void LibrarySystem::addStudent(const int studentId, const string studentName) 
{
    if (findStudent(studentId) == NULL) 
    {
        StudentNode *cur;
        cur = head;
        while(cur->next != NULL)
        {
           cur = cur->next;
        }
        cur->next = new StudentNode;
        cur = cur->next;
        cur->data.setId(studentId);
        cur->data.setName(studentName);
        cur->next = NULL;
        size++;
        cout << "Student added into library system." << endl;     
    }
    else
    {
       cout << "Student already exists in the library system." << endl; 
    }
}

void LibrarySystem::deleteStudent(const int studentId) {
    
    bool exists = false;
    for (StudentNode *prev = head, *cur = head->next; cur != NULL; cur = cur->next) 
    {
        if (cur->data.getId() == studentId) 
        {
            prev->next = cur->next;
            delete cur;
            size--;
            exists = true;
            break;
        }
        prev = cur;
    }
    
    if (!exists)
    {
        cout << "No student with given ID found, no deletion happened." << endl;
    }
    else
    {
        cout << "Student with given ID has deleted." << endl;
    }
}

void LibrarySystem::showStudent(const int studentId) const 
{
    if (head->next == NULL)
    {
        cout << "There are no students in the system." << endl;
    }
    else
    {
        bool exists = false;
        for (StudentNode* cur = head->next; cur != NULL; cur = cur->next)
        {
            if(cur->data.getId() == studentId)
            {
               cout<< "Name of student: " << cur->data.getName() << endl;
               cout<< "ID of student: " << cur->data.getId() << endl;
               exists = true;
              break;
            }
        }

        if (!exists)
        {
            cout << "No student with given ID found." << endl;
        }
    }
    
    
    
}


