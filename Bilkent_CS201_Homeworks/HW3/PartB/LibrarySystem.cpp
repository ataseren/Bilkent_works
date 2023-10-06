/*
---LibrarySystem.cpp
---Ata Seren
---21901575
---Section 2
*/
#include <iostream>
#include <string>
#include <iomanip>
#include "LibrarySystem.h"
using namespace std;

//constructor, destructor
LibrarySystem::LibrarySystem(): head_uBook(new UncheckedBookNode), head_cBook(new CheckedBookNode), head(new StudentNode), size(0) {
    head->next = NULL;
    head_uBook->nextU = NULL;
    head_cBook->nextC = NULL;
}

LibrarySystem::~LibrarySystem() 
{
    StudentNode* ptr = head;
    for (StudentNode* cur = ptr ; cur != NULL; cur = ptr) {
        ptr = cur->next;
        delete cur;
    }
    
    UncheckedBookNode* ptr2 = head_uBook;
    for (UncheckedBookNode* cur2 = ptr2 ; cur2 != NULL; cur2 = ptr2) {
        ptr2 = cur2->nextU;
        delete cur2;
    }     

    CheckedBookNode* ptr3 = head_cBook;
    for (CheckedBookNode* cur3 = ptr3 ; cur3 != NULL; cur3 = ptr3) {
        ptr3 = cur3->nextC;
        delete cur3;
    }  
}


//required for adding student, finds the node with given ID
LibrarySystem::StudentNode* LibrarySystem::findStudent(int lId) 
{
    for (StudentNode* cur = head->next; cur != NULL; cur = cur->next) 
    {
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
        cout << "Student " << studentId << " has been added." << endl;     
    }
    else
    {
       cout << "Student " << studentId << " already exists." << endl;     
    }
}

//deletes student from list
void LibrarySystem::deleteStudent(const int studentId) {
    
    bool exists = false;
    for (StudentNode *prev = head, *cur = head->next; cur != NULL; cur = cur->next) 
    {
        for (CheckedBookNode* cur2 = head_cBook->nextC; cur2 != NULL; cur2 = cur2->nextC)
        {
            if (cur2->cInfo.getStudent() == studentId)
            {
                returnBook(cur2->cInfo.getBookId());
            }    
        }
        
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
        cout << "Student " << studentId << " does not exist" << endl;
    }
    else
    {
        cout << "Student " << studentId << " has been deleted." << endl;    
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
                cout<< "Student ID: " << cur->data.getId();
                cout<< "   Student name: " << cur->data.getName() << endl;
                cur->data.showAllBooks();
                exists = true;
                break;
            }
        }

        if (!exists)
        {
            cout << "Student " << studentId <<" does not exist" << endl;
        }
    }   
}

//required for adding book, finds the node with given ID
LibrarySystem::UncheckedBookNode* LibrarySystem::find_uBook(int bId) 
{
    for (UncheckedBookNode* cur = head_uBook->nextU; cur != NULL; cur = cur->nextU) 
    {
        if(cur->uInfo.getBookId() == bId )
        {
            return cur;
        }
    }
    return NULL;
}

LibrarySystem::CheckedBookNode* LibrarySystem::find_cBook(int bId) 
{
    for (CheckedBookNode* cur = head_cBook->nextC; cur != NULL; cur = cur->nextC) 
    {
        if(cur->cInfo.getBookId() == bId )
        {
            return cur;
        }
    }
    return NULL;
}

//adds book to list
void LibrarySystem::addBook(const int bookId, const string bookName, const int bookYear) 
{
    if(find_uBook(bookId) == NULL) 
    {
        UncheckedBookNode *cur;
        cur = head_uBook;
        while(cur->nextU != NULL)
        {
           cur = cur->nextU;
        }
        cur->nextU = new UncheckedBookNode;
        cur = cur->nextU;
        cur->uInfo.setBookId(bookId);
        cur->uInfo.setBookTitle(bookName);
        cur->uInfo.setBookYear(bookYear);
        cur->nextU = NULL;
        cout << "Book "<< bookId <<" has been added." << endl;     
    }
    else
    {
       cout << "Book "<< bookId <<" already exists." << endl;   
    }
}

