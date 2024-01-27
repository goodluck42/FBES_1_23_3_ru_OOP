#include <fstream>
#include <iostream>
#include <vector>
#include <memory> // smart pointers

class Object
{
public:
    Object()
    {
        Value = 42;
    }

    int Value;

    explicit operator int() const noexcept
    {
        std::cout << "static_cast used!\n";

        return Value;
    }

    void DoSomething()
    {
        std::cout << "Doing something" << '\n';
    }

    void DoSomething() const
    {
        // variant 1
        // {
        //     auto that = const_cast<Object*>(this);
        //     that->DoSomething();
        //     std::cout << "But constant" << '\n';
        // }
        // variant 2

        // {
        //     auto& that = const_cast<Object&>(*this);
        //     that.DoSomething();
        //     std::cout << "But constant" << '\n';
        // }

        // variant 3

        {
            const_cast<Object*>(this)->DoSomething();
            std::cout << "But constant" << '\n';
        }
    }
};

void foo(const std::string& str)
{
    auto& ref = const_cast<std::string&>(str);

    ref = "Goodbye";
}

class User
{
public:
    std::string Login;
    std::string Password;
};

class Logger
{
public:
    ~Logger()
    {
        std::cout << "~Logger()" << '\n';
    }
    void Info(const std::string& info)
    {
        std::cout << info << '\n';
    }
};

class UserSerializer
{
private:
    Logger MLogger;
public:
    ~UserSerializer()
    {
        std::cout << "~UserSerializer()" << '\n';
    }
    UserSerializer()
    {
        
    }
    std::shared_ptr<char[]> Serialize(const User& user, size_t& aTotalSize)
    {
        size_t loginSize = user.Login.size();
        size_t passwordSize = user.Password.size();
        size_t totalSize = aTotalSize = loginSize + passwordSize + sizeof(size_t) * 2;
        
        char* begin;
        char* buffer = begin = new char[totalSize];
#if _DEBUG
        MLogger.Info("Memory allocated!");
#endif
        
        std::memcpy(buffer, &loginSize, sizeof(size_t));

        buffer += sizeof(size_t);

        MLogger.Info("Size written");
        
        std::memcpy(buffer, user.Login.data(), loginSize);

        buffer += loginSize;

        std::memcpy(buffer, &passwordSize, sizeof(size_t));

        buffer += sizeof(size_t);

        std::memcpy(buffer, user.Password.data(), passwordSize);

        return std::shared_ptr<char[]>{begin};
    }

    User Deserialize(char* data)
    {
        return User{};
    }
};

class Animal
{
public:
    virtual ~Animal() = default;
    virtual void Voice() = 0;
};

class Hamster : public Animal
{
public:
    virtual void Voice() override
    {
        std::cout << "kxkxkx" << '\n';
    }

    void Spin()
    {
        std::cout << "Hamster is spinning" << '\n';
    }
};

class Dog : public Animal
{
public:
    virtual void Voice() override
    {
        std::cout << "bark-bark" << '\n';
    }

    void Sniff()
    {
        std::cout << "this = " << this << '\n';
        std::cout << "Dog is sniffing" << '\n';
    }
};

class Cat : public Animal
{
public:
    virtual void Voice() override
    {
        std::cout << "meow-meow" << '\n';
    }

    void Chew()
    {
        std::cout << "Cat is chewing crocks" << '\n';
    }
};

class Monkey
{
public:
    virtual void Voice()
    {
        std::cout << "ya-ya-ya" << '\n';
    }
};

class Human : public Monkey
{
public:
    virtual void Voice() override
    {
        std::cout << "Salam" << '\n';
    }
};

class Programmer : public Monkey
{
public:
    virtual void Voice() override
    {
        std::cout << "Writing code in Python" << '\n';
    }
};

namespace MSSQL
{
    void connect()
    {
        std::cout << "MSSQL::connect()" << '\n';
    } // MSSQL
}

