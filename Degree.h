//
//  Degree.h
//  c867_Project
//
//  Created by Obianuju Akusoba on 11/25/20.
//

#ifndef Degree_h
#define Degree_h
#pragma once
#include <string>
enum DegreeProgram {SECURITY, NETWORK, SOFTWARE};

//This a parallel array of strings created to pop out a string for each degree program, remember the underlying datatype of enum is int which uses index.
static const std:: string degreeProgramStrings[] = {"SECURITY", "NETWORK", "SOFTWARE"};


#endif /* Degree_h */
