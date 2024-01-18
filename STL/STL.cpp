#include <complex>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>

class User
{
public:
    User(const std::string& ALogin, const std::string& APassword) :
        Login(ALogin),
        Password(APassword)
    {
        std::cout << "constructor\n";
    }

    User()
    {
        std::cout << "default\n";
    }
    User(const User& AOther)
    {
        std::cout << "copied\n";
        
        Login = AOther.Login;
        Password = AOther.Password;
    }
    User(User&& AOther)
    {
        std::cout << "moved\n";
        
        Login = std::move(AOther.Login);
        Password = std::move(AOther.Password);
    }

    void Foo() const
    {
        
    }
    void Foo()
    {
        
    }
    
    User& operator=(const User& AOther)
    {
        std::cout << "operator=(const User& AOther)\n";
        
        Login = AOther.Login;
        Password = AOther.Password;

        return *this;
    }

    User& operator=(User&& AOther)
    {
        std::cout << "operator=(const User& AOther)\n";
        
        Login = std::move(AOther.Login);
        Password = std::move(AOther.Password);

        return *this;
    }

    std::string Login;
    std::string Password;
};
// void append()
// {
//     mdata[size] = user;
//     size++;
// }
// STL - Standard Template Library

template<typename... TArgs>
User* Create(TArgs&&... AArgs)
{
    return new User{AArgs...};
}

int main(int argc, char* argv[])
{
    //// Stack 
    // {
    //     std::stack<User> stack{};
    //     
    //     User u1{"MyLogin", "MyPassword"};
    //
    //     stack.push(u1);
    //     
    //     User& myUser = stack.top();
    //
    //     //myUser.Login = "Test";
    //
    //     // std::cout << u1.Login << '\n';
    //     // std::cout << myUser.Login << '\n';
    //
    //     std::cout << "-----------\n";
    // }

    //// Args
    // {
    //
    //     User* u = Create("MyLogin", "MyPassword");
    //
    //     std::cout << u->Login << '\n';
    //     std::cout << u->Password << '\n';
    //
    //     delete u;        
    // }
    
    // {
    //     std::stack<User> users;
    //     
    //     users.emplace("MyLogin", "MyPassword");
    //
    //     User& myUser = users.top();
    //
    //     std::cout << myUser.Login << '\n';
    //     std::cout << myUser.Password << '\n';
    // }

    // Queue

    // {
    //     std::queue<User> users;
    // }

    // Vector

    {
        std::vector<User> users;
        
        //users.assign({User{}, User{}, User{}});
        // users.assign(10, User{"login", "pass"});
        //
        // User& user = users.at(3);
        //
        // std::cout << user.Login << '\n';
        // std::cout << user.Password << '\n';

        {
            std::vector<int> vect {10, 20, 30};
        
            // for (auto& value : vect)
            // {
            //     std::cout << value << '\n';
            // }

            // for (auto begin = vect.rbegin(); begin != vect.rend(); ++begin)
            // {
            //     std::cout << *begin << '\n';
            // }
            
        }

        // {
        //     std::vector<int> vect {10, 20, 30};
        //     //
        //     // for (auto& value : vect)
        //     // {
        //     //     value *= 2;
        //     // }
        //
        //     
        //     int* arr = vect.data();
        //     
        //     for (int i = 0; i < vect.size(); ++i)
        //     {
        //         std::cout << arr[i] << '\n';
        //     }
        // }

        // emplace vs insert
        {
            std::vector<User> users;
            
            users.emplace_back("L1", "P1"); // 0
            users.emplace_back("L2", "P2"); // 2
            users.emplace_back("L3", "P3"); // 3
            
            users.emplace(users.begin() + 1, "FirstLogin", "FirstPass"); // emplace // 1
            
            // User u1{"FirstLogin", "FirstPass"}; // insert
            // users.insert(users.begin() + 1, u1);

            users.erase(users.begin() + 2);
            
            for (auto& user : users)
            {
                std::cout << user.Login << '\n';
                std::cout << user.Password << '\n';
                std::cout << "--------------" << '\n';
            }
        }
    }
    
    return 0;
}
