/*
---SimpleStudent.cpp
---Ata Seren
---21901575
---Section 2
*/
#include <iostream>
#include <string>
#include "SimpleStudent.h"

//constructor, destructor and copy constructor
Student::Student(const int sId, const string sName)
{
    id = sId;
    name = sName;
}

Student::~Student()
{
    
}

Student::Student (const Student& copyStudent) 
{
    id = copyStudent.id;
    name = copyStudent.name;
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