#include <iostream>
#include <vector>

template <typename T> // generic specialization
class Array
{
public:
    ~Array()
    {
        delete[] mData;
    }

    Array(int aCapacity = 15)
    {
        std::cout << "Array<T>" << '\n';
        mData = new T[aCapacity];
    }

    T* GetData()
    {
        return mData;
    }

    // ...
private:
    T* mData;
};

template <> // concrete specialization
class Array<char>
{
public:
    ~Array()
    {
        delete[] mData;
    }

    Array(int aCapacity = 31)
    {
        std::cout << "Array<char>" << '\n';
        mData = new char[aCapacity];
    }

    char* GetCharData()
    {
        return mData;
    }

private:
    char* mData;
};

template <typename T> // partial specialization
class Array<T*>
{
public:
    ~Array()
    {
        operator delete(mData);
    }

    Array(int aCapacity = 15)
    {
        std::cout << "Array<T*>" << '\n';
        mData = (T*)operator new(sizeof(T) * aCapacity);
    }

private:
    T* mData;
};

template <typename T, int SIZE>
class FixedArray
{
public:
    FixedArray()
    {
        std::cout << "Array<T, SIZE>" << '\n';
    }

private:
    T mData[SIZE];
};

class A
{
public:
    A()
    {
        std::cout << "A()" << '\n';
    }
};

template <int SIZE>
void PrintArray(int (&arr)[SIZE])
{
    for (int i = 0; i < SIZE; ++i)
    {
        std::cout << arr[i] << '\n';
    }
}

// Variadic template
template <typename... Args>
void Print(Args&&... args)
{
    ((std::cout << args << ' '), ...);
    std::cout << '\n';
}

template <typename... Args>
void print(Args&&... args)
{
    Print(args...);
}

template<typename... Args>
auto Sum(Args&&... args)
{    
    return (args + ...);
}

void Handle(int value)
{
    std::cout << "int arg" << '\n';
}

void Handle(float value)
{
    std::cout << "float arg" << '\n';
}


template <typename... Args>
void Foo(Args&&... args)
{
    (Handle(args), ...);
}

int main(int argc, char* argv[])
{
    // A* arr = (A*)malloc(sizeof(A) * 4);
    //
    // free(arr);

    // A* arr = new A[4];
    //
    // delete[] arr;

    // Array<char> arr;
    // Array<int> arr2;
    //
    // arr.GetCharData();
    // arr2.GetData();

    // FixedArray<int, 10> arr;
    // FixedArray<int, 20> arr1;
    // FixedArray<int, 30> arr2;

    // int arr[3]{10, 20, 30};
    //
    // print(arr);

    
    // int a = 42;
    // Print(1, 2, 3, "Hello C++", 2.f, 2.4, true, a);

    //std::cout << Sum(1, 2, 3, 4, 5);

    //Foo(1, 2.2f, 3.3f);

    print(1, 2, 3, 4, "hello!");
    
    return 0;
}
