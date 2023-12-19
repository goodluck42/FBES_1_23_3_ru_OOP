#include <iostream>
#include <string>


class Array
{
public:
    Array(const Array&) = delete;
    Array(Array&&) = delete;

    void operator=(const Array&) = delete;
    void operator=(Array&&) = delete;
};

class String
{
public:
    ~String()
    {
        std::cout << "destructor" << '\n';

        delete[] mData;
    }

    String()
    {
        std::cout << "default constructor" << '\n';
        mSize = 0;
        mData = new char[mSize + 1]{};
    }

    String(const char* aString)
    {
        std::cout << "cstr constructor" << '\n';
        mSize = (int)std::strlen(aString);
        mData = new char[mSize + 1]{};

        std::memcpy(mData, aString, mSize + 1);
    }

    String(const String& aOther)
    {
        std::cout << "copy constructor" << '\n';

        mSize = aOther.mSize;
        mData = new char[mSize + 1]{};

        std::memcpy(mData, aOther.mData, mSize + 1);
    }

    String(String&& aOther) noexcept
    {
        std::cout << "move constructor" << '\n';

        mData = aOther.mData;
        mSize = aOther.mSize;

        aOther.mData = nullptr;
        aOther.mSize = 0;
    }

    String& operator=(const String& aOther) // copy assignment operator
    {
        std::cout << "copy assignment operator" << '\n';

        if (this != &aOther) // self assignment check
        {
            this->~String();

            mSize = aOther.mSize;
            mData = new char[mSize + 1]{};
            std::memcpy(mData, aOther.mData, mSize + 1);
        }

        return *this;
    }

    String& operator=(String&& aOther) noexcept // move assignment operator
    {
        std::cout << "move assignment operator" << '\n';

        if (this != &aOther)
        {
            this->~String();

            mData = aOther.mData;
            mSize = aOther.mSize;

            aOther.mData = nullptr;
            aOther.mSize = 0;
        }

        return *this;
    }

    String& operator*=(int aTimes)
    {
        int totalSize = (mSize * aTimes);
        char* data = new char[totalSize + 1]{};

        for (int i = 0; i < totalSize; ++i)
        {
            data[i] = mData[i % mSize];
        }

        this->~String();

        mSize = totalSize;
        mData = data;

        return *this;
    }

    String operator*(int aTimes) const
    {
        int totalSize = (mSize * aTimes);
        char* data = new char[totalSize + 1]{};

        for (int i = 0; i < totalSize; ++i)
        {
            data[i] = mData[i % mSize];
        }

        return String{totalSize, data};
    }

    const char& operator[](int aIndex) const
    {
        return mData[aIndex];
    }

    char& operator[](int aIndex)
    {
        return mData[aIndex];
    }

    const char* GetData() const
    {
        return mData;
    }

    explicit operator int()
    {
        std::cout << "converted to int" << '\n';

        return std::atoi(mData);
    }

    operator const char*()
    {
        std::cout << "converted to const char*" << '\n';

        return mData;
    }

private:
    char* mData;
    int mSize;

    String(int aSize, char* aData) : mData(aData), mSize(aSize)
    {
        std::cout << "strange constructor" << '\n';
    }
};

void f(const String& s)
{
}

void f(String&& s)
{
    s *= 2;

    std::cout << s.GetData() << '\n';
}

class Number
{
public:
    Number(int aValue) : mValue(aValue)
    {
    }

    bool operator>(const Number& aOther)
    {
        return mValue > aOther.mValue;
    }

    bool operator<(const Number& aOther)
    {
        return mValue < aOther.mValue;
    }

    //auto operator<=>(const Number&) const = default;

    Number& operator++() // prefix increment
    {
        mValue += 1;

        return *this;
    }

    Number operator-()
    {
        Number copy{*this};

        copy.mValue *= -1;

        return copy;
    }

    Number operator-(const Number& aRhs)
    {
        Number copy{*this};

        copy.mValue -= aRhs.mValue;

        return copy;
    }

    Number& operator-=(const Number& aRhs)
    {
        mValue -= aRhs.mValue;

        return *this;
    }

    Number operator++(int) // postfix increment
    {
        Number copy{*this};

        mValue += 1;

        return copy;
    }

    int GetValue()
    {
        return mValue;
    }

private:
    int mValue;
};


String Foo()
{
    return "Hello from Foo";
}


class Test
{
public:
    void operator()(int)
    {
    }

    void operator+(int)
    {
    }

    void operator*(int)
    {
    }
};

class C
{
};

class B
{
public:
    C BMethod() { return C{}; }
};


class A
{
public:
    ~A() { std::cout << "~A()\n"; }
    A()
    {
        random = rand();
    }
    
    void Foo()
    {
        std::cout << this->random << '\n';
    }
private:
    int random;
};

int main(int argc, char* argv[])
{
    /*{
        Number num1 = 42;

        Number num2 = num1++;

        std::cout << num1.GetValue() << '\n';
        std::cout << num2.GetValue() << '\n';
        
    }*/

    // String s = "abc1000";
    //
    // s[0] = 'X';
    //
    // std::cout << s.GetData() << '\n';


    // Calling move constructor
    // std::cout << "Calling move constructor\n-----------" << '\n';
    // {
    //     String s1{"C#"};
    //     String s2{std::move(s1)};
    // }

    // Calling move assignment (=)

    // std::cout << "Calling move assignment (=)\n-----------" << '\n';
    // {
    //     String s1{"C#"};
    //     String s2{"C++"};
    //
    //     s2 = std::move(s1);
    // }

    // Calling copy assignment (=)
    
    // std::cout << "Calling copy assignment (=)\n-----------" << '\n';
    // {
    //     String s1{"C#"};
    //     String s2{"C++"};
    //
    //     s2 = s1;
    // }


    //f((String&&)s1);

    //std::cout << (void*)s1.GetData() << '\n';

    A obj;
    A obj2;


    A::Foo(&obj);
    A::Foo(&obj2);
    
    obj.Foo();
    obj2.Foo();
    
    // void(A::*MethodPtr)(int) = &A::Foo;
    //
    // MethodPtr(obj, 123);
    
    return 0;
}
