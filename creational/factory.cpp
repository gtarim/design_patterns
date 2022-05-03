#include <iostream>
#include <vector>
#include <memory>

struct Car { Car(){ std::cout << "car ctor\n"; } };
struct Bmw : public Car { Bmw(){ std::cout << "bmw ctor\n"; } };
struct Ford : public Car { Ford(){ std::cout << "ford ctor\n"; } };

namespace FirstImpl
{
struct Factory
{
    enum class Type { Bmw, Ford };
    std::unique_ptr<Car> create(Type type) const
    {
        if (type == Type::Bmw)
            return std::make_unique<Bmw>();
        else if (type == Type::Ford)
            return std::make_unique<Ford>();
        else
            return std::unique_ptr<Car>{};
    }
};
};

namespace SecondImpl
{
template <typename T>
struct Factory
{
    std::unique_ptr<Car> create() const
    {
        return std::make_unique<T>();
    }
};
};

int main()
{
    {
        FirstImpl::Factory factory;
        std::unique_ptr<Car> bmw = factory.create(FirstImpl::Factory::Type::Bmw);
    }

    {
        SecondImpl::Factory<Bmw> factory;
        auto bmw = factory.create();
    }
}