#include <iostream>
using namespace std;

//模板工厂方法:
//特点:
//1. 商品类是抽象类
//2. 工厂类是抽象类
//3. 当我们需要新增商品时，只需要新增 商品类即可，不需要新增具体工厂类 (可能会新增CreateProduct()接口, 比如下一次卖手机, 就是新增CreatePhone()接口)

//相比 抽象工厂模式, 模板工厂不需要新增 具体工厂类了!

class Shoes
{
public:
    virtual void Show() = 0;
    virtual ~Shoes() { }
};

class NikeShoes : public Shoes
{
public:
    void Show() {   cout << "Here is NikeShoes!" << endl;   }
};


class Clothe
{
public:
    virtual void Show() = 0;
    virtual ~Clothe() { }
};

class NikeClothe : public Clothe
{
public:
    void Show() {   cout << "Here is NikeClothe!" << endl;  }
};


//  这个类有啥用?
// template <typename AbstractProduct_t>
// class AbstractFactory
// {
// public:
//     virtual AbstractProduct_t* CreateProduct() = 0;
//     virtual ~AbstractFactory() { }
// };

template <typename AbstractProduct_t, typename ConcreteProduct_t>
class ConcreteFactory //: public AbstractFactory<AbstractProduct_t>
{
public:
    AbstractProduct_t* CreateProduct()
    {
        return new ConcreteProduct_t();
    }
};


int main()
{
    ConcreteFactory<Clothe, NikeClothe> conFactory;
    Clothe* pNikeClothe = conFactory.CreateProduct();
    pNikeClothe->Show();
}