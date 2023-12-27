#include <iostream>
using namespace std;

// 使用逻辑与方法:
// 通过Context类的ChangeState()方法切换状态, ChangeState()方法接收 来自同一基类的派生类对象。
// 随后调用Request()时，会利用多态性质来实现根据State对象的类型去调用该类型中的Handle方法.


class Context;

class State
{
public:
    virtual void Handle(Context *pContext) = 0;
};

class ConcreteStateA : public State
{
public:
    virtual void Handle(Context *pContext)
    {
        cout<<"I am concretestateA."<<endl;
    }
};

class ConcreteStateB : public State
{
public:
    virtual void Handle(Context *pContext)
    {
        cout<<"I am concretestateB."<<endl;
    }
};


class Context
{
public:
    Context(State *pState)
        :m_pState(pState)
    {}

    void Request()
    {
        if (m_pState)
        {
            m_pState->Handle(this); // 这里是一个多态: m_pState是所有State的基类, 然后接收不同子类对象, 调用Handle方法, 以此形成多态
        }
    }

    void ChangeState(State *pState)
    {
        m_pState = pState;
    }

private:
    State *m_pState;
};

int main()
{
    State *pStateA = new ConcreteStateA();
    State *pStateB = new ConcreteStateB();
    Context *pContext = new Context(pStateA);
    pContext->Request();

    pContext->ChangeState(pStateB);
    pContext->Request();

    delete pContext;
    delete pStateB;
    delete pStateA;
}