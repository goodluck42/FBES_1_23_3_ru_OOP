#include <iostream>
#include <initializer_list>

template <typename T>
class Array
{
public:
    class Iterator
    {
    public:
        Iterator(T* APtr) : MPtr(APtr)
        {
        }

        T& operator*()
        {
            return *MPtr;
        }

        Iterator& operator++()
        {
            MPtr += 1;

            return *this;
        }

        bool operator!=(const Iterator& AOther)
        {
            return AOther.MPtr != MPtr;
        }

    private:
        T* MPtr;
    };
    
    ~Array()
    {
        delete[] MArr;
    }

    Array(std::initializer_list<T> AList) : MSize(AList.size())
    {
        int i = 0;
        MArr = new T[MSize];

        for (auto& element : AList)
        {
            MArr[i++] = element;
        }
    }

    Iterator begin()
    {
        return Iterator{MArr};
    }

    Iterator end()
    {
        return Iterator{MArr + MSize};
    }

private:
    T* MArr;
    int MSize;
};

int main(int argc, char* argv[])
{
    Array<int> arr{10, 20, 30, 40, 42};

    for (auto& elem : arr)
    {
        std::cout << elem << '\t';
    }

    // {
    //     auto end = arr.end();
    //
    //     for (auto begin = arr.begin(); begin != end; ++begin)
    //     {
    //         std::cout << *begin << '\t';
    //     }
    // }
    

    // {
    //     auto begin = arr.begin();
    //     auto end = arr.end();
    //
    //     while (begin != end)
    //     {
    //         std::cout << *begin << '\t';
    //
    //         ++begin;
    //     }
    // }
    
    
    return 0;
}
