//
//  student.h
//  c867_Project
//
//  Created by Obianuju Akusoba on 11/25/20.
//

#ifndef student_h
#define student_h
#pragma once
#include <iostream>
#include <iomanip>
#include "Degree.h"
using std::string;
using std::endl;
using std::cout;
using std::left;
using std::setw;

class Student
{
public:
    const static int daysInCourseArraySize = 3;
private:
    string studentId;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;
    
public:
    Student(); //Parameterless constructor - sets to default values.
    Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[3], DegreeProgram degreeProgram); //Full constructor
    ~Student(); //Destructor
    
    //Getters aka mutators
    string getStudentId();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDaysInCourse();
    DegreeProgram getDegreeProgram();
    
    //setters aka mutators
    void setStudentId(string studentId);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse[]);
    void setDegreeProgram(DegreeProgram degreeProgram);

    
    static void printHeader();//Displays a header for the data to follow
    
    void print(); //Displays this students data
    
    
};
    
    



#endif /* student_h */
