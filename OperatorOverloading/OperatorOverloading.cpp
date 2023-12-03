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

    String operator*(int aTimes)
    {
        int totalSize = (mSize * aTimes);
        char* data = new char[totalSize + 1]{};

        for (int i = 0; i < totalSize; ++i)
        {
            data[i] = mData[i % mSize];
        }

        return String{totalSize, data};
    }

    const char* GetData()
    {
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

int main(int argc, char* argv[])
{
    String s = "abc1000";
    s *= 2;


    int& ref;

    ref = 42;
    
    std::cout << s.GetData() << '\n';
    
    return 0;
}
