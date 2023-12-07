#pragma once
#include "TypeId.h"

// Cannot be modified
class SampleClass1 : public TypeId<SampleClass1>
{
public:
    SampleClass1();
};
