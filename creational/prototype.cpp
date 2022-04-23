#include <iostream>
#include <vector>
#include <memory>

struct Car 
{
    std::string name;
    std::string type;
    explicit Car( std::string _name) : name{_name} { }
    virtual std::unique_ptr<Car> clone() const = 0; 
    virtual void setType( std::string _type ) noexcept = 0;
};
struct Bmw : public Car 
{
    Bmw() : Car{"bmw"} { }
    std::unique_ptr<Car> clone() const override
    {
        return std::make_unique<Bmw>();
    }
    void setType( std::string _type ) noexcept override { type = _type; }
};

struct Nissan : public Car 
{
    Nissan() : Car{"nissan"} { }
    std::unique_ptr<Car> clone() const override
    {
        return std::make_unique<Nissan>();
    }
    void setType( std::string _type ) noexcept override { type = _type; }
};

int main()
{
    std::vector<std::unique_ptr<Car>> cars;

    const auto bmwBase = std::make_unique<Bmw>();
    std::unique_ptr<Car> bmw = bmwBase->clone();
    bmw->setType("wagon");
    cars.push_back( std::move(bmw) );

    const auto nissanBase = std::make_unique<Nissan>();
    std::unique_ptr<Car> nissan = nissanBase->clone();
    nissan->setType("coupe");
    cars.push_back( std::move(nissan) );


    for( auto const& car : cars)
    {
        std::cout << "name=" << car->name << " type=" << car->type << "\n";
    }
}