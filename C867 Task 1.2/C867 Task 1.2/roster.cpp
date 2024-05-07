//
//  roster.cpp
//  Class Roster
//
//  Created by Hunter Bradshaw on 3/7/24.
//
#include <iostream>
#include "roster.h"
#include "degree.h"

Student** Roster::getStudents() {
    return Roster::students;
}

// Add student to roster
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysInCourseArray[3] = {
        daysInCourse1, daysInCourse2, daysInCourse3
    };
    students[++lastIndex] = new Student(
        studentID, firstName, lastName, email, age, daysInCourseArray, degreeProgram);
}

//Parse student data
void Roster::parse(const std::string& studentData) {
    DegreeProgram degreeProgram = DegreeProgram::SOFTWARE;
    if (studentData.back() == 'Y')
        degreeProgram = DegreeProgram::SECURITY;
    else if (studentData.back() == 'K')
        degreeProgram = DegreeProgram::NETWORK;
    
    size_t rhs = studentData.find(",");
    std::string studentID = studentData.substr(0, rhs);
    
    size_t lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    std::string firstName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    std::string lastName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    std::string email = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));
    
    add(studentID, firstName, lastName, email, age, daysInCourse1,
        daysInCourse2, daysInCourse3, degreeProgram);
}

// Remove student from roster by student ID
void Roster::remove(std::string studentID) {
    bool found = false;
    for (int i = 0; i <= Roster::lastIndex; ++i) {
        if (students[i]->getStudentID() == studentID) {
            found = true;
            delete students[i];
            students[i] = nullptr;
            // Shift elements to fill the gap
            for (int j = i; j < Roster::lastIndex; ++j) {
                students[j] = students[j + 1];
            }
            Roster::lastIndex--;
            std::cout << "\nStudent with ID " << studentID << " was removed." << std::endl;
            break;
        }
    }
    if (!found) {
        std::cout << "\nError: Student with ID " << studentID << " was not found.\n" << std::endl;
    }
}

// Print all students in roster
void Roster::printAll() {
    std::cout << "\nDisplaying all students: " << std::endl;
    for (int i = 0; i <= Roster::lastIndex; i++) {
        (Roster::students)[i]->print();
    }
}

// Print average days in course for a given student
void Roster::printAverageDaysInCourse(std::string studentID) {
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::students[i]->getStudentID() == studentID) {
            std::cout << "\nAverage days in course for student " << studentID << ": ";
            std::cout << (students[i]->getDaysInCourse()[0] + students[i]->getDaysInCourse()[1] + students[i]->getDaysInCourse()[2]) / 3.0 << std::endl;
        }
    }
}

// Print invalid emails
void Roster::printInvalidEmails() {
    std::cout << "\nPrinting invalid emails: " << std::endl;
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++) {
        std::string email = (students[i]->getEmail());
        if ((email.find("@") == std::string::npos) || (email.find(".") == std::string::npos) || (email.find(" ") != std::string::npos)) {
            any = true;
            std::cout << "Invalid email: " << students[i]->getEmail() << std::endl;
        }
    }
    if (!any) {
        std::cout << "NONE" << std::endl;
    }
}

// Print students by degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    std::cout << "\nPrinting by degree program: " << degreeStrings[degreeProgram] << std::endl;
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::students[i]->getDegreeProgram() == degreeProgram) {
            students[i]->print();
        }
    }
}

// Destructor definition
Roster::~Roster() {
    // Delete all Student objects in classRosterArray
    for (int i = 0; i <= lastIndex; i++) {
        delete students[i];
        students[i] = nullptr;
    }
    std::cout << "Releasing dynamically allocated memory...\n" << std::endl;
}
