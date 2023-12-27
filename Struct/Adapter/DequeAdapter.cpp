#include <iostream>
using namespace std;

// class Deque
// {
// public:
//     void push(int x) { }
//     void pop() { }
// };

// class Stack : public Deque
// {
// public:
//     void push(int x) { }
//     void pop() { }
// };


// // 方法1: 多继承
// // Targets
// class Target
// {
// public:
//     virtual void Request()
//     {
//         cout<<"Target::Request"<<endl;
//     }
// };

// // Adaptee
// class Adaptee
// {
// public:
//     void SpecificRequest()
//     {
//         cout<<"Adaptee::SpecificRequest"<<endl;
//     }
// };

// // Adapter
// class Adapter : public Target, Adaptee
// {
// public:
//     void Request()
//     {
//         Adaptee::SpecificRequest();
//     }
// };


// 方法2: 组合
class Target
{
public:
    virtual void Request()
    {
        cout<<"Target::Request"<<endl;
    }
};

// Adaptee
class Adaptee
{
public:
    void SpecificRequest()
    {
        cout<<"Adaptee::SpecificRequest"<<endl;
        m_a = 10;
    }
private:
    int m_a;
};

// Adapter
class Adapter : public Target
{
public:
    Adapter()
        :m_adaptee(new Adaptee)
    {}

    void Request()
    {
        m_adaptee->SpecificRequest();
    }
    
    ~Adapter()
    {
        delete m_adaptee;
    }
private:
    Adaptee* m_adaptee = nullptr;
};


// Client (保持调用Request()接口不变)
int main(int argc, char *argv[])
{
    Target *targetObj = new Adapter();
    targetObj->Request();

    delete targetObj;
    targetObj = NULL;

    return 0;
}