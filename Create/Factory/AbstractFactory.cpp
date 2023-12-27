#include <iostream>
using namespace std;

//抽象工厂模式:
//特点:
//1. 商品是抽象类     --->    派生出具体的商品类
//2. 工厂类是抽象类     --->    派生出具体的工厂类
//3. 当需要新增商品时，需要手动添加新的抽象商品类，以及其具体的商品类
//   当需要新增工厂时，需要手动修改已存在的抽象工厂类的接口，以及新增具体工厂类


//1. 支持同一个工厂生产多种产品
//2. 支持


// 产品A
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

// 产品B
class Clothe
{
public:
    virtual void Show() = 0;
    virtual ~Clothe() { }
};

class NikeClothe : public Clothe
{
public:
    void Show() {   cout << "Here is Nike Clothe~" << endl; }
};


// 工厂类
class Factory
{
public:
    virtual Shoes* CreateShoes() = 0;
    virtual Clothe* CreateClothe() = 0;
    virtual ~Factory() { }
};

class NikeFactory : public Factory
{
public:
    Shoes* CreateShoes()
    {
        return new NikeShoes();   
    }

    Clothe* CreateClothe()
    {
        return new NikeClothe();
    }
};

class LiNingFactory : public Factory
{
public:
    Shoes* CreateShoes()
    {
        return new LiNingShoes();   
    }

    Clothe* CreateClothe()
    {
        return new LiNingClothe();
    }
};



int main()
{
    NikeFactory nFactory;
    Shoes* pNikeShoes = nFactory.CreateShoes();
    pNikeShoes->Show();

    Clothe* pNikeClothe = nFactory.CreateClothe();
    pNikeClothe->Show();

	return 0;
}