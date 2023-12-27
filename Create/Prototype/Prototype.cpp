#include <iostream>
using namespace std;

//接口
class Prototype
{
public :
    Prototype(){}
    virtual ~Prototype(){}
    virtual Prototype* Clone() = 0;
    virtual void setCounter(int counter) = 0;
    virtual int getCounter() = 0;
};

//实现
class ConcretePrototype : public Prototype
{
public :
    ConcretePrototype()
        :m_counter(233)
    {}
    virtual ~ConcretePrototype(){}

    //拷贝构造函数
    ConcretePrototype(const ConcretePrototype& rhs)
        :m_counter(rhs.m_counter)
    {}

    //复制自身
    virtual ConcretePrototype* Clone()
    {
        //调用拷贝构造函数
        return new ConcretePrototype(*this);
    }

    virtual void setCounter(int counter)
    {
        m_counter = counter;
    }

    virtual int getCounter()
    {
        return m_counter;
    }

private :
    int m_counter;  // 类的成员变量
};

int main(int argc , char **argv)
{
    //生成对像
    ConcretePrototype* conProA = new ConcretePrototype();

    //复制自身
    ConcretePrototype* conProB = conProA->Clone();

    conProA->setCounter(10);
    conProB->setCounter(99);
    cout << "conProA: " << conProA->getCounter() << endl;
    cout << "conProB: " << conProB->getCounter() << endl;

    delete conProA;
    conProA = NULL ;
    delete conProB;
    conProB = NULL ;
    return 0;
}