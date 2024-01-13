#include <iostream>

class Vehicle // Parent class, base class
{
public:
    Vehicle() : MSpeed(), MColor()
    {
        std::cout << "Vehicle()" << '\n';
    }
    Vehicle(int ASpeed, int AColor) : MSpeed(ASpeed), MColor(AColor)
    {
    }
    void SetColor(int AColor)
    {
        if (AColor >= 0 && AColor <= 65535)
        {
            MColor = AColor;
        }
    }

    int GetColor()
    {
        return MColor;
    }

    void Accelerate()
    {
        MSpeed++;
    }
protected:
    int MSpeed;
private:
    int MColor;
};

class Motorcycle final : public Vehicle // derived class, child class
{
public:
    Motorcycle() : Vehicle(0, 0), MFuel()
    {
        std::cout << "Motorcycle()" << '\n';
    }

    Motorcycle(int ASpeed, int AColor = 0) : Vehicle(ASpeed, AColor), MFuel()
    {
    }
    
    void SetFuel(float AFuel)
    {
        if (AFuel > 0)
        {
            MFuel = AFuel;
        }
    }
    float GetFuel()
    {
        return MFuel;
    }

    void UseNitro()
    {
        MSpeed *= 2;
    }
    void Show()
    {
        std::cout << "Color = " << GetColor() << '\n'; 
        std::cout << "Speed = " << MSpeed << '\n'; 
        std::cout << "Fuel = " << MFuel << '\n'; 
    }
private:
    float MFuel;
};

class Bicycle
{

};

// class A {};
//
// class B : public A {};
//
// class C final : public B {};
//
// class D : public C {};

int main(int argc, char* argv[])
{
    Motorcycle LMotorcycle{1, 255};

    LMotorcycle.Accelerate();
    LMotorcycle.Accelerate();

    LMotorcycle.SetColor(123);

    LMotorcycle.UseNitro();
    
    LMotorcycle.Show();
    
    return 0;
}

