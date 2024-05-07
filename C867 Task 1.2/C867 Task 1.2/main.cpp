//
//  main.cpp
//  Class Roster
//
//  Created by Hunter Bradshaw on 3/7/24.
//

#include <iostream>
#include "roster.h"

int main() {
    
    std::cout << "Course Title: C867 - Scripting and Programming - Applications" << std::endl;
    std::cout << "Programming Language: C++" << std::endl;
    std::cout << "WGU Student ID: 1413698" << std::endl;
    std::cout << "Name: Hunter Bradshaw" << std::endl;

    // Define student data
    const std::string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Hunter,Bradshaw,hbrads8@wgu.edu,30,30,38,28,SOFTWARE"
    };
    
    const int numberOfStudents = 5;
    
    // Initialize roster object
    Roster classRoster;
    
    //Parsing student data
    for (int i = 0; i < numberOfStudents; i++) {
        classRoster.parse(studentData[i]);
    }
    
    //Demonstrating required functionality 
    classRoster.printAll();
    classRoster.printInvalidEmails();
    classRoster.printAverageDaysInCourse("A5");
    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}
