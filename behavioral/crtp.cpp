#include <iostream>

template <typename T>
struct Base
{
    void print() { static_cast<T&>(*this).print(); }
};

struct Der1 : public Base<Der1>
{
    void print() { std::cout << "der1\n"; }
};

struct Der2 : public Base<Der2>
{
    void print() { std::cout << "der2\n"; }
};

int main()
{
    Base der1 = Der1{};
    der1.print();

    Base der2 = Der2{};
    der2.print();
}