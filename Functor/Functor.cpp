#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <random>
#include <cmath>
#include <array>

class Random
{
public:
    Random(int aSeed)
    {
        mSeed = aSeed == 0 ? 1 : aSeed;
    }
    long long operator()(long long min, long long max)
    {
        auto currentTime = (long long)time(nullptr) / mSeed++;

        return currentTime % (max - min + 1) + min;
    }
private:
    int mSeed;
};

int main(int argc, char* argv[])
{
    /*
    time_t time = std::time(nullptr);
    tm* currentTime = localtime(&time);
    
    std::cout << currentTime->tm_yday;
    */
    
    /*{
        std::default_random_engine engine(time(nullptr));
        std::uniform_real_distribution<float> range(1.f, 10.f);

        std::cout << range(engine);
    }*/

    Random rand{42};
    
    int i = 0;
    while(i++ < 100)
    {
        std::cout << rand(1, 10) << '\n';
    }
        
    return 0;
}
