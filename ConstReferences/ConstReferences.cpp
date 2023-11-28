#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class User
{
public:
    ~User()
    {
        std::cout << "User::~User()" << '\n';
        delete[] m_login;
        delete[] m_password;
    }

    User(const char* aLogin, const char* aPassword)
    {
        SetLogin(aLogin);
        SetPassword(aPassword);
    }

    User(const User& aOther)
    {
        auto loginLen = strlen(aOther.m_login);
        auto passwordLen = strlen(aOther.m_password);

        m_login = new char[loginLen + 1] {};
        m_password = new char[passwordLen + 1] {};
        
        // variant 1

        for (int i = 0; i < loginLen; ++i)
        {
            m_login[i] = aOther.m_login[i];
        }

        // variant 2

        std::memcpy(this->m_password, aOther.m_password, passwordLen * sizeof(char));
    }

    User()
    {
        m_login = nullptr;
        m_password = nullptr;
    }

    const char* GetLogin() const
    {
        return m_login;
    }

    void SetLogin(const char* a_login)
    {
        delete[] m_login;

        auto len = strlen(a_login);

        m_login = new char[len + 1] {};
        
        strcpy(m_login, a_login);
    }

    void SetPassword(const char* a_password)
    {
        auto self = this;

        delete[] m_password;

        auto len = strlen(a_password);

        m_password = new char[len + 1] {};

        strcpy(m_password, a_password);
    }

    const char* GetPassword() const
    {
        return m_password;
    }
private:
    char* m_login;
    char* m_password;
};


class UserDb
{
public:
    ~UserDb()
    {
        for (int i = 0; i < mSize; ++i)
        {
            delete mUsers[i];
        }

        delete[] mUsers;
    }
    UserDb()
    {
        mSize = 0;
        mUsers = new User*[mSize];
    }
    void AddUser(User* aUser)
    {
        User** users = new User*[mSize + 1]{};

        for (int i = 0; i < mSize; ++i)
        {
            users[i] = mUsers[i]; // User* u1 = u2;
        }

        delete[] mUsers;

        mUsers = users;

        mUsers[mSize++] = aUser;
    }

    // 0 1 2 X 4 5
    void RemoveUser(const char* aLogin)
    {
        for (int i = 0; i < mSize; ++i)
        {
            if (std::strcmp(mUsers[i]->GetLogin(), aLogin) == 0)
            {
                delete mUsers[i];

                mUsers[i] = nullptr;
                // TODO: shift mUsers array
            }
        }
    }

    User* GetUser(const char* aLogin)
    {
        for (int i = 0; i < mSize; ++i)
        {
            auto currentLogin = mUsers[i]->GetLogin();
            
            if (std::strcmp(currentLogin, aLogin) == 0)
            {
                return mUsers[i];
            }
        }

        return nullptr;
    }
private:
    User** mUsers;
    int mSize;
};



void f(int); // 1 - ValueType
void f(int&); // 2 - ReferenceType
void f(int*); // 1 - ValueType


// Тимур - 1
// Вагиф - 2
// Айхан - 1
// Фарид - 1
// Амин - 1
// Xanbaba - 1
// Ayan - 1
// Nurlan - 2
// Samir - 2
// Rasul - 1
// Tarik - 1
// Ali - 2
// Ramil - 2

int main(int argc, char* argv[])
{
    UserDb db;

    db.AddUser(new User("my_login", "my_password"));
    db.AddUser(new User("my_login2", "my_password2"));
    db.AddUser(new User("my_login3", "my_password3"));

    User* u = db.GetUser("my_login2");

    if (u != nullptr)
    {
        std::cout << u->GetLogin() << '\n';
        std::cout << u->GetPassword() << '\n';
    }
    
    return 0;
}
