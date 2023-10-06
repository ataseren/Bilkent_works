/*
---SimpleLibrarySystem.h
---Ata Seren
---21901575
---Section 2
*/
#ifndef __SIMPLELIBRARYSYSTEM_H
#define __SIMPLELIBRARYSYSTEM_H
#include <iostream>
#include <string>
#include "SimpleStudent.h"
using namespace std;

class LibrarySystem {
    public:
        LibrarySystem();
        ~LibrarySystem();
        LibrarySystem(const LibrarySystem& copyLibrary);
        void addStudent(const int studentId, const string studentName);
        void deleteStudent(const int studentId);
        void showStudent(const int studentId) const;
    private:
        struct StudentNode {
            Student data;
            StudentNode* next;
        };
        int size; 
        StudentNode* head;
        StudentNode* findStudent(int id);
};
#endif