#include <iostream>
#include <memory>

struct EuPlug
{
    static constexpr int voltage = 220;
    static constexpr int hz = 50;

    bool plug(int _voltage, int _hz)
    {
        if( _voltage != voltage && _hz != hz)
            return false;
    
        std::cout << "eu plug is ok!\n";
        return true;
    }
};

struct JapanPlug
{
    static constexpr int voltage = 100;
    static constexpr int hz = 60;

    bool plug(int _voltage, int _hz)
    {
        if( _voltage != voltage && _hz != hz)
            return false;
    
        std::cout << "japan plug is ok!\n";
        return true;
    }
};

struct AdapterJp : public EuPlug
{
    std::unique_ptr<JapanPlug> jpplug;
    AdapterJp() : jpplug{} { }
    bool plugInToJp()
    {
        return jpplug->plug( voltage / 22 * 10, hz / 12 * 10 );
    }
};

struct AdapterEu : public JapanPlug
{
    std::unique_ptr<EuPlug> euplug;
    AdapterEu() : euplug{} { }

    bool plugInToEu()
    {
        return euplug->plug( voltage * 2.2, hz * 1.2 );
    }
};

int main()
{
    AdapterEu adapterEu;
    if(adapterEu.plugInToEu())
        std::cout << "eu status=ok\n";
    else
        std::cout << "eu status=nok";

    AdapterJp adapterJp;
    if(adapterJp.plugInToJp())
        std::cout << "jp status=ok\n";
    else
        std::cout << "jp status=nok";
}