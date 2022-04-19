#include <iostream>
#include <memory>

struct Transportation
{
    virtual ~Transportation() { }
    virtual void transport() = 0;
};

struct Vehicle : Transportation
{
    void transport() override { std::cout << "VehicleTransportation\n"; };
};

struct Train : Transportation
{
    void transport() override { std::cout << "TrainTransportation\n"; };
};

struct Plane : Transportation
{
    void transport() override { std::cout << "PlaneTransportation\n"; };
};

struct Strategy
{
    enum class Type {Vehicle, Train, Plane};
    void transport(Type type)
    {
        std::unique_ptr<Transportation> tr;
        if(type == Type::Vehicle)
        {
            tr = std::move( std::unique_ptr<Transportation>{ new Vehicle{} } );
        }
        else if(type == Type::Train)
        {
            tr = std::move( std::unique_ptr<Transportation>{ new Train{} } );
        }
        else if(type == Type::Plane)
        {
            tr = std::move( std::unique_ptr<Transportation>{ new Plane{} } );
        }
        else
        {
            return;
        }

        if(tr)
            tr->transport();
    }
};

int main()
{
    Strategy strategy1;
    strategy1.transport(Strategy::Type::Vehicle);

    Strategy strategy2;
    strategy2.transport(Strategy::Type::Train);

    Strategy strategy3;
    strategy3.transport(Strategy::Type::Plane);
}