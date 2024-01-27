#include <iostream>

class InvalidIndexException : public std::exception
{
public:
    InvalidIndexException(const std::string& AMessage) : MMessage(AMessage)
    {
        
    }

    virtual char const* what() const override
    {
        return MMessage.data();
    }
    
private:
    std::string MMessage;
};

class NegativeIndexException : public std::exception
{
public:
    NegativeIndexException(const std::string& AMessage) : MMessage(AMessage)
    {
        
    }

    virtual char const* what() const override
    {
        return MMessage.data();
    }
    
private:
    std::string MMessage;
};


class IntArray
{
public:
    ~IntArray()
    {
        delete[] arr;
    }
    IntArray()
    {
        count = 6;
        arr = new int[count] {10, 20, 30, 40, 42, 50};
    }

    int& operator[](int index) noexcept
    {
        return arr[index];
    }

    int get_size() noexcept
    {
        return count;
    }

    int& at(int index)
    {
        if (index < 0)
        {
            throw NegativeIndexException{"Negative index!"};
        }
        
        if (index >= count)
        {
            throw InvalidIndexException{"Invalid index!"};
        }

        return arr[index];
    }
    
private:
    int* arr;
    int count;
};

void user_input()
{
    IntArray arr;

    int index;

    std::cin >> index;

    try
    {
        std::cout << arr.at(index);
    }
    catch (...)
    {
        std::cout << "Caught" << '\n';
    }
    
    std::cout << "OK" << '\n';
}

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
};

int main(int argc, char* argv[])
{
    // 10, 20, 30, 40, 42, 50
    
    // try
    // {
    //     user_input();
    // }
    // catch (const InvalidIndexException& ex)
    // {
    //     std::cout << "InvalidIndexException: " << ex.what() << '\n';
    //
    //     throw ex;
    // }
    // catch (const NegativeIndexException& ex)
    // {
    //     std::cout << "NegativeIndexException: " << ex.what() << '\n';
    // }
    // catch(...)
    // {
    //     std::cout << "unknown exception";
    // }

    // static_cast
    // dynamic_cast
    // const_cast
    // reinterpret_cast
    
    // {
    //     int* a = new int{42};
    //     long long* b = static_cast<long long*>(a);
    // }

    // {
    //     int a = 42;
    //
    //     int& b = a;
    //
    //     float& x = static_cast<float&>(b);
    //     
    // }
    
    // {
    //     Object obj;
    //
    //     int a = static_cast<int>(obj);
    //
    //     std::cout << a << '\n';
    // }

    {
        int a = 42;

        float b = static_cast<float>(a);
    }
    
    
    return 0;
}
