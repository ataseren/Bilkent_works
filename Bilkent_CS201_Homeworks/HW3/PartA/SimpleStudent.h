/*
---SimpleStudent.h
---Ata Seren
---21901575
---Section 2
*/
#ifndef __SIMPLESTUDENT_H
#define __SIMPLESTUDENT_H
#include <iostream>
#include <string>
using namespace std;

class Student {
    public:
        Student(const int sId = 0, const string = "");
        ~Student();
        Student(const Student &copyStudent);
        void setId(int newId);
        int getId();
        void setName(string newName);
        string getName();
    private:
        int id;
        string name;
        
};
#endif