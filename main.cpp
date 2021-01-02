//
//  main.cpp
//  c867_Project
//
//  Created by Obianuju Akusoba on 11/25/20.
//

#include <iostream>
#include <sstream>
#include <vector>
#include "roster.h"
#include "student.h"
#include "Degree.h"
#include <string>
#include <cstdlib>
#include <stdlib.h>



int main()
{
    const string studentData[] =

    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Obianuju,Akusoba,oakusob@wgu.edu,21,10,20,30,SOFTWARE"
        
    };
    
    const int numStudents = 5; //Arrays dont record their sizes
    Roster classRoster; //This creates a parameterless roster
    

    cout << "C867 Scripting and Programming Applications." << endl;
    cout << "Written in C++ by Obianuju Akusoba, Student ID: 001348128" << endl;
 
    
    cout << endl;
    
    for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);
    
    cout << "Displaying all students:  " << std::endl;
    classRoster.printAll();
    cout << std::endl;
    
    
    cout << "Displaying SOFTWARE students: "  << std::endl;
    classRoster.printByDegreeProgram(SOFTWARE); //Cast integer to degree program
      
    
    cout << "Displaying invalid email addresses:" << std :: endl;
    classRoster.printInvalidEmails();
    cout << std::endl;
    
    cout << "Displaying average days in course: " << std::endl;
    for (int i  = 0; i <numStudents; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentId());
        
        
    }
    cout << "Removing student A3." << endl;
    if(classRoster.remove("A3")) cout << "Modified Roster" << endl;
    else cout << "Student A3 not found." << endl;
    classRoster.printAll();
    
    cout <<"\n" << endl;
    
 
    cout << "Removing student A3." << endl;
    classRoster.remove("A3");
    
    
   
    
    return 0;
    
}