namespace MongoDb
{
    void connect()
    {
        std::cout << "MongoDb::connect()" << '\n';
    } // MSSQL
}

namespace MongoDb
{
    void disconnect()
    {
        std::cout << "MongoDb::disconnect()" << '\n';
    }
}




int main(int argc, char* argv[])
{
    // static_cast №1
    // {
    //     int* a = static_cast<int*>(operator new(sizeof(int)));
    //
    //     // long long* b = static_cast<long long*>(a); // error 
    //     long long* b = (long long*)(a); // ok
    //
    //     *b = 490000000000000LL;
    //
    //     operator delete(a);
    // }

    // static_cast №2

    // {
    //     int a = 4213; // 4
    //
    //     // long long& b = static_cast<long long&>(a); // error
    //     long long& b = (long long&)(a); // error
    //
    //     b = 490000000000000LL;
    // }

    // static_cast №3
    // {
    //     Object obj;
    //
    //     int b = static_cast<int>(obj);
    //
    //     std::cout << b << '\n';
    // }

    // const_cast №1
    // {
    //     Object obj;
    //     
    //     obj.DoSomething();
    // }

    // const_cast №2
    // {
    //     const int value = 42;
    //
    //     int* value_without_const = const_cast<int*>(&value);
    //
    //     *value_without_const = 13;
    //
    //     std::cout << value;
    // }

    // const_cast №3
    // {
    //     std::string myStr = "Hello";
    //
    //     foo(myStr);
    //
    //     std::cout << myStr;
    // }

    // reinterpret_cast №1

    // {
    //     std::fstream file{"data.bin", std::ios::in | std::ios::out | std::ios::binary};
    //
    //     if (file.is_open())
    //     {
    //         std::string s = "data";
    //         std::vector<int> v{10, 20, 30, 42};
    //
    //         file.write(s.data(), static_cast<std::streamsize>(s.size()));
    //         file.write(reinterpret_cast<char*>(v.data()), static_cast<std::streamsize>(v.size() * sizeof(int)));
    //
    //         file.close();
    //     }
    // }

    //Logger logger;
    // serialization
    {
        User u {"MyLogin", "MyPassword"};
    
        UserSerializer serializer{};
    
        std::fstream file{"user.bin", std::ios::out | std::ios::binary};
    
        if (file.is_open())
        {
            size_t totalSize;
            std::shared_ptr<char[]> data = serializer.Serialize(u, totalSize);
            
            file.write(data.get(), static_cast<std::streamsize>(totalSize));
            
            file.close();
        }
    }
    std::cout << "---------end\n";


    // {
    //     Animal** animals = new Animal*[3];
    //
    //     {
    //         animals[0] = new Hamster;
    //         animals[1] = new Cat;
    //         animals[2] = new Dog;
    //     }
    //
    //     auto x = animals[0];
    //
    //     Hamster* hamster = dynamic_cast<Hamster*>(animals[0]);
    //
    //     if (hamster != nullptr)
    //     {
    //         std::cout << "This is Hamster!" << '\n';
    //         hamster->Voice();
    //         hamster->Spin();
    //     }
    //     else
    //     {
    //         std::cout << "This is not Hamster!" << '\n';
    //     }
    //
    //
    //     Dog* dog = dynamic_cast<Dog*>(animals[0]);
    //
    //     dog->Sniff();
    //     //dog->Voice();
    //
    //     // downcast
    //     {
    //         
    //     }
    //
    //     // release memory
    //     {
    //         delete animals[0];
    //         delete animals[1];
    //         delete animals[2];
    //
    //         delete[] animals;
    //     }
    // }

    // {
    //     Programmer programmer;
    //
    //     try
    //     {
    //         Human& human = dynamic_cast<Human&>(programmer);
    //
    //         human.Voice();
    //     }
    //     catch (std::bad_cast& ex)
    //     {
    //         std::cout << ex.what() << '\n';
    //     }
    // }


    // const_cast
    // static_cast
    // reinterpret_cast
    // dynamic_cast

    return 0;
}
