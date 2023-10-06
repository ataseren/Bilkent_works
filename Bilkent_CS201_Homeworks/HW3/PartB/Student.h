/*
---Student.h
---Ata Seren
---21901575
---Section 2
*/
#ifndef __SIMPLESTUDENT_H
#define __SIMPLESTUDENT_H
#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

class Student 
{
    public:
        Student(const int sId = 0, const string = "");
        ~Student();
        void setId(int newId);
        int getId();
        void setName(string newName);
        string getName();
        void checkoutBook(int id, string title, int year, int studentId);
        void returnBook(int id);
        void showAllBooks();
    private:
        int id;
        string name;
        
        struct BookNode 
        {
            Book info;
            BookNode* next;
        };
        BookNode* head_book;
        BookNode* findBook(int id);      
};
#endif