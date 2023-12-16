#include <iostream>
#include <initializer_list>

class Object
{
public:
    Object(int aValue)
    {
    }
};

void Foo(const Object& aObj)
{
}

void Foo(Object& aObj)
{
}

void Foo(const std::string& aStr)
{
}


template <typename T>
class Array
{
public:
    Array() : mSize{}, mCapacity{}
    {
        std::cout << "default" << '\n';
    }

    Array(int aCapacity) : mSize{}, mCapacity(aCapacity)
    {
        std::cout << "aCapacity" << '\n';
    }

    Array(std::initializer_list<T> aList) : mSize(aList.size()), mCapacity(mSize)
    {
        std::cout << "initializer_list" << '\n';
    }

    Array(std::initializer_list<T> aList, std::initializer_list<T> aList2) : mSize(aList.size()), mCapacity(mSize)
    {
        std::cout << "absurd initializer_list" << '\n';
    }

    void Extend(std::initializer_list<T> aList)
    {
        // range based for
        for (auto& value : aList)
        {
            std::cout << value << '\n';
        }

        // for (auto begin = aList.begin(), end = aList.end(); begin != end; ++begin)
        // {
        //     std::cout << *begin << '\n';
        // }
    }

    void Extend(const Array& aArray)
    {
    }

    template<typename T2>
    void Method()
    {
        T value {};
        T2 value2 {};
    }
    
    int GetCapacity()
    {
        return mCapacity;
    }

private:
    T* mData;
    int mSize;
    int mCapacity;
};


int main(int argc, char* argv[])
{
    {
        Array<int> arr{}; // default constructor
        Array<int> arr2{15}; // initializer_list
        Array<int> arr3(15); // another constructor
        Array<int> arr4({1, 2, 3, 4, 5}, {6, 7, 8});
        
        // std::cout << arr.GetCapacity() << '\n';
        // std::cout << arr2.GetCapacity() << '\n';
        // std::cout << arr3.GetCapacity() << '\n';


        arr2.Extend({});

        arr2.Method<int>();
    }


    return 0;
}
