#include <iostream>
#include <vector>

struct Car { Car(){ std::cout << "car ctor\n"; } };
struct Bmw : public Car { Bmw(){ std::cout << "bmw ctor\n"; } };
struct Ford : public Car { Ford(){ std::cout << "ford ctor\n"; } };

struct CarFactory
{
    virtual Car* create() const = 0;
};

struct BmwFactory : public CarFactory
{
    Car* create() const override
    {
        return new Bmw{};
    }
};

struct FordFactory : public CarFactory 
{
    Car* create() const override
    {
        return new Ford{};
    }
};

int main()
{
    FordFactory ffactory;
    Car* car = ffactory.create();
}