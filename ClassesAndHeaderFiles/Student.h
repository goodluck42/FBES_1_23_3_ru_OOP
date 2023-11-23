#pragma once

class Student
{
private:
    static int Objects;
    int m_diamonds;
    int m_coins;
    char* m_name;
    int m_badges{};
public:
    ~Student();
    Student();
    Student(int a_diamonds, int a_coins, const char* a_name);
    Student(int a_diamonds, int a_coins, const char* a_name, int a_badges);

    int GetDiamonds();
    void SetDiamonds(int a_diamonds);
    int GetCoins();
    void SetCoins(int a_coins);
    const char* GetName();
    void SetName(const char* a_name);

    static int GetObjects();
};