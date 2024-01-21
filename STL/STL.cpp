#include <complex>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <forward_list>
// 
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <array>

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

    bool operator>(const User& AOther)
    {
        return Login > AOther.Login;
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

template <typename... TArgs>
User* Create(TArgs&&... AArgs)
{
    return new User{AArgs...};
}

bool simple_predicate(const int& value)
{
    return value < 0;
}

void remove_all(std::list<int>& list, bool (*predicate)(const int&))
{
    bool deleted = false;

    for (auto& value : list)
    {
        if (predicate(value))
        {
            list.remove(value);

            deleted = true;
            break;
        }
    }

    if (deleted)
    {
        remove_all(list, predicate);
    }
}

int& g()
{
    static int v = 42;

    return v;
}

class Test
{
public:
    Test() {  }

    Test(const Test&) = delete;
    Test(Test&&) = delete;
    int value = 42;
};

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

    //{
    //std::vector<User> users;

    //users.assign({User{}, User{}, User{}});
    // users.assign(10, User{"login", "pass"});
    //
    // User& user = users.at(3);
    //
    // std::cout << user.Login << '\n';
    // std::cout << user.Password << '\n';

    //{
    // std::vector<int> vect {10, 20, 30};

    // for (auto& value : vect)
    // {
    //     std::cout << value << '\n';
    // }

    // for (auto begin = vect.rbegin(); begin != vect.rend(); ++begin)
    // {
    //     std::cout << *begin << '\n';
    // }

    //}

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
    // {
    //     std::vector<User> users;
    //     
    //     users.emplace_back("L1", "P1"); // 0
    //     users.emplace_back("L2", "P2"); // 2
    //     users.emplace_back("L3", "P3"); // 3
    //     
    //     users.emplace(users.begin() + 1, "FirstLogin", "FirstPass"); // emplace // 1
    //     
    //     // User u1{"FirstLogin", "FirstPass"}; // insert
    //     // users.insert(users.begin() + 1, u1);
    //
    //     users.erase(users.begin() + 2);
    //     
    //     for (auto& user : users)
    //     {
    //         std::cout << user.Login << '\n';
    //         std::cout << user.Password << '\n';
    //         std::cout << "--------------" << '\n';
    //     }
    // }
    //}

    // // list & forward_list
    // {
    //     // predicate
    //     std::list<int> list{10, 20, -10, -20, -30, 30};
    //     std::forward_list<int> flist{10, 20, -10, -20, -30, 30};
    //     
    //     // variant 1
    //      list.remove_if(simple_predicate);
    //     
    //      for (auto& value : list)
    //      {
    //          std::cout << value << '\n';
    //      }
    //
    //     // Variant 2
    //      remove_all(list, simple_predicate);
    //
    //     // Variant 3
    //
    //      list.remove_if([](auto& value)
    //      {
    //          return value > 0;
    //      });
    //     
    //      for (auto& value : list)
    //      {
    //          std::cout << value << '\n';
    //      }
    //     
    // }
    //
    // // Lambda expressions part1
    //  {
    //      auto sum = [](auto&& a, auto&& b) -> decltype(auto)
    //      {
    //          return a + b;
    //      };
    //
    //      int a = 42, b = 13;
    //      std::cout << sum(a, b) << '\n';
    //      std::cout << sum(10.2, 20.2) << '\n';
    //      std::cout << sum(std::string{"Hello "}, std::string{"world!"}) << '\n';
    //  }
    //
    // // Lambda expressions part2
    //  {
    //      int value = 42;
    //      int value2 = 10;
    //      
    //      auto foo = [&value, value2]()
    //      {
    //          value = 13;
    //          // value2 = 40; // readonly/const
    //      };
    //      
    //      foo();
    //      
    //      std::cout << value << '\n';
    //      std::cout << value2 << '\n';
    //  }
    //
    // // Lambda expressions part3
    //  {
    //      int a = 10,
    //          b = 20,
    //          c = 30;
    //
    //      auto lambda_capture_by_ref = [&]()
    //      {
    //          a = 11;
    //          b = 12;
    //          c = 13;
    //      };
    //
    //      Test obj{};
    //
    //      // SFINAE
    //      auto lambda_capture_by_copy = [=]()
    //      {
    //          std::cout << "a + b + c = " << a + b + c << '\n';
    //      };
    //
    //      lambda_capture_by_ref();
    //      
    //      std::cout << a << '\n';
    //      std::cout << b << '\n';
    //      std::cout << c << '\n';
    //
    //      lambda_capture_by_copy();
    //  }

    //// set, multiset, unordered_set, unordered_multiset
    
    // {
    //     std::unordered_set<int> set;
    //
    //     srand(time(nullptr));
    //
    //     for (int i = 0; i < 15; ++i)
    //     {
    //         set.emplace(rand());
    //     }
    //     
    //     set.emplace(42);
    //     set.emplace(42);
    //     set.emplace(30);
    //     set.emplace(20);
    //     set.emplace(10);
    //     set.emplace(20);
    //
    //     if (set.contains(20))
    //     {
    //         std::cout << "20 exists\n";
    //     }
    //     
    //     auto result = set.extract(20);
    //
    //     if (!result.empty())
    //     {
    //         std::cout << "extract value = " << result.value() << '\n';
    //     }
    //     
    //     std::cout << "count = " << set.count(20) << '\n';
    //
    //     int target = 20;
    //     
    //     if (set.contains(target))
    //     {
    //         auto it = set.find(target);
    //
    //         set.erase(it);
    //     }
    //     
    //     for (auto& value : set)
    //     {
    //         std::cout << value << '\n';
    //     }
    // }

    //// Set custom data type
    // {
    //     std::set<User, std::less<User>> users;
    //
    //     User user{"Log", "Pass"};
    //     
    //     users.insert(user);
    //     users.emplace("MyLogin", "MyPassword");
    // }


    //// pair, tuple, map, unordered_map, multimap, unordered_multimap
    {
        //// pair
        std::pair<std::string, long> pair;

        pair.first = "Value";
        pair.second = 42L;
        
        std::tuple tuple{std::string{"str"}, 10L, 20.2};

        const auto& first = std::get<0>(tuple);
        const auto& second = std::get<1>(tuple);
        

        // {
        //     std::map<int, std::string> values {};
        //
        //     values.insert({0, "John"});
        //     values.insert({1, "Jack"});
        //     values.insert({2, "Mahmud"});
        //     values.insert({3, "Ahmed"});
        //     values.insert({4, "Daniel"});
        //     values.insert({5, "Petya"});
        //
        //     for (auto& value : values)
        //     {
        //         std::cout << value.first << ": " << value.second << '\n';
        //     }
        //     std::cout << values[0] << '\n';
        // }


        //// map
        // std::map<std::string, int> values {};
        //
        // values.insert({"John", 18});
        // values.insert({"Jack", 41});
        // values.insert({"Mahmud", 44});
        // values.insert({"Ahmed", 18});
        // values.insert({"Daniel", 20});
        // values.emplace("Petya", 32);
        // values.insert({{"Amin", 18}, {"Fuad", 22}});
        //
        // values["Vagif"] = 99;
        // values["Vagif"] = 40;
        //
        // if (values.contains("Fuad"))
        // {
        //     //// Variant 1
        //
        //     auto it = values.find("Fuad");
        //
        //     std::cout << "found key: "<< it->first << '\n';
        //     std::cout << "found value: "<< it->second << '\n';
        //
        //     values.erase(it);
        //     //// Variant 2
        //     // auto result = values.extract("Fuad");
        //     //
        //     // if (!result.empty())
        //     // {
        //     //     std::cout << "key = " << result.key() << '\n';
        //     // }
        // }
        //
        // std::cout << values["Amin"] << '\n';
        // std::cout << values["Fuad"] << '\n';
        // std::cout << values["Vagif"] << '\n';

        //// multimap

        std::multimap<std::string, int> values;

        values.insert({"Test", 42});
        values.insert({"Test", 13});
        values.insert({"Test", 10});

        values.insert({"Data", 10});
        values.insert({"Data", 20});
        values.insert({"Data", 30});

        auto keyValues = values.equal_range("Test");

        auto begin = keyValues.first;
        auto end = keyValues.second;

        while(begin != end)
        {
            std::cout << begin->first << '\n';
            std::cout << begin->second << '\n';

            ++begin;
        }
        
        //std::cout << values["Data"];
    }

    printf("\n");
    system("pause");
    return 0;
}
