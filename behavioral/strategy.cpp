#include <iostream>
#include <memory>

struct Transportation
{
    virtual ~Transportation() { }
    virtual void transport() const = 0;
};

struct Vehicle final : Transportation
{
    void transport() const override { std::cout << "VehicleTransportation\n"; };
};

struct Train final : Transportation
{
    void transport() const override { std::cout << "TrainTransportation\n"; };
};

struct Plane final : Transportation
{
    void transport() const override { std::cout << "PlaneTransportation\n"; };
};

struct Strategy
{
    void run(const Transportation& tr ) const
    {
        tr.transport();
    }
};

int main()
{
    Strategy strategy1;
    strategy1.run(Vehicle{});

    Strategy strategy2;
    strategy2.run(Train{});

    Strategy strategy3;
    strategy3.run(Plane{});
}