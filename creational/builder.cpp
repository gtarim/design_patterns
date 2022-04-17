#include <iostream>
#include <vector>

struct Part { };
struct Transmission : public Part 
{
    int shifter; 
    Transmission(int _shifter) : shifter{_shifter} { }
};

struct Engine : public Part 
{
    double liter;
    Engine(double _liter) : liter{_liter} { }
};

struct Wheel : public Part 
{
    int size;
    Wheel(int _size) : size{_size} { }
};

class Creator
{
public:
    Creator& addPart(Part part)
    {
        parts.push_back(part);
        return *this;
    }
private:
    std::vector<Part> parts;
};

int main()
{
    Creator creator;
    creator.addPart(Transmission{8})
           .addPart(Engine{1.5})
           .addPart(Wheel{18})
           .addPart(Wheel{18})
           .addPart(Wheel{21})
           .addPart(Wheel{21});
}