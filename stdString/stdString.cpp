#include <iostream>
#include <string>

class Less;
class Greater;

class Array
{
public:
    Array(int aSize) : mSize(aSize), mArr(nullptr)
    {
        
    }
    void Sort(Less less);
    void Sort(Greater greater);
private:
    int mSize;
    int* mArr;
};

int main(int argc, char* argv[])
{    
    // {
    //     std::string s = "Hello C++ strings";
    //
    //     s = "C++";
    //
    //     std::cout << s;
    // }

    // append 1
    // {
    //     std::string s = "C# ";
    //
    //     s.append("vs C++");
    //
    //     std::cout << s;
    // }

    // append 2
    // {
    //     std::string s = "C# ";
    //     std::string s2 = "vs C++";
    //
    //     // s.append(s2);
    //             
    //     s += s2;
    //     
    //     std::cout << s;
    // }

    // insert
    // {
    //     std::string s = "C vs C++";
    //     
    //     s.insert(1, "#");
    //     
    //     std::cout << s;
    // }

    // erase
    // {
    //     std::string s = "C++17";
    //     
    //     s.erase(3, 2);
    //
    //     std::cout << s << '\n';
    //
    //     s += "23";
    //
    //     std::cout << s << '\n';
    // }


    // at & capacity
    // {
    //     std::string s = "JavaScript";
    //
    //     std::cout << s.capacity() << '\n';
    //     
    //     //std::cout << (int)s[14] << '\n';
    //     try
    //     {
    //         std::cout << (int)s[14] << '\n'; // Do not throws exception
    //         //std::cout << s.at(14) << '\n'; // Throws
    //     }
    //     catch (std::out_of_range& ex)
    //     {
    //         std::cout << "out_of_range" << '\n';
    //     }
    // }


    // reserve & shrink_to_fit
    // {
    //     std::string s = "C++";
    //             
    //     std::cout << "before reserve capacity = " << s.capacity() << "\n";
    //
    //     s.reserve(1000);
    //     
    //     for (int i = 0; i < 500; ++i)
    //     {
    //         s += '@';
    //     }
    //     
    //     std::cout << "after reserve capacity = " << s.capacity() << "\n";
    //
    //     s.shrink_to_fit();
    //     
    //     std::cout << "after shrink_to_fit capacity = " << s.capacity() << "\n";
    // }

    // find & rfind
    // {
    //     std::string s = "Hello world world.";
    //
    //     std::cout << s.find("world") << '\n';
    //     std::cout << s.rfind("world") << '\n';
    // }

    /*{
        std::string s1 = "C++";
        //std::string s2 = "C++";

        //if (s1 == "C++")
        //if (s1 == s2)
        //if ("C++" == s1)
        if (s1 > "A++")
        {
            std::cout << "Equals" << '\n';
        }
        else
        {
            std::cout << "Not Equals" << '\n';
        }
    }*/

    {
        std::string s = "Hello world!";

        const char* data = s.data();
        const char* data2 = s.c_str();
        std::cout << data;
    }

    
    
    return 0;
}
