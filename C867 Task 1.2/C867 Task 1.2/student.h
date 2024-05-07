//
//  student.h
//  Class Roster
//
//  Created by Hunter Bradshaw on 3/7/24.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"

class Student {
    
public:
    const static int daysInCourseArraySize = 3;

private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string email;
    int age;
    int* daysInCourse;
    DegreeProgram degreeProgram;

public:
    Student();
    Student(
            std::string studentID,
            std::string firstName,
            std::string lastName,
            std::string email,
            int age,
            int daysInCourse[],
            DegreeProgram degreeProgram);

    // Accessors
    std::string getStudentID();
    std::string getFirstName();
    std::string getLastName();
    std::string getEmail();
    int getAge();
    int* getDaysInCourse();
    DegreeProgram getDegreeProgram();

    // Mutators
    void setStudentID(std::string studentID);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setEmail(std::string email);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse[]);
    void setDegreeProgram(DegreeProgram degreeProgram);

    // Print
    void print();
};

#endif
