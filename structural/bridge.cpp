#include <iostream>
#include <memory>

struct OperationSystem
{
    virtual bool run() const noexcept = 0;
};

struct Linux : public OperationSystem
{
    bool run() const noexcept override
    {
        std::cout << "Linux operation system run\n";
        return true;
    }
};

struct Computer
{
    virtual bool start() const noexcept = 0;
};

class Mac : public Computer
{
    std::unique_ptr<OperationSystem> os;
public:
    Mac() : os{ std::make_unique<Linux>() } { }
    bool start() const noexcept override
    {
        return os->run();
    }
};

int main()
{
    Mac mac;
    mac.start();
}