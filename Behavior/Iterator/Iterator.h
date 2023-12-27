#include <iostream>
using namespace std;

typedef struct tagNode
{
    int value;
    tagNode *pNext;
}Node;


class JTList
{
public:
    JTList()
        :m_pHead(NULL), m_pTail(NULL)
    {}

    JTList(const JTList &);
    ~JTList();
    JTList &operator=(const JTList &);

    long GetCount() const;
    Node *Get(const long index) const;
    Node *First() const;
    Node *Last() const;
    bool Includes(const int &) const;

    void Append(const int &);
    void Remove(Node *pNode);
    void RemoveAll();

private:
    Node *m_pHead;
    Node *m_pTail;
    long m_lCount;
};


class Iterator
{
public:
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() const = 0;
    virtual Node *CurrentItem() const  = 0;
};

class JTListIterator : public Iterator
{
public:
    JTListIterator(JTList *pList)
        :m_pJTList(pList), m_pCurrent(NULL)
    {}

    virtual void First();
    virtual void Next();
    virtual bool IsDone() const;
    virtual Node *CurrentItem() const;

private:
    JTList *m_pJTList;
    Node *m_pCurrent;
};