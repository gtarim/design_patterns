#include <iostream>

template <typename T>
class Adapter;

struct EuropeanPlug
{
    int getSocket()
    {
        std::cout << "european socket ";
        return 1;
    }

    template <typename T>
    void plugIn(Adapter<T>& adapter)
    {
        adapter.getSocket();
        std::cout << "plug in to european socket";
    }

};

struct JapanesePlug
{
    double getSocket()
    {
        std::cout << "japanese socket ";
        return 100.1;
    }

    template <typename T>
    void plugIn(Adapter<T>& adapter)
    {
        adapter.getSocket();
        std::cout << "plug in to japanese socket";
    }
};

template <typename T>
class Adapter
{
    T t;
public:
    Adapter( T _t ) : t{_t} {}
    auto getSocket()
    {
        return t.getSocket();
    }
};

int main()
{
    EuropeanPlug euPlug1 = EuropeanPlug{};
    auto adapter1 = Adapter<EuropeanPlug>{euPlug1};
    JapanesePlug jpPlug1;
    jpPlug1.plugIn(adapter1);

    std::cout << "\n";

    JapanesePlug jpPlug2 = JapanesePlug{};
    auto adapter2 = Adapter<JapanesePlug>{jpPlug2};
    EuropeanPlug euPlug2;
    euPlug2.plugIn(adapter2);
}