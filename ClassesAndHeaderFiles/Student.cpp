#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include "StudentHelper.h"
#include <iostream>

Student::~Student()
{
    std::cout << "Student::~Student()" << '\n';

    delete[] m_name;
}

Student::Student()
{
    std::cout << "Student::Student()" << '\n';

    m_coins = 0;
    m_diamonds = 0;
    m_name = nullptr;

    Objects++;
}

Student::Student(int a_diamonds, int a_coins, const char* a_name)
{
    std::cout << "Student::Student(int a_diamonds, int a_coins, const char* a_name)" << '\n';

    m_name = nullptr;

    SetDiamonds(a_diamonds);
    SetCoins(a_coins);
    SetName(a_name);

    Objects++;
}


Student::Student(int a_diamonds, int a_coins, const char* a_name, int a_badges)
{
    std::cout << "Student::Student(int a_diamonds, int a_coins, const char* a_name, int a_badges)" << '\n';

    this->m_diamonds = a_diamonds;
    this->m_coins = a_coins;
    this->m_name = new char[32];
    this->m_badges = a_badges;

    strcpy(m_name, a_name);

    Objects++;
}

int Student::GetDiamonds()
{
    return m_diamonds;
}

void Student::SetDiamonds(int a_diamonds)
{
    if (StudentHelper::IsDiamondsValid(a_diamonds))
    {
        m_diamonds = a_diamonds;
    }
}

int Student::GetCoins()
{
    return m_coins;
}
void Student::SetCoins(int a_coins)
{
    if (a_coins >= 0 && a_coins < 2000)
    {
        m_coins = a_coins;
    }
}

const char* Student::GetName()
{
    return m_name;
}

void Student::SetName(const char* a_name)
{
    delete[] m_name;

    int len = strlen(a_name) + 1;

    m_name = new char[len];

    strcpy(m_name, a_name);
}

int Student::GetObjects()
{
    return Objects;
}

int Student::Objects = 0;