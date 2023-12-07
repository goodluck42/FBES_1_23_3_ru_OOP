#include <iostream>
#include "TypeId.h"
#include "SampleClass1.h"
#include "SampleClass2.h"


// The rules are simple:
// No extern
// No global variables
// No modifying the classes in project list
// No creating additional classes

int main(int argc, char* argv[])
{
    // You are not allowed to modify this code! 
    std::cout << "In main.cpp -> SampleClass1::SampleClass1(): " << TypeId<SampleClass1>::GetId() << '\n';
    std::cout << "In main.cpp -> SampleClass2::SampleClass2(): " << TypeId<SampleClass2>::GetId() << '\n';

    SampleClass1 object1{};
    SampleClass2 object2{};
    
    return 0;
}
