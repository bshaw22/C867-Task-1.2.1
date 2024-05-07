//
//  roster.h
//  Class Roster
//
//  Created by Hunter Bradshaw on 3/7/24.
//

#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <string>
#include "student.h"

class Roster {
    
private:
    int lastIndex = -1;
    const static int numberOfStudents = 5;
    Student* students[numberOfStudents] = {
        nullptr, nullptr, nullptr, nullptr, nullptr
    };

public:
    Student** getStudents();
    
    void parse(const std::string& studentData);
    
    // Add student to roster
    void add(std::string studentID,
             std::string firstName,
             std::string lastName,
             std::string email, 
             int age,
             int daysInCourse1,
             int daysInCourse2, 
             int daysInCourse3,
             DegreeProgram degreeProgram);

    // Remove student from roster by student ID
    void remove(std::string studentID);

    // Print all students in roster
    void printAll();

    // Print average days in course for a given student
    void printAverageDaysInCourse(std::string studentID);

    // Print invalid emails
    void printInvalidEmails();

    // Print students by degree program
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
    // Destructor declaration
    ~Roster();
};

#endif

