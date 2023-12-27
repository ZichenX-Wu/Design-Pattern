#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// class ConcreteElementA;
// class ConcreteElementB;

// class Visitor
// {
// public:
//     virtual void VisitConcreteElementA(ConcreteElementA *pElementA) = 0;
//     virtual void VisitConcreteElementB(ConcreteElementB *pElementB) = 0;
// };

// class ConcreteVisitor1 : public Visitor
// {
// public:
//     void VisitConcreteElementA(ConcreteElementA *pElementA);
//     void VisitConcreteElementB(ConcreteElementB *pElementB);
// };

// void ConcreteVisitor1::VisitConcreteElementA(ConcreteElementA *pElementA)
// {
//     // 现在根据传进来的pElementA，可以对ConcreteElementA中的element进行操作
// }

// void ConcreteVisitor1::VisitConcreteElementB(ConcreteElementB *pElementB)
// {
//     // 现在根据传进来的pElementB，可以对ConcreteElementB中的element进行操作
// }

// class ConcreteVisitor2 : public Visitor
// {
// public:
//     void VisitConcreteElementA(ConcreteElementA *pElementA);
//     void VisitConcreteElementB(ConcreteElementB *pElementB);
// };

// void ConcreteVisitor2::VisitConcreteElementA(ConcreteElementA *pElementA)
// {
//     // ...
// }

// void ConcreteVisitor2::VisitConcreteElementB(ConcreteElementB *pElementB)
// {
//     // ...
// }

// // Element object
// class Element
// {
// public:
//     virtual void Accept(Visitor *pVisitor) = 0;
// };

// class ConcreteElementA : public Element
// {
// public:
//     void Accept(Visitor *pVisitor);
// };

// void ConcreteElementA::Accept(Visitor *pVisitor)
// {
//     pVisitor->VisitConcreteElementA(this);
// }

// class ConcreteElementB : public Element
// {
// public:
//     void Accept(Visitor *pVisitor);
// };

// void ConcreteElementB::Accept(Visitor *pVisitor)
// {
//     pVisitor->VisitConcreteElementB(this);
// }

// // ObjectStructure类，能枚举它的元素，可以提供一个高层的接口以允许访问者访问它的元素
// class ObjectStructure
// {
// public:
//     void Attach(Element *pElement);
//     void Detach(Element *pElement);
//     void Accept(Visitor *pVisitor);

// private:
//     vector<Element *> elements;
// };

// void ObjectStructure::Attach(Element *pElement)
// {
//     elements.push_back(pElement);
// }

// void ObjectStructure::Detach(Element *pElement)
// {
//     vector<Element *>::iterator it = find(elements.begin(), elements.end(), pElement);
//     if (it != elements.end())
//     {
//         elements.erase(it);
//     }
// }

// void ObjectStructure::Accept(Visitor *pVisitor)
// {
//     // 为每一个element设置visitor，进行对应的操作
//     for (vector<Element *>::const_iterator it = elements.begin(); it != elements.end(); ++it)
//     {
//         (*it)->Accept(pVisitor);
//     }
// }

// int main()
// {
//     ObjectStructure *pObject = new ObjectStructure;

//     ConcreteElementA *pElementA = new ConcreteElementA;
//     ConcreteElementB *pElementB = new ConcreteElementB;

//     pObject->Attach(pElementA);
//     pObject->Attach(pElementB);

//     ConcreteVisitor1 *pVisitor1 = new ConcreteVisitor1;
//     ConcreteVisitor2 *pVisitor2 = new ConcreteVisitor2;

//     pObject->Accept(pVisitor1);
//     pObject->Accept(pVisitor2);

//     if (pVisitor2) delete pVisitor2;
//     if (pVisitor1) delete pVisitor1;
//     if (pElementB) delete pElementB;
//     if (pElementA) delete pElementA;
//     if (pObject) delete pObject;

//     return 0;
// }




// 比较好理解的例子
class Visitor;

class DataStructure
{
public:
    virtual void accept(Visitor& visitor) = 0;
    virtual std::vector<int>& getData() = 0;
    virtual void addData(int data) = 0;
};

class Array : public DataStructure
{
public:
    void accept(Visitor& visitor);
    std::vector<int>& getData();
    void addData(int data);

private:
    std::vector<int> m_data;
};

class Linked : public DataStructure
{
public:
    void accept(Visitor& visitor);
    std::vector<int>& getData();
    void addData(int data);

private:
    std::vector<int> m_data;
};

class Visitor
{
public:
    virtual void visit(Array& array) = 0;
    virtual void visit(Linked& linked) = 0;
};

class DisplayVisitor : public Visitor
{
public:
    void visit(Array& array);
    void visit(Linked& linked);
};

void Array::accept(Visitor& visitor)
{
    visitor.visit(*this);
}

std::vector<int>& Array::getData()
{
    return m_data;
}

void Array::addData(int data)
{
    m_data.push_back(data);
}

void Linked::accept(Visitor& visitor)
{
    visitor.visit(*this);
}

std::vector<int>& Linked::getData()
{
    return m_data;
}

void Linked::addData(int data)
{
    m_data.push_back(data);
}

void DisplayVisitor::visit(Array& array)
{
    std::cout << "Displaying Array data: ";
    for (int i = 0; i < array.getData().size(); i++)
    {
        std::cout << array.getData()[i] << " ";
    }
    std::cout << std::endl;
}

void DisplayVisitor::visit(Linked& linked)
{
    std::cout << "Displaying Linked data: ";
    for (int i = 0; i < linked.getData().size(); i++)
    {
        std::cout << linked.getData()[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Array arr;
    arr.addData(1);
    arr.addData(2);

    Linked linked;
    linked.addData(3);
    linked.addData(4);

    DisplayVisitor displayVisitor;

    arr.accept(displayVisitor);
    linked.accept(displayVisitor);

    return 0;
}