void LibrarySystem::addBookNoText(const int bookId, const string bookName, const int bookYear) 
{
    if(find_uBook(bookId) == NULL) 
    {
        UncheckedBookNode *cur;
        cur = head_uBook;
        while(cur->nextU != NULL)
        {
           cur = cur->nextU;
        }
        cur->nextU = new UncheckedBookNode;
        cur = cur->nextU;
        cur->uInfo.setBookId(bookId);
        cur->uInfo.setBookTitle(bookName);
        cur->uInfo.setBookYear(bookYear);
        cur->uInfo.setStudent(0);
        cur->nextU = NULL;
    }
    else
    {

    }
}


//deletes book from list
void LibrarySystem::deleteBook(const int bookId) {
    
    if(find_uBook(bookId) != NULL)
    {
        for (UncheckedBookNode *prev = head_uBook, *cur = head_uBook->nextU; cur != NULL; cur = cur->nextU) 
        {
            if (cur->uInfo.getBookId() == bookId) 
            {
                prev->nextU = cur->nextU;
                delete cur;
                size--;
                break;
            }
            prev = cur;
        }
            cout << "Book " << bookId << " has not been checked out." << endl;
            cout << "Book " << bookId << " has been deleted." << endl;
    }
    else if (find_cBook(bookId) != NULL)
    {
        returnBook(bookId);
        deleteBookNoText(bookId);
        cout << "Book " << bookId << " has been deleted." << endl;
    }
    else
    {
        cout << "Book " << bookId << " does not exist." << endl;
    }
}

void LibrarySystem::deleteBookNoText(const int bookId) {
    
    if(find_uBook(bookId) != NULL)
    {
        for (UncheckedBookNode *prev = head_uBook, *cur = head_uBook->nextU; cur != NULL; cur = cur->nextU) 
        {
            if (cur->uInfo.getBookId() == bookId) 
            {
                prev->nextU = cur->nextU;
                delete cur;
                size--;
                break;
            }
            prev = cur;
        }
    }
    else if (find_cBook(bookId) != NULL)
    {
        returnBook(bookId);
    }
    else
    {

    }
}

void LibrarySystem::addBookChecked(const int bookId, const int studentId)
{
    if(find_cBook(bookId) == NULL) 
    {
        UncheckedBookNode *book = find_uBook(bookId);
        CheckedBookNode *cur;
        cur = head_cBook;
        while(cur->nextC != NULL)
        {
           cur = cur->nextC;
        }
        cur->nextC = new CheckedBookNode;
        cur = cur->nextC;
        cur->cInfo.setBookId(book->uInfo.getBookId());
        cur->cInfo.setBookTitle(book->uInfo.getBookTitle());
        cur->cInfo.setBookYear(book->uInfo.getBookYear());
        cur->cInfo.setChecked(true);
        cur->cInfo.setStudent(studentId);
        cur->nextC = NULL; 
    }
}

void LibrarySystem::checkoutBook(const int bookId, const int studentId)
{
    StudentNode* found = findStudent(studentId);
    UncheckedBookNode* check = find_uBook(bookId); 
    CheckedBookNode* check2 = find_cBook(bookId); 
    if (check == NULL && check2 != NULL)
    {
        cout << "Book "<< bookId <<" has been already checked out by another student"<<endl;
    } 
    else if (check == NULL)
    {
        cout << "Book " << bookId << " does not exist for checkout"<<endl;
    }  
    else if (found == NULL)
    {
        cout << "Student "<< studentId << " does not exist for checkout"<<endl;
    }
    else
    {
        found->data.checkoutBook(check->uInfo.getBookId(),check->uInfo.getBookTitle(),check->uInfo.getBookYear(), studentId);
        cout << "Book " << bookId << " has been checked out by student " << studentId <<endl;    
        addBookChecked(bookId, studentId);
        deleteBookNoText(bookId);
    }
}

