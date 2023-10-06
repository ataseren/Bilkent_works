/*
---Student.cpp
---Ata Seren
---21901575
---Section 2
*/
#include <iostream>
#include <string>
#include <iomanip>
#include "Student.h"

//constructor, destructor and copy constructor
Student::Student(const int sId, const string sName): head_book(new BookNode)
{
    head_book->next = NULL;
    id = sId;
    name = sName;
}

Student::~Student()
{
    BookNode* ptr = head_book;
    for (BookNode* cur = ptr ; cur != NULL; cur = ptr) 
    {
        ptr = cur->next;
        delete cur;
    }
}

//setters and getters
void Student::setId(int newId)
{
    id = newId;
}

void Student::setName(string newName)
{
    name = newName;
}

int Student::getId()
{
    return id;
}

string Student::getName()
{
    return name;
}

Student::BookNode* Student::findBook(int bId)
{   
    for (BookNode* cur = head_book->next; cur != NULL; cur = cur->next) 
    {
        if(cur->info.getBookId() == bId )
        {
            return cur;
        }
    }
    return NULL;
}

void Student::checkoutBook(const int id, const string title, const int year, const int studentId)
{
    BookNode *cur;
    cur = head_book;
    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = new BookNode;
    cur = cur->next;
    cur->info.setBookId(id);
    cur->info.setBookTitle(title);
    cur->info.setBookYear(year);
    cur->info.setStudent(studentId);
    cur->next = NULL; 
}

void Student::returnBook(int id)
{
    bool exists = false;
    for (BookNode *prev = head_book, *cur = head_book->next; cur != NULL; cur = cur->next) 
    {
        if (cur->info.getBookId() == id) 
        {
            prev->next = cur->next;
            delete cur;
            exists = true;
            break;
        }
        prev = cur;
    }
    
    if (!exists)
    {
        cout << "No book with given ID found, no return happened." << endl;
    }
    else
    {
        cout << "Book " << id<<" has been returned." << endl;
    }
}

void Student::showAllBooks()
{
    if (head_book->next == NULL)
    {
       cout<<"Student "<<id<<" has no books"<<endl;
    }
    else
    {
        cout<<"Student " << id << " has checked out the following books: "<< endl;
        cout<<"Book id    Book name               Year "<<endl;
        for (BookNode* cur = head_book->next; cur != NULL; cur = cur->next)
        {
            cout<<left<<setw(11)<<cur->info.getBookId();
            cout<<left<<setw(24)<<cur->info.getBookTitle();
            cout<<left<<setw(11)<<cur->info.getBookYear()<<endl;;
        }
    }
}