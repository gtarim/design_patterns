#include <iostream>

class Singleton
{
    Singleton() = default;
public:
    Singleton( const Singleton& ) = delete;
    Singleton& operator=( const Singleton& ) = delete;
    
    static Singleton& getInstance()
    {
        static Singleton instance;
        return instance;
    }
};

int main()
{
    auto instance = Singleton::getInstance();
}