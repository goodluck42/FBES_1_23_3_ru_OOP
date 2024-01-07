#include <iostream>
#include <queue>

template <typename T, typename TFunctor>
class Queue
{
public:
    void Enqueue(const T& AElement) // adds an element
    {
        
    }

    void Enqueue(T&& AElement)
    {
        
    }

    T Dequeue(const T& AElement) // removes first element
    {
        
    }

    T& Front()
    {
        
    }

    T& Back()
    {
        
    }
    
    void Sort()
    {
        // ...
        if (AFunctor(obj1, obj2))
        {
            // swap
        }
        // ...
    }
};

class Foo
{
public:
    ~Foo()
    {
        delete[] MData;
    }

    void operator()()
    {
    }

    Foo()
    {
        this->MData = new int[32];
    }

private:
    int* MData;
    int a;
    int b;
    int c;
};


Foo& f()
{
    Foo* f2 = new Foo;

    return *f2;
}


template <typename T>
void f(T&& arg)
{
}

int foo()
{
    return 42;
}

int& foo2()
{
    int* value = new int{42};

    return *value;
}

class User
{
public:
    ~User()
    {
        std::cout << "dtor\n";
    }
    User()
    {
        std::cout << "default\n";
    }

    User(const std::string& ALogin, const std::string& APassword) :
        Login(ALogin),
        Password(APassword)
    {
        std::cout << "constructor\n";
    }

    User(const User& AOther)
    {
        std::cout << "copy\n";

        Login = AOther.Login;
        Password = AOther.Password;
    }

    User(User&& AOther) noexcept
    {
        std::cout << "move\n";

        Login = std::move(AOther.Login);
        Password = std::move(AOther.Password);
    }

    std::string Login;
    std::string Password;
};

int main(int argc, char* argv[])
{
    // Stack - LIFO
    // Queue - FIFO
    int LCapacity = 32;
    int LSize = 0;

    User* LUsers = (User*)operator new(sizeof(User) * LCapacity); // memory allocation

    new(LUsers) User{"MyLogin", "MyPassword"}; // placement new
    LSize++;
    new(LUsers + 1) User{"MyLogin2", "MYPass2"}; // placement new
    LSize++;

    for (int i = 0; i < LSize; ++i)
    {
        std::cout << LUsers[i].Login << '\n';
        std::cout << LUsers[i].Password << '\n';
    }
    
    for (int i = 0; i < LSize; ++i)
    {
        LUsers[i].~User();
    }
    
    operator delete(LUsers);
    
    return 0;
}
