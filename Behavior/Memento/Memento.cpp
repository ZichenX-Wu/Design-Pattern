#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

//备忘录类
class Memento
{
public:
    Memento(const std::string& state)
        :_state(state)
    {}

    std::string getState() const
    {
        return _state;
    }

private:
    std::string _state;
};

//原始发起人
class Originator
{
public:
    Originator()
        :_state("")
    {}

    void setState(const std::string& state)
    {
        _state = state;
    }

    Memento saveStateToMemento()
    {
        return Memento(_state);
    }

    void restoreStateFromMemento(const Memento& memento)
    {
        _state = memento.getState();
    }

    std::string getState() const
    {
        return _state;
    }

private:
    std::string _state;
};

//看管者(管理Mementod的类)
class Caretaker
{
public:
    void addMemento(const Memento& memento)
    {
        _mementos.push_back(memento);
    }

    Memento getMemento(int index) const
    {
        return _mementos.at(index);
    }

private:
    std::vector<Memento> _mementos;
};

int main()
{
    Originator originator;
    Caretaker caretaker;

    originator.setState("State #1");
    originator.setState("State #2");
    caretaker.addMemento(originator.saveStateToMemento());

    originator.setState("State #3");
    caretaker.addMemento(originator.saveStateToMemento());

    originator.setState("State #4");

    std::cout << "Current state: " << originator.getState() << std::endl;

    originator.restoreStateFromMemento(caretaker.getMemento(0));
    std::cout << "First saved state: " << originator.getState() << std::endl;

    originator.restoreStateFromMemento(caretaker.getMemento(1));
    std::cout << "Second saved state: " << originator.getState() << std::endl;

    return 0;
}