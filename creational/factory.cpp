#include <iostream>
#include <vector>
#include <memory>

struct Car { Car(){ std::cout << "car ctor\n"; } };
struct Bmw : public Car { Bmw(){ std::cout << "bmw ctor\n"; } };
struct Ford : public Car { Ford(){ std::cout << "ford ctor\n"; } };

struct CarFactory
{
    virtual std::unique_ptr<Car> create() const = 0;
};

struct BmwFactory : public CarFactory
{
    std::unique_ptr<Car> create() const override
    {
        return std::make_unique<Bmw>();
    }
};

struct FordFactory : public CarFactory 
{
    std::unique_ptr<Car> create() const override
    {
        return std::make_unique<Ford>();
    }
};

int main()
{
    FordFactory ffactory;
    std::unique_ptr<Car> car = ffactory.create();
}