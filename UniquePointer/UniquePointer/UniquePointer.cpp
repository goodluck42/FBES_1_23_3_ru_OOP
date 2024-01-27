#include <iostream>
#include <memory>


class User
{
public:
    std::string Login;
    std::string Password;
};

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

    UniquePtr(const UniquePtr&) = delete;
    
    UniquePtr(UniquePtr&& AOther)
    {
        // ...
    }

    T& operator*()
    {
        return *MData;
    }

    const T& operator*() const
    {
        return *MData;
    }

    T* operator->()
    {
        return MData;
    }
private:
    T* MData;
};

void foo(UniquePtr<int> APtr)
{}

int main(int argc, char* argv[])
{
    // UniquePtr<int[]> data{new int[32]};
    // UniquePtr<int> data2{new int{1337}};
    //
    // foo(data2);
    //
    // data[0] = 90;
    // data[1] = 91;
    //
    // std::cout << *data2 << '\n'; // shows 1337
    //
    // UniquePtr<User> userPtr{new User};
    //
    // std::cout << (*userPtr).Login << '\n'; // shows login
    // std::cout << userPtr->Login << '\n'; // shows login
    // std::cout << userPtr->Password << '\n'; // shows password

    std::shared_ptr<int> obj {new int};

    std::cout << obj.use_count() << '\n'; // 1
    
    {
        std::shared_ptr<int> obj2 {obj};
        std::cout << obj.use_count() << '\n'; // 2
        std::cout << obj2.use_count() << '\n'; // 2
    }
    
    std::cout << obj.use_count() << '\n'; // 1
    
    return 0;
}
