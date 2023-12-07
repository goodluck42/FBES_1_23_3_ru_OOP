#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class User
{
    friend class UserFactory;
public:
    const char* GetLogin();
    const char* GetPassword();
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
};

class UserFactory
{
public:
    UserFactory()
    {
        mMemory = mCurrent = operator new (1000 * 1000 * 2); // 2MB
    }
    User* Create()
    {
        new (mCurrent) User {}; // placement new

        void* object = mCurrent;
        char* anchor = (char*)mCurrent;
        
        anchor += sizeof(User);
        mCurrent = anchor;

        return (User*)object;
    }

    void Destroy(User* user)
    {
        user->~User();
    }
private:
    void* mMemory;
    void* mCurrent;
};

class Int32
{
public:
    Int32()
    {
        std::cout << "Int32::Int32" << '\n'; 
    }
};

class Float
{
public:
    Float()
    {
        std::cout << "Float::Float" << '\n'; 
    }
};

class Object : public Float<Object>
{
    
};

int main(int argc, char* argv[])
{
    

    
    return 0;
}
