//
//  roster.cpp
//  c867_Project
//
//  Created by Obianuju Akusoba on 11/26/20.
//

#include <stdio.h>
#include "roster.h"
#include "Degree.h"
#include "student.h"
#include <iostream>
using namespace std;

//This parses out each row of student data one at a time.
void Roster::parse(string studentdata)
{
    DegreeProgram degreeProgram = SECURITY;  //Default value.
    if(studentdata.back() == 'Y') degreeProgram = SECURITY;
    else if(studentdata.back() == 'K') degreeProgram = NETWORK;
    else if(studentdata.back() == 'E') degreeProgram = SOFTWARE;
    
    int rhs = studentdata.find(","); //rhs is right hand side, so find the first comma from the rhs. This will find the index of the comma.
    string studentId = studentdata.substr(0,rhs); // Student ID, Extract the substring in front of the comma.
    
    int lhs  = rhs + 1; //Move past the comma
    rhs = studentdata.find(",", lhs);
    string firstName = studentdata.substr(lhs, rhs - lhs); //Student first name
    
    lhs = rhs + 1; //Keep going
    rhs = studentdata.find(",", lhs);
    string LastName = studentdata.substr(lhs, rhs - lhs); //Last name
    
    lhs = rhs + 1; //Keep going
    rhs = studentdata.find(",", lhs);
    string emailAddress = studentdata.substr(lhs, rhs - lhs); //email Address
    
    lhs = rhs + 1; //Keep going
    rhs = studentdata.find(",", lhs);
    string tempAge = studentdata.substr(lhs, rhs - lhs); //Age
    int age = stoi(tempAge);
    
    lhs = rhs + 1; //Keep going
    rhs = studentdata.find(",", lhs);
    int dayInCourse1 = stoi(studentdata.substr(lhs, rhs -lhs)); //Converts string to int.
    lhs = rhs + 1; //Keep going
    rhs = studentdata.find(",", lhs);
    int dayInCourse2 = stoi(studentdata.substr(lhs, rhs -lhs)); //Converts string to int.
    lhs = rhs + 1; //Keep going
    rhs = studentdata.find(",", lhs);
    int dayInCourse3 = stoi(studentdata.substr(lhs, rhs -lhs)); //Converts string to int.
    
    add(studentId,firstName, LastName, emailAddress, age, dayInCourse1, dayInCourse2, dayInCourse3, degreeProgram);
    
}
void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int dayInCourse1, int dayInCourse2, int dayInCourse3, DegreeProgram degreeProgram){
    int daysInCourse[3] = {dayInCourse1, dayInCourse2, dayInCourse3};
   
    
    classRosterArray[++lastIndex] = new Student(studentId, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);

}
void Roster::printAll(){
    Student::printHeader();
    for(int i = 0; i <= Roster::lastIndex; i++)(this->classRosterArray[i])->print();
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
    Student::printHeader();
    for(int i = 0; i <= Roster::lastIndex; i++) {
        if(Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
    }
    cout << std::endl;
    
}
void Roster::printInvalidEmails()
{
    bool any = false;
    for(int i = 0; i <=Roster::lastIndex; i++){
        string tempEmail = (classRosterArray[i]->getEmailAddress());
        if((tempEmail.find("@") == string::npos || tempEmail.find(".") == string::npos) || (tempEmail.find(" ") != string::npos)) {
            any = true;
            cout << tempEmail << ": " <<classRosterArray[i] << std::endl;
        }
    }
    if(!any) cout << "NONE" << std::endl;
}

void Roster::printAverageDaysInCourse(string studentId)
{
    for(int i = 0; i <= Roster::lastIndex; i++) {
        if(classRosterArray[i]->getStudentId()==studentId){
        
            
            cout << classRosterArray[i]->getStudentId() << ": ";
            cout << (classRosterArray[i]->getDaysInCourse()[0]  + classRosterArray[i]->getDaysInCourse()[1]  + classRosterArray[i]->getDaysInCourse()[2])/3.0 << std::endl;
        }
    
    }
    cout << std::endl;
}
bool Roster::remove(string studentId)
{
    bool success = false; //Assume the student you want to remove is not here.
    for(int i = 0; i <= Roster::lastIndex; i++)
    {
        if(classRosterArray[i]->getStudentId() == studentId){
            success = true; //Found the studentId
            if(i < numStudents - 1){
                Student* temp = classRosterArray[i]; //Swap it with the last student.
                classRosterArray[i] = classRosterArray[numStudents - 1];
                classRosterArray[numStudents - 1] = temp;
                
            }
            Roster::lastIndex--; //Last student is no longer visible.The student was never deleted, but it's just no longer visible.
        }
            
    }
    if(success){
        cout << "Student was removed from Roster." << std::endl << std::endl;
        
    }
    else cout << studentId << " Student was not found." << std::endl << std::endl;
    
    return  success;
}

Roster::~Roster()
{cout << "Destructor called!!" << std::endl << std::endl;
    for(int i = 0; i < numStudents; i++)
    {
        cout << "Destroying student #" << i + 1 << std::endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
    
}
    


