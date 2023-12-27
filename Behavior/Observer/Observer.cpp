#include <iostream>
#include <list>
using namespace std;

class Subject;

class Observer
{
public:
    virtual void Update(const Subject* const sub) = 0;
};

class Subject
{
public:
    virtual void Attach(Observer*) = 0;
    virtual void Detach(Observer*) = 0;
    virtual void Notify() = 0;
    virtual void SetState(int state) = 0;
    virtual int GetState() const = 0;
};

class ConcreteSubject : public Subject
{
public:
    void Attach(Observer* obs)
    {
        m_ObserverList.push_back(obs);
    }

    void Detach(Observer* obs)
    {
        m_ObserverList.remove(obs);
    }

    void Notify()
    {
        auto it = m_ObserverList.begin();
        while(it != m_ObserverList.end())
        {
            // (*it)->Update(m_state);
            (*it)->Update(this);
            ++it;
        }
    }

    void SetState(int state)
    {
        m_state = state;
    }

    int GetState() const
    {
        return m_state;
    }

private:
    list<Observer*> m_ObserverList;
    int m_state = 0;
};


// class Observer
// {
// public:
//     virtual void Update(int) = 0;
// };

class ConcreteObserver : public Observer
{
public:
    // ConcreteObserver(Subject* sub)
    //     :m_Subject(sub)
    // {}

    void Subscribe(Subject* sub)
    {
        m_SubjectList.push_back(sub);
    }

    void UnFollow(Subject* sub)
    {
        m_SubjectList.remove(sub);
    }

    void Update(const Subject* const sub)
    {
        cout << "Subject Notify: Now, state is: " << sub->GetState() << endl;
    }

private:
    // Subject* m_Subject;
    list<Subject*> m_SubjectList;
};

int main()
{
    ConcreteSubject* conSubject1 = new ConcreteSubject;
    // ConcreteObserver* ob1 = new ConcreteObserver(conSubject);
    // ConcreteObserver* ob2 = new ConcreteObserver(conSubject);
    // ConcreteObserver* ob3 = new ConcreteObserver(conSubject);

    ConcreteObserver* ob1 = new ConcreteObserver;
    ob1->Subscribe(conSubject1);

    ConcreteObserver* ob2 = new ConcreteObserver;
    ob2->Subscribe(conSubject1);

    ConcreteObserver* ob3 = new ConcreteObserver;
    ob2->Subscribe(conSubject1);


    conSubject1->Attach(ob1);
    conSubject1->Attach(ob2);
    conSubject1->Attach(ob3);

    conSubject1->SetState(1);
    conSubject1->Notify();
    conSubject1->SetState(20);
    conSubject1->Notify();


    ConcreteSubject* conSubject2 = new ConcreteSubject;

    ob1->Subscribe(conSubject2);
    ob2->Subscribe(conSubject2);
    ob2->Subscribe(conSubject2);


    conSubject2->Attach(ob1);
    conSubject2->Attach(ob2);
    conSubject2->Attach(ob3);

    conSubject2->SetState(233);
    conSubject2->Notify();
    conSubject2->SetState(555);
    conSubject2->Notify();



    return 0;
}