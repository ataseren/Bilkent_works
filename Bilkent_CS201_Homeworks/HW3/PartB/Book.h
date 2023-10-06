/*
---Book.h
---Ata Seren
---21901575
---Section 2
*/
#ifndef __BOOK_H
#define __BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book
{
    public:
        Book(const int bId = 0, const string bTitle = "", const int bYear = 0);
        ~Book();
        string getName() const;
        void setBookId(int bookId);
        void setBookTitle(string bookTitle);
        void setBookYear(int bookYear);
        void setChecked(bool check);
        void setStudent(int id);

        int getBookId();
        string getBookTitle();
        int getBookYear();
        bool getChecked();
        int getStudent();
    
    private:
        int bookId;
        string bookTitle;
        int bookYear;
        bool checked;
        int student;
};

#endif