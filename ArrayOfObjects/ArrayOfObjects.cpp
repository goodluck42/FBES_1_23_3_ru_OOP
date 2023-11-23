#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

class Object
{
public:
    Object()
    {
        value++;
    }

    int GetValue()
    {
        return value;
    }

private:
    static int value; // declaration
};

int Object::value = 0; // definition

class StudentHelper
{
public:
    static bool IsDiamondsValid(int value)
    {
        return value > 0 && value < 1000;
    }
};

class Student
{
private:
    static int Objects;
    int m_diamonds;
    int m_coins;
    char* m_name;
    int m_badges{};

public:
    ~Student()
    {
        std::cout << "Student::~Student()" << '\n';

        delete[] m_name;
    }

    Student()
    {
        std::cout << "Student::Student()" << '\n';

        m_coins = 0;
        m_diamonds = 0;
        m_name = nullptr;

        Objects++;
    }

    Student(int a_diamonds, int a_coins, const char* a_name)
    {
        std::cout << "Student::Student(int a_diamonds, int a_coins, const char* a_name)" << '\n';

        m_name = nullptr;

        SetDiamonds(a_diamonds);
        SetCoins(a_coins);
        SetName(a_name);

        Objects++;
    }

    Student(int a_diamonds, int a_coins, const char* a_name, int a_badges)
    {
        std::cout << "Student::Student(int a_diamonds, int a_coins, const char* a_name, int a_badges)" << '\n';

        this->m_diamonds = a_diamonds;
        this->m_coins = a_coins;
        this->m_name = new char[32];
        this->m_badges = a_badges;

        strcpy(m_name, a_name);

        Objects++;
    }

    int GetDiamonds()
    {
        return m_diamonds;
    }

    void SetDiamonds(int a_diamonds)
    {
        if (StudentHelper::IsDiamondsValid(a_diamonds))
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

    static int GetObjects()
    {
        return Objects;
    }
};

int Student::Objects = 0;


class User
{
private:
    int m_login;
    int m_password;

public:
    ~User()
    {
        std::cout << "~User()" << '\n';
    }

    User()
    {
        std::cout << "User()" << '\n';
        m_login = 0;
        m_password = 0;

        // a_login = 0;
    }

    User(int a_login, int a_password)
    {
        std::cout << "User(int a_login, int a_password)" << '\n';

        m_login = a_login;
        m_password = a_password;
    }

    int GetLogin()
    {
        return m_login;
    }

    int GetPassword()
    {
        return m_password;
    }

    void SetPassword(int a_password)
    {
        m_password = a_password;
    }
};


int main(int argc, char* argv[])
{
    // Object o1;
    // Object o2;
    // Object o3;
    //
    // std::cout << o1.GetValue() << '\n';
    // std::cout << o2.GetValue() << '\n';
    // std::cout << o3.GetValue() << '\n';

    // ?
    /*{
        Student student1{99, 199, "Amin"};
        Student student2{133, 249, "Vagif"};

        std::cout << "Object counter -> " << Student::GetObjects() << '\n';

        std::cout << student2.GetName() << '\n';
    }*/

    /*{
        User* user = new User{42, 1000};

        std::cout << user->GetLogin() << '\n';
        std::cout << user->GetPassword() << '\n';

        delete user;
    }*/

    // Array of objects №1
    {
        User* users = new User[3]{ {10, 20}, {30, 40}, {50, 60} };

        std::cout << users[1].GetLogin() << '\n';
        std::cout << users[1].GetPassword() << '\n';
        
        delete[] users;
    }
    // Array of objects №2
    /*{
        User* users = (User*)::operator new(sizeof(User) * 3);
        User* current_user = users;
        
        std::cout << current_user << '\n';
        // placement new
        new(current_user) User{42, 1000};

        current_user++;

        std::cout << current_user << '\n';
        
        new(current_user) User{13, 20};
        
        ::operator delete(users);
    }*/



  
    return 0;
}
