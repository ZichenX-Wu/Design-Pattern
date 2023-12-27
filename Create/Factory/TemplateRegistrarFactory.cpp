#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

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

template <typename AbstractProduct_t, typename ConcreteProduct_t>
class RegisterProduction
{
public:
    RegisterProduction(const string& production)
    {
        if(m_RegisterList.find(production) == m_RegisterList.end())
        {
            m_RegisterList[production] = true;
        }
    }

private:
    unordered_map<string, bool> m_RegisterList;
};

template <typename AbstractProduct_t>
class Factory
{
public:
    AbstractProduct_t* CreateProduct(const string& production)
    {
        if()
    }
};


int main()
{
    RegisterProduction<Shoes, NikeShoes> nkShoes("Nike");
    Shoes* pNikeShoes = Factory.CreateProduct("Nike");
    pNikeClothe->Show();
    return 0;
}