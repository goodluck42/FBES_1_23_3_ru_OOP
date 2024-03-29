#include <iostream>

struct IMoveable // interface
{
    virtual void Move() = 0; // pure virtual function/method
};

class Cat : public IMoveable
{
public:
    virtual void Move() override
    {
        
    }
};

struct A
{
    
};

struct B : public A
{
public:
    int GetA()
    {
        return a;
    }
private:
    int a;
};

class Vehicle : public IMoveable // abstract class
{
    // Move, Accelerate
    // [nullptr, 0x42]
public:
    virtual ~Vehicle() = default;
    Vehicle() : MSpeed(), MColor(), MWeight()
    {
        std::cout << "Vehicle()" << '\n';
    }
    virtual void Accelerate() // 0x42
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
    // Move, Accelerate
    // [0x20, 0x42]
public:
    virtual ~Car() override
    {
        std::cout << "~Car()\n";
    }

    Car()
    {
        std::cout << "Car()\n";
    }
    virtual void Move() override // 0x20
    {
        std::cout << "Car::Move()\n";

        MSpeed += 50;
    }
};

class Motorcycle : public Vehicle
{
    // Move, Accelerate
    // [0x90, 0x72]
public:
    virtual ~Motorcycle() override
    {
        std::cout << "~Motorcycle()\n";
    }
    Motorcycle()
    {
        std::cout << "Motorcycle()" << '\n';
    }
    virtual void Move() override // 0x90
    {
        std::cout << "Motorcycle::Move()\n";

        MSpeed += 100;
    }

    virtual void Accelerate() override // 0x72
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


class Base // 8b
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

class Derived : public Base // 16b
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
    // {
    //     Base* base = new Derived;
    //
    //     base->DoSomething();
    //     
    //     std::cout << sizeof(Base);
    //
    //     delete base;
    // }
    
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
