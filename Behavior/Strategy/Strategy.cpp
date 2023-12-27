#include <iostream>
using namespace std;

/*************************  策略模式   *****************************************/
// The abstract strategy
class Strategy
{
public:
    virtual void AlgorithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy
{
public:
    void AlgorithmInterface()
    {
        cout<<"I am from ConcreteStrategyA."<<endl;
    }
};


class ConcreteStrategyB : public Strategy
{
public:
    void AlgorithmInterface()
    {
        cout<<"I am from ConcreteStrategyB."<<endl;
    }
};

class ConcreteStrategyC : public Strategy
{
public:
    void AlgorithmInterface()
    {
        cout<<"I am from ConcreteStrategyC."<<endl;
    }
};


class Context
{
public:
    Context(Strategy *pStrategyArg)
        :pStrategy(pStrategyArg)
    {}
    
    void ContextInterface()
    {
        pStrategy->AlgorithmInterface();    // 我寻思，这不就是一个多态的简单使用吗?(只不过这样用就不需要暴露给外人关于 ConcreteStrategyA 这个的具体算法实现了，你只需要知道抽象类的接口即可)
    }
private:
    Strategy *pStrategy;
};

int main()
{
    // Create the Strategy
    Strategy *pStrategyA = new ConcreteStrategyA;
    Strategy *pStrategyB = new ConcreteStrategyB;
    Strategy *pStrategyC = new ConcreteStrategyC;

    Context *pContextA = new Context(pStrategyA);
    Context *pContextB = new Context(pStrategyB);
    Context *pContextC = new Context(pStrategyC);

    pContextA->ContextInterface();
    pContextB->ContextInterface();
    pContextC->ContextInterface();

    if (pStrategyA) delete pStrategyA;
    if (pStrategyB) delete pStrategyB;
    if (pStrategyC) delete pStrategyC;

    if (pContextA) delete pContextA;
    if (pContextB) delete pContextB;
    if (pContextC) delete pContextC;
}




// /*************************  简单工厂模式 + 策略模式   *****************************************/
// // Define the strategy type
// typedef enum StrategyType
// {
//     StrategyA,
//     StrategyB,
//     StrategyC
// }STRATEGYTYPE;

// // The abstract strategy
// class Strategy
// {
// public:
//     virtual void AlgorithmInterface() = 0;
//     virtual ~Strategy() = 0;
// };

// Strategy::~Strategy()
// {}

// class ConcreteStrategyA : public Strategy
// {
// public:
//     void AlgorithmInterface()
//     {
//         cout << "I am from ConcreteStrategyA." << endl;
//     }

//     ~ConcreteStrategyA(){}
// };

// class ConcreteStrategyB : public Strategy
// {
// public:
//     void AlgorithmInterface()
//     {
//         cout << "I am from ConcreteStrategyB." << endl;
//     }

//     ~ConcreteStrategyB(){}
// };

// class ConcreteStrategyC : public Strategy
// {
// public:
//     void AlgorithmInterface()
//     {
//         cout << "I am from ConcreteStrategyC." << endl;
//     }

//     ~ConcreteStrategyC(){}
// };

// class Context
// {
// public:
//     Context(STRATEGYTYPE strategyType)
//     {
//         switch (strategyType)
//         {
//         case StrategyA:
//             pStrategy = new ConcreteStrategyA;
//             break;

//         case StrategyB:
//             pStrategy = new ConcreteStrategyB;
//             break;

//         case StrategyC:
//             pStrategy = new ConcreteStrategyC;
//             break;

//         default:
//             break;
//         }
//     }

//     ~Context()
//     {
//         if (pStrategy) delete pStrategy;
//     }

//     void ContextInterface()
//     {
//         if (pStrategy)
//             pStrategy->AlgorithmInterface();
//     }

// private:
//     Strategy *pStrategy;
// };

// int main()
// {
//     //省去了 用户手动创建 Strategy对象的 过程, 这个过程交给简单工厂类完成(Context类本身就是基于简单工厂类设计出来的)
//     Context *pContextA = new Context(StrategyA);
//     Context *pContextB = new Context(StrategyB);
//     Context *pContextC = new Context(StrategyC);

//     pContextA->ContextInterface();
//     pContextB->ContextInterface();
//     pContextC->ContextInterface();

//     if (pContextA) delete pContextA;
//     if (pContextB) delete pContextB;
//     if (pContextC) delete pContextC;
// }