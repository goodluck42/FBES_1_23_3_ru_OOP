#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

template<typename T>
class Object
{
    template<typename T2> friend std::ostream& operator<<(std::ostream& aOs, const Object<T2>& aObject);
public:
    ~Object()
    {
        std::cout << "dtor" << '\n';
    }

    Object(int value)
    {
        this->~T();
        std::cout << "ctor" << '\n';
    }
    
    Object(const Object&)
    {
        std::cout << "copy" << '\n';
    }
    Object(Object&&) noexcept
    {
        std::cout << "move" << '\n';
    }
private:
    int mSize;
};


template<typename T> std::ostream& operator<<(std::ostream& aOs, const Object<T>& aObject)
{
    std::cout << aObject.mSize << '\n';

    return aOs;
}


int main(int argc, char* argv[])
{
    std::vector<Object<int>> arr;

    arr.emplace(arr.begin() + 1, 42);

    return 0;
}
