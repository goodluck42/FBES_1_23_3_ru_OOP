#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class User
{
    friend class UserFactory;
    friend std::ostream& operator<<(std::ostream& os, const User& user);
    friend std::istream& operator>>(std::istream& aIs, User& aUser);
public:
    const char* GetLogin() const
    {        
        return mLogin;
    }
    const char* GetPassword() const
    {
        return mPassword;
    }
private:
    User()
    {
        mLogin = new char[32];
        mPassword = new char[32];
    }

    User(const char* aLogin, const char* aPassword) : User()
    {
        std::strcpy(mLogin, aLogin);
        std::strcpy(mPassword, aPassword);
    }
    char* mLogin;
    char* mPassword;

    void operator+(const int& aRhs) // right hand side
    {
        this; // left hand side
    }
};


std::ostream& operator<<(std::ostream& aOs, const User& aUser) // 'os' - left hand side; 'user' - right hand side
{
    aOs << "Login = " << aUser.mLogin << '\n';
    aOs << "Password = " << aUser.mPassword << '\n';

    return aOs;
}

std::istream& operator>>(std::istream& aIs, User& aUser)
{
    aIs.getline(aUser.mLogin, 32);
    aIs.getline(aUser.mPassword, 32);

    return aIs;
}

void operator+(User& os, const char* aData)
{
    
}

void operator+(const char* aData, User& os)
{
    
}

class UserFactory
{
public:
    ~UserFactory()
    {
        User* current = (User*)mMemory;
        
        for (int i = 0; i < (int)mLength; current++)
        {
            current->~User();
        }

        operator delete(mMemory);
    }
    UserFactory()
    {
        mLength = 0;
        mMemory = mCurrent = operator new (1000 * 1000 * 2); // 2MB
    }
    User* Create()
    {
        new (mCurrent) User {}; // placement new

        void* object = mCurrent;
        char* anchor = (char*)mCurrent;
        
        anchor += sizeof(User);
        mCurrent = anchor;

        ++mLength;
        
        return (User*)object;
    }

    User* Create(const char* aLogin, const char* aPassword)
    {
        new (mCurrent) User {aLogin, aPassword}; // placement new

        void* object = mCurrent;
        char* anchor = (char*)mCurrent;
        
        anchor += sizeof(User);
        mCurrent = anchor;

        ++mLength;
        
        return (User*)object;
    }

    void Destroy(User* user)
    {
        user->~User();

        --mLength;
    }
private:
    void* mMemory;
    void* mCurrent;
    uint64_t mLength;
};

class Builder
{
public:
    Builder& DoSomeAction()
    {
        std::cout << mCounter++ << '\n';

        return *this;
    }
private:
    int mCounter = 0;
};

int main(int argc, char* argv[])
{
    UserFactory factory;
    
    User* user = factory.Create("MyLogin", "MyPassword");

    std::cin >> *user;
    std::cout << *user;
    
        
    /*{
        Builder builder;

        builder.DoSomeAction().DoSomeAction().DoSomeAction().DoSomeAction();
    }*/
    
    // std::cout << user->GetLogin() << '\n';
    // std::cout << user->GetPassword() << '\n';


    factory.Destroy(user);
    
    return 0;
}
