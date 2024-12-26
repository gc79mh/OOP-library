#include <iostream>
#include "../inc/Student.h"

int main() {
    Student student("John Doe", 20, 3.75);

    student.printDetails();

    student.setName("Jane Smith");
    student.setAge(22);
    student.setGPA(3.85);

    std::cout << "\nUpdated Details:" << std::endl;
    student.printDetails();

    return 0;
}

