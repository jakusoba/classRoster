//
//  student.cpp
//  c867_Project
//
//  Created by Obianuju Akusoba on 11/26/20.
//

#include "student.h"
#include "Degree.h"
#include <string>
#include <iostream>

using namespace std;

//Parameterless constructor sets to default values.
Student::Student()
{
    this->studentId = ""; //Empty string is something, null pointer is nothing
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for(int i = 0; i < daysInCourseArraySize; i++){
        this->daysInCourse[i] = 0;
    }
    this->degreeProgram = DegreeProgram::SECURITY;
}

//Full constructor
Student::Student(string studentId, string firstName,string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {
    this->studentId = studentId;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for(int i = 0; i < daysInCourseArraySize; i++)this->daysInCourse[i] = daysInCourse[i];
    this->degreeProgram = degreeProgram;
    
}

Student::~Student() {}

string Student::getStudentId() {return this->studentId;}
string Student::getFirstName() {return this->firstName;}
string Student::getLastName() {return this->lastName;}
string Student::getEmailAddress() {return this->emailAddress;}
int Student::getAge() {return this->age;}
int* Student::getDaysInCourse() {return this->daysInCourse;} //An array name is a pointer
DegreeProgram Student::getDegreeProgram() {return this->degreeProgram;}

void Student::setStudentId(string studentId) {this->studentId = studentId;}
void Student::setFirstName(string firstName) {this->firstName = firstName;}
void Student::setLastName(string lastName) {this->lastName = lastName;}
void Student::setEmailAddress(string emailAddress) {this->emailAddress = emailAddress;}
void Student::setAge(int age) {this->age = age;}
void Student::setDaysInCourse(int daysInCourse[]) {
    for(int i = 0; i < daysInCourseArraySize; i++) {
        this->daysInCourse[i] = daysInCourse[i];
    }
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}
void Student::printHeader() //Used to print the header
{
    cout << "Output format: Student Id|First Name|Last Name|Age|Days In Course|Degree Program\n";
}

void Student::print()
{
    cout << this->getStudentId() << '\t'; //Using tab to separate output and getters.
    cout << this->getFirstName() << '\t';
    cout << this->getLastName() << '\t';
    cout << this->getEmailAddress() << '\t';
    cout << this->getAge() << '\t';
    cout << this->getDaysInCourse()[0] << ',';
    cout << this->getDaysInCourse()[1] << ',';
    cout << this->getDaysInCourse()[2] << '\t';
    cout << degreeProgramStrings[this->getDegreeProgram()] << endl; // DegreeProgram to string
}



