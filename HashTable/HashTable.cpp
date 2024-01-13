#include <iostream>
#include <functional>

int main(int argc, char* argv[])
{
    std::hash<std::string> LHashFn;

    std::string LName1 = "John";
    std::string LName2 = "Samir";
    std::string LName3 = "Amin";

    int LBuckets = 12;
    
    std::cout << LHashFn(LName1) << '\n';
    std::cout << LHashFn(LName1) % LBuckets << '\n';
    std::cout << LHashFn(LName2) % LBuckets << '\n';
    std::cout << LHashFn(LName3) % LBuckets << '\n';


    
    
    return 0;
}
