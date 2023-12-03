#include <iostream>
#include <string>

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
        std::cout << "constructor" << '\n';
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
        
    }
};

void f(const String& s)
{
}

class Number
{
public:
    Number(int aValue) : mValue(aValue) {  }
    
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

    String s = "123";

    int a = (int)s;
    
    std::cout << a << '\n';
    
    return 0;
}
