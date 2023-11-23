#include <iostream>
#include "StudentHelper.h"
#include "Student.h"


int main(int argc, char* argv[])
{
    Student* student = new Student[3];

    delete[] student;

    return 0;
}
