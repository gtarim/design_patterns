#include <iostream>
#include <memory>

struct Vehicle
{
    ~Vehicle() {}
    virtual void enter() const = 0;
};

struct Bmw : public Vehicle
{
    void enter() const override { std::cout << "bmw enter\n"; }
};

template <typename VehicleType>
class IEnter : public Vehicle
{
    std::unique_ptr<VehicleType> vehicle;
public:
    IEnter() : vehicle{ std::make_unique<VehicleType>() } {}
    void enter() const override
    {
        if(vehicle)
            vehicle->enter();
    }
};

int main()
{
    IEnter<Bmw> bmwKey {};
    bmwKey.enter();
}