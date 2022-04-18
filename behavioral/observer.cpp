#include <iostream>
#include <vector>
#include <algorithm>

class Observer;
class Subject
{
    int val;
public:
    Subject() : val{} { }
    void attach(Observer* observer)
    {
        observers.push_back(observer);
    }

    void notify();
    int getVal()
    {
        return val;
    }
private:
    std::vector<Observer*> observers;
};

class Observer
{
    Subject* subject;
    std::string name;
public:
    Observer(Subject& _subject, std::string _name) : subject{&_subject}, name{_name}
    {
        _subject.attach(this);
    }
    void update()
    {
        std::cout << name << " " << subject->getVal() << "\n";
    }
};

void Subject::notify()
{
    ++val;
    for(auto observer : observers)
    {
        observer->update();
    }
}

int main()
{
    Subject subject;

    Observer observer1{ subject, "observer1" };
    Observer observer2{ subject, "observer2" };

    subject.notify();
    subject.notify();
    subject.notify();
    subject.notify();
}