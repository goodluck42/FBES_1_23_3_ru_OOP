#pragma once
#include <cstdlib>

// CAN be modified
template<typename T>
class TypeId
{
public:
    // You must specify correct way to get proper ID for each class type!
    // You are ALLOWED to change this class as many much as you want!
    // Try not to creating new methods!~~~
    // Reward: 15 crystals
    // Happy new year!
    static long long GetId()
    {
        return rand();
    }
};