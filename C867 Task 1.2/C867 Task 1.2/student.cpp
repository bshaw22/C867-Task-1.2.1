//
//  student.cpp
//  Class Roster
//
//  Created by Hunter Bradshaw on 3/7/24.
//

#include <iostream>
#include "student.h"
#include <string>

Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    for (int i = 0; i < daysInCourseArraySize; i++) {
        this->daysInCourse[i] = 0;
    }
    this->degreeProgram = DegreeProgram::SOFTWARE;
}

Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string email, int age, int daysInCourse[], DegreeProgram degreeProgram) {
    
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    this->daysInCourse = new int[daysInCourseArraySize]();
    for (int i = 0; i < daysInCourseArraySize; i++) {
        this->daysInCourse[i] = daysInCourse[i];
    }
    this->degreeProgram = degreeProgram;
}

// Accessors
std::string Student::getStudentID() { 
    return this->studentID; }
std::string Student::getFirstName() { 
    return this->firstName; }
std::string Student::getLastName() { 
    return this->lastName; }
std::string Student::getEmail() { 
    return this->email; }
int Student::getAge() { 
    return this->age; }
int* Student::getDaysInCourse() { 
    return this->daysInCourse; }
DegreeProgram Student::getDegreeProgram() { 
    return this->degreeProgram; }

// Mutators
void Student::setStudentID(std::string studentID) {
    this->studentID = studentID; }
void Student::setFirstName(std::string firstName) {
    this->firstName = firstName; }
void Student::setLastName(std::string lastName) {
    this->lastName = lastName; }
void Student::setEmail(std::string email) {
    this->email = email; }
void Student::setAge(int age) {
    this->age = age; }
void Student::setDaysInCourse(int daysInCourse[]) {
    for (int i = 0; i < daysInCourseArraySize; ++i) {
        this->daysInCourse[i] = daysInCourse[i];
    }
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

//Print
void Student::print() {
    std::cout << getStudentID();
    std::cout << "\tFirst Name: " << getFirstName();
    std::cout << "\tLast Name: " << getLastName();
    std::cout << "\tAge: " << getAge();
    std::cout << "\tDays in Course: {" << getDaysInCourse()[0] << ", " << getDaysInCourse()[1] << ", " << getDaysInCourse()[2] << "}";
    std::cout << "\tDegree Program: " << degreeStrings[static_cast<int>(getDegreeProgram())] << std::endl;
}

