//
//  roster.h
//  c867_Project
//
//  Created by Obianuju Akusoba on 11/26/20.
//

#ifndef roster_h
#define roster_h
#pragma once
#include <string>
#include "student.h"
#include "Degree.h"

using std::string;

class Roster
{
public: //This stores pointers to each student object in the roster.
    int lastIndex = -1;
    const static int numStudents = 5;

    Student* classRosterArray[numStudents]; //Not declared dynamically.
  

    
    
public:
    //Student has no constructor
    //The parse method goes through a set of comma delimited strings and extracts the data of a student.
    void parse(string row);
    //All book data is then passed into add method which creates the student object and places it in the roster.
    void add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int DaysInCourse3, DegreeProgram degreeProgram);
    
    void printAll(); //This calls the print() method in Student class for each student.
    void printByDegreeProgram(DegreeProgram degreeProgram);
    void printInvalidEmails();
    void printAverageDaysInCourse(string studentId);
    bool remove(string studentId);
    
    ~Roster(); //Destroys the roster as memory is not dynamically allocated.
};


#endif /* roster_h */
