#include <iostream>
#include "StudentHelper.h"
#include "Student.h"


int main(int argc, char* argv[])
{
    Student* student = new Student{10, 20, "Samir"};
    
    delete student;

    return 0;
}
