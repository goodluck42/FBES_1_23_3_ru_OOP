#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// private
// public
class Student
{
public:
    ~Student()
    {
        std::cout << "Destructor" << '\n';
        delete[] m_name;
    }
    
    Student()
    {
        std::cout << "Default constructor" << '\n';
    
        m_coins = 0;
        m_diamonds = 0;
        m_name = nullptr;
    }
    
    Student(int a_diamonds, int a_coins, const char* a_name)
    {
        std::cout << "Overloaded constructor" << '\n';
        
        m_diamonds = a_diamonds;
        m_coins = a_coins;
        m_name = new char[32];
    
        strcpy(m_name, a_name);
    }

    int GetDiamonds()
    {
        return m_diamonds;
    }

    void SetDiamonds(int a_diamonds)
    {
        if (a_diamonds >= 0 && a_diamonds < 1000)
        {
            m_diamonds = a_diamonds;
        }
    }

    int GetCoins()
    {
        return m_coins;
    }

    void SetCoins(int a_coins)
    {
        if (a_coins >= 0 && a_coins < 2000)
        {
            m_coins = a_coins;
        }
    }

    const char* GetName()
    {
        return m_name;
    }

    void SetName(const char* a_name)
    {
        delete[] m_name;

        int len = strlen(a_name) + 1;

        m_name = new char[len];

        strcpy(m_name, a_name);
    }
    static int StaticValue;
private:
    int m_diamonds;
    int m_coins;
    char* m_name;
};

int Student::StaticValue = 42;


int main(int argc, char* argv[])
{
    Student student1{100, 120, "Amin"};

    student1.SetCoins(10);
    student1.SetDiamonds(20);
    student1.SetName("Vagif");

    std::cout << Student::StaticValue << '\n';
    std::cout << student1.GetDiamonds() << '\n';
    std::cout << student1.GetCoins() << '\n';
    std::cout << student1.GetName() << '\n';
    
    // std::cout << student1.coins << '\n';
    // std::cout << student1.name << '\n';


    // {
    //     std::cout << "Before object created" << '\n';
    //     Student s1{100, 200, "Samir"};
    // }
    //
    // std::cout << "After object created" << '\n';
    
    return 0;
}
