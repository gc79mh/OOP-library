#include "../inc/Student.h"
#include <iostream>

// Constructor
Student::Student(const std::string &name, int age, double gpa)
    : name(name), age(age), gpa(gpa) {}

// Getters
std::string Student::getName() const {
    return name;
}

int Student::getAge() const {
    return age;
}

double Student::getGPA() const {
    return gpa;
}

// Setters
void Student::setName(const std::string &name) {
    this->name = name;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setGPA(double gpa) {
    this->gpa = gpa;
}

// Other member functions
void Student::printDetails() const {
    std::cout << "Name: " << name << "\nAge: " << age << "\nGPA: " << gpa << std::endl;
}

