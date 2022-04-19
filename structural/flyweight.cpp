#include <iostream>

class Car
{
    std::string name;
    std::string location;
public:
    Car(std::string _name, std::string _location) : name{_name}, location{_location} { }
};

struct Bmw : public Car
{
    Bmw() : Car{"bmw", "germany"} { std::cout << "bmw ctor\n"; }
};

struct Nissan : public Car
{
    Nissan() : Car{"nissan", "japan"} { std::cout << "nissan ctor\n"; }
};

class CarFactory
{
    CarFactory() {}
public:
    enum class CarType { Bmw, Nissan };
    static Car& getCar(CarType type)
    {
        if( type == CarType::Bmw) { static Bmw bmw; return bmw; }
        else { static Nissan nissan; return nissan; }
    }
};

int main()
{
    Car car1 = CarFactory::getCar(CarFactory::CarType::Bmw);
    Car car2 = CarFactory::getCar(CarFactory::CarType::Nissan);
    Car car3 = CarFactory::getCar(CarFactory::CarType::Bmw);
    Car car4 = CarFactory::getCar(CarFactory::CarType::Nissan);
}