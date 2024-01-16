#include <iostream>
#include <initializer_list>

template<typename T>
class ArrayIterator
{
public:
    ArrayIterator(T* AArr) : MArr(AArr)
    {
        MIndex = 0;
    }

    T& operator*()
    {
        return MArr[MIndex];
    }

    ArrayIterator& operator++()
    {
        MIndex += 1;

        return *this;
    }

    bool operator!=(const ArrayIterator& AOther)
    {
        if (AOther.MArr != MArr)
        {
            return false;
        }

        return AOther.MIndex != MIndex;
    }
    
private:
    T* MArr;
    int MIndex;
};

template <typename T>
class Array
{
public:
    ~Array()
    {
        delete[] MArr;
    }
    Array(std::initializer_list<T> AList)
    {
        int i = 0;
        MArr = new T[AList.size()];
        
        for (auto& element : AList)
        {
            MArr[i++] = element;
        }
    }

    ArrayIterator<T> begin()
    {
        return ArrayIterator<T>{MArr};
    }

    ArrayIterator<T> end()
    {
        return ArrayIterator<T>{MArr};
    }
private:
    T* MArr;
};

int main(int argc, char* argv[])
{
    Array<int> arr{10, 20, 30, 40, 42};

    for (auto& elem : arr)
    {
        
    }

    return 0;
}


