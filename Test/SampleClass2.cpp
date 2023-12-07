#include <iostream>
#include "SampleClass1.h"
#include "SampleClass2.h"

// Cannot be modified
SampleClass2::SampleClass2()
{
    std::cout << "In SampleClass2.cpp -> SampleClass2::SampleClass2(): " << TypeId<SampleClass2>::GetId() << '\n';
    std::cout << "In SampleClass1.cpp -> SampleClass1::SampleClass1(): " << TypeId<SampleClass2>::GetId() << '\n';
}
