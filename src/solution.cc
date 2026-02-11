#include "solution.hpp"
#include "student.hpp"
#include <fstream>
#include <string>

Student ReadStudentRecFromStream(std::istream& is) {
    Student student;
    std::string firstName, lastName;
    unsigned int uin = 0;        // ← 加上 = 0
    char comma = '\0';           // ← 加上 = '\0'
    double gpa = 0.0;            // ← 加上 = 0.0
    
    is >> firstName;
    if (is.fail()) return Student{};
    
    is >> lastName;
    if (is.fail()) return Student{};
    
    if (lastName.empty() || lastName.back() != ',') {
        return Student{};
    }
    lastName.pop_back();
    
    student.full_name = firstName + " " + lastName;
    
    is >> uin;
    if (is.fail()) return Student{};
    
    is >> comma;
    if (is.fail() || comma != ',') return Student{};
    
    is >> gpa;
    if (is.fail()) return Student{};
    
    student.uin = uin;
    student.gpa = gpa;
    
    return student;
}
