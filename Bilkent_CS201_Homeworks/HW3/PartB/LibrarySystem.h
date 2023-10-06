/*
---LibrarySystem.h
---Ata Seren
---21901575
---Section 2
*/
#ifndef __LIBRARYSYSTEM_H
#define __LIBRARYSYSTEM_H
#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

class LibrarySystem {
    public:
        LibrarySystem();
        ~LibrarySystem();
        
        void addBook(const int bookId, const string bookName, const int bookYear);
        void deleteBook(const int bookId);

        void addStudent(const int studentId, const string studentName);
        void deleteStudent(const int studentId);

        void checkoutBook(const int bookId, const int studentId);
        void returnBook(const int bookId);

        void showAllBooks() const;
        void showBook(const int bookId) const;
        
        void showStudent(const int studentId) const;

        void addBookChecked(const int bookId, const int studentId);
        void deleteBookChecked(const int bookId);

        void deleteBookNoText(const int bookId);
        void addBookNoText(const int bookId, const string bookName, const int bookYear);
    private:
        struct StudentNode 
        {
            Student data;
            StudentNode* next;
        };
        int size; 
        StudentNode* head;
        StudentNode* findStudent(int id);

        struct CheckedBookNode 
        {
            Book cInfo;
            CheckedBookNode* nextC;
        };
        CheckedBookNode* head_cBook;
        CheckedBookNode* find_cBook(int id);

        struct UncheckedBookNode 
        {
            Book uInfo;
            UncheckedBookNode* nextU;
        };
        UncheckedBookNode* head_uBook;
        UncheckedBookNode* find_uBook(int id);

        
};
#endif