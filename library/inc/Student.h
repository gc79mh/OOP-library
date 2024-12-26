#ifndef TEST_H 
#define TEST_H

#include <string>

class test {
private:
    int age;
    double gpa;

public:
    // Constructor
    test(const std::string &name, int age, double gpa);

    // Getters
    std::string getName() const;
    int getAge() const;
    double getGPA() const;

    // Setters
    void setName(const std::string &name);
    void setAge(int age);
    void setGPA(double gpa);

    // Other member functions
    void printDetails() const;
};

#endif // STUDENT_H

