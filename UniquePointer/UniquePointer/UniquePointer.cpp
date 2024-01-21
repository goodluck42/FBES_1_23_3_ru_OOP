#include <iostream>

template<typename T>
class UniquePtr
{
public:
    ~UniquePtr()
    {
        //...
    }
    UniquePtr(T* AData) : MData(AData)
    {
        
    }

    UniquePtr(UniquePtr&& AOther)
    {
        // ...
    }

    void operator*()
    {
        // ...
    }

    void operator->()
    {
        // ...
    }
private:
    T* MData;
};

int main(int argc, char* argv[])
{
    UniquePtr<int[]> data{new int[32]};
    
    UniquePtr<int> data2{new int};
    
    return 0;
}
