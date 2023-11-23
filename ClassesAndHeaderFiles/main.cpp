#include <iostream>
#include "StudentHelper.h"
#include "Student.h"


int main(int argc, char* argv[])
{
    int size = 3;
    
    Student** students = new Student*[size]{};


    for (int i = 0; i < size; ++i)
    {
        students[i] = new Student{};
    }

    for (int i = 0; i < size; ++i)
    {
        std::cout << "Student #" << i + 1 << ": \n";
        std::cout << "Coins: " << students[i]->GetCoins() << '\n';
        std::cout << "Diamonds: " << students[i]->GetCoins() << '\n';
        std::cout << "Badges: " << students[i]->GetBadges() << '\n';
        std::cout << "--------------------------" << '\n';
    }

    for (int i = 0; i < size; ++i)
    {
        delete students[i];
    }
    
    delete[] students;
    
    return 0;
}
