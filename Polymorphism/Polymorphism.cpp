#include <iostream>


class Vehicle // abstract class
{
public:
    virtual ~Vehicle()
    {
        std::cout << "~Vehicle()\n";
    }
    Vehicle() : MSpeed(), MColor(), MWeight()
    {
        std::cout << "Vehicle()" << '\n';
    }
    virtual void Move() = 0; // pure virtual function
    virtual void Accelerate()
    {
        MSpeed += 1;
    }
    // void Move()
    // {
    //     std::cout << "Vehicle::Move()\n";
    // }
    int GetSpeed()
    {
        return MSpeed;
    }
protected:
    int MSpeed;
    int MColor;
    int MWeight;
}; 

class Bicycle : public Vehicle
{
public:
    virtual ~Bicycle() override
    {
        std::cout << "~Bicycle()\n";
    }

    Bicycle()
    {
        std::cout << "Bicycle()\n";
    }
    virtual void Move() override
    {
        std::cout << "Bicycle::Move()\n";

        MSpeed += 10;
    }
};

class Car : public Vehicle
{
public:
    virtual ~Car() override
    {
        std::cout << "~Car()\n";
    }

    Car()
    {
        std::cout << "Car()\n";
    }
    virtual void Move() override
    {
        std::cout << "Car::Move()\n";

        MSpeed += 50;
    }
};

class Motorcycle : public Vehicle
{
public:
    virtual ~Motorcycle() override
    {
        std::cout << "~Motorcycle()\n";
    }
    Motorcycle()
    {
        std::cout << "Motorcycle()" << '\n';
    }
    virtual void Move() override
    {
        std::cout << "Motorcycle::Move()\n";

        MSpeed += 100;
    }

    virtual void Accelerate() override
    {
        MSpeed *= 2;
        
        Vehicle::Accelerate();
    }

    void UseNitro()
    {
        std::cout << "Using Nitro\n";
    }
};


class X
{
public:
    ~X()
    {
        std::cout << "~X()\n";
    }
    X()
    {
        std::cout << "X()\n";
    }

    virtual void Foo()
    {
        std::cout << "X::Foo()";
    }
};

class Y : public X
{
public:
    ~Y()
    {
        std::cout << "~Y()\n";
    }
    Y()
    {
        std::cout << "Y()\n";
    }
};


class Base
{
public:
    Base()
    {
        value = 42;
    }

    virtual void DoSomething()
    {
        std::cout << "Doing something...\n";
    }
    
private:
    int value;
};

class Derived : public Base
{
    public:
    Derived()
    {
        
    }

    // virtual void DoSomething() override
    // {
    //     std::cout << "Overriden\n";
    // }
};

int main(int argc, char* argv[])
{
    {
        Base* base = new Derived;

        base->DoSomething();
        
        std::cout << sizeof(Base);

        delete base;
    }
    
    Vehicle* motorcycle = new Motorcycle;
    
    motorcycle->Move();
    motorcycle->Accelerate();
    
    std::cout << motorcycle->GetSpeed() << '\n';
    
    delete motorcycle;

    /////////////////
    
    // const int size = 3;
    // Vehicle** vehicles = new Vehicle*[size];
    //
    // vehicles[0] = new Motorcycle;
    // vehicles[1] = new Car;
    // vehicles[2] = new Bicycle;
    //
    // for (int i = 0; i < size; ++i)
    // {
    //     vehicles[i]->Move();
    // }
    //
    // for (int i = 0; i < size; ++i)
    // {
    //     delete vehicles[i];
    // }
    //
    // delete[] vehicles;

    
    
    return 0;
}
