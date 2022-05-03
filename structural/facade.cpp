#include <iostream>

struct Engine
{
    double liter;
    Engine(double _liter) : liter{_liter} {}
    void start() {std::cout << "engine started\n";}
};

struct Transmission
{
    int gear;
    Transmission() : gear{} { }
    void setGear(int _gear) { gear = _gear; std::cout << "gear set to " << gear << "\n"; }
};

class Car
{
    Engine engine;
    Transmission transmission;
public:
    Car() : engine{1.5}, transmission{} {}
    void run()
    {
        transmission.setGear(0);
        engine.start();
        transmission.setGear(1);
    }
};

int main()
{
    Car car;
    car.run();
}