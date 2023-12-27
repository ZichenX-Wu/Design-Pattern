#include <iostream>
using namespace std;

//简单工厂模式:
//特点:
//1. 商品类是抽象类     --->    派生出具体的商品类
//2. 只有1个工厂类, 在该工厂类中包含1个Create商品的方法
//3. 当需要新增商品时, 需要 手动修改 工厂类中的Create商品的方法


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
enum SHOES_TYPE
{
    Nike,
    LiNing
};

class ShoesFactory
{
public:
    Shoes* CreateShoes(SHOES_TYPE type)
    {
        switch(type)
        {
            case Nike:
                return new NikeShoes();
                break;
            case LiNing:
                return new LiNingShoes();
                break;
            default:
                return nullptr;
                break;
        }
    }
};


int main()
{
    ShoesFactory sFactory;
    Shoes* pNikeShoes = sFactory.CreateShoes(LiNing);
    if(pNikeShoes)
    {
        pNikeShoes->Show();
        delete pNikeShoes;
        pNikeShoes = nullptr;
    }
	return 0;
}