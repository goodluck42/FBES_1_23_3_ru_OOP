#include <iostream>

template<typename K, typename V>
class HashMap
{
public:
    struct KeyValuePair
    {
        KeyValuePair(const K& AKey, const V& AValue) : Key(AKey), Value(AValue)
        {
            
        }
        K Key;
        V Value;
    };

    V& operator[](const K& AKey)
    {
        
    }
};

class User {};

int main(int argc, char* argv[])
{
    HashMap<std::string, User> LMap;

    LMap["user1"] = User{};

    
    std::cout << LMap["user1"];
    
    return 0;
}
