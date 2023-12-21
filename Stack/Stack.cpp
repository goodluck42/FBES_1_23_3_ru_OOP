#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

class Object
{
public:
    ~Object()
    {
        std::cout << "dtor" << '\n';
    }

    Object(int value)
    {
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
};

int main(int argc, char* argv[])
{
    std::vector<Object> arr;

    arr.emplace(arr.begin() + 1, 42);

    return 0;
}
