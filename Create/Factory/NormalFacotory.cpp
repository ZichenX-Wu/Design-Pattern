#include <iostream>
using namespace std;

//工厂方法模式:
//特点:
//1. 商品类是抽象类     --->    派生出具体的商品类
//2. 工厂类是 "针对某一商品的" 抽象工厂类   --->    派生出具体工厂类(用于生产具体的商品)
//3. 当需要新增商品时，需要 手动添加具体工厂类

// 商品类
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

class LiNingShoes : public Shoes
{
public:
    void Show() {   cout << "Here is LiNingShoes!" << endl;   }
};


// 工厂类
class ShoesFactory
{
public:
    virtual Shoes* CreateShoes() = 0;
    virtual ~ShoesFactory() { }
};

class NikeFactory : public ShoesFactory
{
public:
    Shoes* CreateShoes()
    {
        return new NikeShoes();
    }
};

class LiNingFactory : public ShoesFactory
{
public:
    Shoes* CreateShoes()
    {
        return new LiNingShoes();
    }
};


int main()
{
    NikeFactory nFactory;
    Shoes* pNikeShoes = nFactory.CreateShoes();
    if(pNikeShoes)
    {
        pNikeShoes->Show();
        delete pNikeShoes;
        pNikeShoes = nullptr;
    }

	return 0;
}