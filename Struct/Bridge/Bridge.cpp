#include <iostream>
using namespace std;

// class Implementor
// {
// public:
//     virtual void OperationImpl() = 0;
// };

// class ConcreteImpementor : public Implementor
// {
// public:
//     void OperationImpl()
//     {
//         cout<<"OperationImpl"<<endl;
//     }
// };

// class Abstraction
// {
// public:
//     Abstraction(Implementor *pImpl)
//         :m_pImpl(pImpl)
//     {}

//     virtual void Operation() = 0;
// protected:
//     Implementor *m_pImpl;
// };

// class RedfinedAbstraction : public Abstraction
// {
// public:
//     RedfinedAbstraction(Implementor *pImpl)
//         : Abstraction(pImpl)
//     {}
    
//     void Operation()
//     {
//         m_pImpl->OperationImpl();
//     }
// };

// int main(int argc, char *argv[])
// {
//     Implementor *pImplObj = new ConcreteImpementor();
//     Abstraction *pAbsObj = new RedfinedAbstraction(pImplObj);
//     pAbsObj->Operation();

//     delete pImplObj;
//     pImplObj = NULL;
//     delete pAbsObj;
//     pAbsObj = NULL;
//     return 0;
// }


// 具体的例子
// Shape: 形状 (正方形, 圆形, 三角形, ...)
// Color: 颜色 (蓝色, 红色, 绿色, ...)

class Color
{
public:
    virtual void paint() = 0;
};

class BlueColor : public Color
{
public:
    virtual void paint()
    {
        cout << "Blue!" << endl;
    }
};

class RedColor : public Color
{
public:
    virtual void paint()
    {
        cout << "Red!" << endl;
    }
};



class Shape
{
public:
    Shape(Color* color)
        :m_color(color)
    {}

    virtual void drawInfo() = 0;

    ~Shape() { delete m_color; }
protected:
    Color* m_color;
};

class RectangleShape : public Shape
{
public:
    RectangleShape(Color* color)
        :Shape(color)
    {}

    virtual void drawInfo()
    {
        cout << "This is Rectangle - ";
        m_color->paint();
    }
};

class CircleShape : public Shape
{
public:
    CircleShape(Color* color)
        :Shape(color)
    {}

    virtual void drawInfo()
    {
        cout << "This is Circle - ";
        m_color->paint();
    }
};


int main()
{
    RectangleShape* rect = new RectangleShape(new BlueColor());
    rect->drawInfo();
    CircleShape* circle = new CircleShape(new RedColor());
    circle->drawInfo();

    delete rect;
    delete circle;
    return 0;
}