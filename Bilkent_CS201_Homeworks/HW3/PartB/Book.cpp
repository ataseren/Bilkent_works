/*
---Book.cpp
---Ata Seren
---21901575
---Section 2
*/
#include <iostream>
#include <string>
#include "Book.h"

//constructor
Book::Book(const int bId, const string bTitle, const int bYear)
{
    bookId = bId;
    bookTitle = bTitle;
    bookYear = bYear;
    checked = false;
    student = 0;
}

//destructor
Book::~Book()
{
    
}


//setters and getters
void Book::setBookId(int newId)
{
    bookId = newId;
}

void Book::setBookTitle(string newTitle)
{
    bookTitle = newTitle;
}

void Book::setBookYear(int newYear)
{
    bookYear = newYear;
}

void Book::setChecked(bool check)
{
    checked = check;
}
       
void Book::setStudent(int id)
{
    student = id;
}

int Book::getBookId()
{
    return bookId;
}

string Book::getBookTitle()
{
    return bookTitle;
}

int Book::getBookYear()
{
    return bookYear;
}

bool Book::getChecked()
{
    return checked;
}

int Book::getStudent()
{
    return student;
}