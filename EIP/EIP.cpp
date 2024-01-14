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

class Foo
{
public:
    Foo()
    {
        PublicField = 10;
        ProtectedField = 20;
        PrivateField = 30;
    }
    int PublicField;
protected:
    int ProtectedField;
private:
    int PrivateField;
};

class Bar_Public : public Foo
{
public:
    Bar_Public()
    {
        this->ProtectedField; // protected
        this->PublicField; // public
    }
};

class Bar_Protected : protected Foo
{
public:
    Bar_Protected()
    {
        this->ProtectedField; // protected
        this->PublicField; // protected
    }
};

class Bar_SubProtected : public Bar_Protected
{
public:
    Bar_SubProtected()
    {
        this->ProtectedField;
        this->PublicField;
    }
};

class Bar_Private : private Foo
{
public:
    Bar_Private()
    {
        this->ProtectedField; // private
        this->PublicField; // private
    }
};

class Bar_SubPrivate : public Bar_Private
{
public:
    Bar_SubPrivate()
    {
        // this->ProtectedField; // error
        // this->PublicField; // error
    }
};


int main(int argc, char* argv[])
{
    // Motorcycle LMotorcycle{1, 255};
    //
    // LMotorcycle.Accelerate();
    // LMotorcycle.Accelerate();
    //
    // LMotorcycle.SetColor(123);
    //
    // LMotorcycle.UseNitro();
    //
    // LMotorcycle.Show();

    //
    {
        Bar_Public obj1;

        obj1.PublicField;


        Bar_Protected obj2;

        // obj2.PublicField; // protected
    }    
    return 0;
}

