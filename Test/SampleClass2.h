#pragma once
#include "TypeId.h"

// Cannot be modified
class SampleClass2 : public TypeId<SampleClass2>
{
public:
    SampleClass2();
};