void LibrarySystem::deleteBookChecked(const int bookId)
{
    bool exists = false;
    for (CheckedBookNode *prev = head_cBook, *cur = head_cBook->nextC; cur != NULL; cur = cur->nextC) 
    {
        if (cur->cInfo.getBookId() == bookId) 
        {
            prev->nextC = cur->nextC;
            delete cur;
            size--;
            exists = true;
            break;
        }
        prev = cur;
    }
}


void LibrarySystem::returnBook(const int bookId)
{
    CheckedBookNode* book = find_cBook(bookId);
    if (book == NULL&&find_uBook(bookId) != NULL)
    {
        cout << "Book "<<bookId<< " has not been checked out."<< endl;
    }
    else if (book == NULL&&find_uBook(bookId) == NULL)
    {
        cout << "Book "<<bookId<< " does not exist."<< endl;
    }
    else
    {
        StudentNode* found = findStudent(book->cInfo.getStudent());
        found->data.returnBook(bookId);
        addBookNoText(book->cInfo.getBookId(), book->cInfo.getBookTitle(), book->cInfo.getBookYear());
        deleteBookChecked(bookId);
    }
}

void LibrarySystem::showAllBooks() const
{
    cout<<"Book id    Book name               Year       Status"<<endl;
    for (UncheckedBookNode* cur = head_uBook->nextU; cur != NULL; cur = cur->nextU)
        {
            cout<<left<<setw(11)<<cur->uInfo.getBookId();
            cout<<left<<setw(24)<<cur->uInfo.getBookTitle();
            cout<<left<<setw(11)<<cur->uInfo.getBookYear();
            if (cur->uInfo.getStudent() == 0)
            {
                cout<< "Not checked out" <<endl;
            }
            else
            {
                cout<<"Checked out by student "<<cur->uInfo.getStudent() <<endl;
            }
        }
    
    for (CheckedBookNode* cur2 = head_cBook->nextC; cur2 != NULL; cur2 = cur2->nextC)
        {            
            cout<<left<<setw(11)<<cur2->cInfo.getBookId();
            cout<<left<<setw(24)<<cur2->cInfo.getBookTitle();
            cout<<left<<setw(11)<<cur2->cInfo.getBookYear();
            if (cur2->cInfo.getStudent() == 0)
            {
                cout<< "Not checked out" <<endl;
            }
            else
            {
                cout<<"Checked out by student "<<cur2->cInfo.getStudent() <<endl;
            }
        }
}

void LibrarySystem::showBook(const int bookId) const
{
    for (UncheckedBookNode* cur = head_uBook->nextU; cur != NULL; cur = cur->nextU)
    {
        if(cur->uInfo.getBookId() == bookId)
        {
            cout<<left<<setw(11)<<cur->uInfo.getBookId();
            cout<<left<<setw(24)<<cur->uInfo.getBookTitle();
            cout<<left<<setw(11)<<cur->uInfo.getBookYear();
            if (cur->uInfo.getStudent() == 0)
            {
                cout<< "Not checked out" <<endl;
            }
            else
            {
                cout<<"Checked out by student "<<cur->uInfo.getStudent() <<endl;
            }
            break;
        }
    }
    for (CheckedBookNode* cur2 = head_cBook->nextC; cur2 != NULL; cur2 = cur2->nextC)
    {
        if(cur2->cInfo.getBookId() == bookId)
        {
            cout<<left<<setw(11)<<cur2->cInfo.getBookId();
            cout<<left<<setw(24)<<cur2->cInfo.getBookTitle();
            cout<<left<<setw(11)<<cur2->cInfo.getBookYear();
            if (cur2->cInfo.getStudent() == 0)
            {
                cout<< "Not checked out" <<endl;
            }
            else
            {
                cout<<"Checked out by student "<<cur2->cInfo.getStudent() <<endl;
            }
            break;
        }
    }
}
