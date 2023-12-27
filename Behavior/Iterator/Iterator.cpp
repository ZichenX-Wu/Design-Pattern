#include "Iterator.h"

JTList::~JTList()
{
    Node *pCurrent = m_pHead;
    Node *pNextNode = NULL;
    while (pCurrent)
    {
        pNextNode = pCurrent->pNext;
        delete pCurrent;
        pCurrent = pNextNode;
    }
}

long JTList::GetCount() const
{
    return m_lCount;
}

Node *JTList::Get(const long index) const
{
    // The min index is 0, max index is count - 1
    if (index > m_lCount - 1 || index < 0)
    {
        return NULL;
    }

    int iPosTemp = 0;
    Node *pNodeTemp = m_pHead;
    while (pNodeTemp)
    {
        if (index == iPosTemp++)
        {
            return pNodeTemp;
        }
        pNodeTemp = pNodeTemp->pNext;
    }
    return NULL;
}

Node *JTList::First() const
{
    return m_pHead;
}

Node *JTList::Last() const
{
    return m_pTail;
}

bool JTList::Includes(const int &value) const
{
    Node *pNodeTemp = m_pHead;
    while (pNodeTemp)
    {
        if (value == pNodeTemp->value)
        {
            return true;
        }
        pNodeTemp = pNodeTemp->pNext;
    }
    return false;
}

void JTList::Append(const int &value)
{
    // Create the new node
    Node *pInsertNode = new Node;
    pInsertNode->value = value;
    pInsertNode->pNext = NULL;

    // This list is empty
    if (m_pHead == NULL)
    {
        m_pHead = m_pTail = pInsertNode;
    }
    else
    {
        m_pTail->pNext = pInsertNode;
        m_pTail = pInsertNode;
    }
    ++m_lCount;
}

void JTList::Remove(Node *pNode)
{
    if (pNode == NULL || m_pHead == NULL || m_pTail == NULL)
    {
        return;
    }

    if (pNode == m_pHead) // If the deleting node is head node
    {
        Node *pNewHead = m_pHead->pNext;
        m_pHead = pNewHead;
    }
    else
    {
        // To get the deleting node's previous node
        Node *pPreviousNode = NULL;
        Node *pCurrentNode = m_pHead;
        while (pCurrentNode)
        {
            pPreviousNode = pCurrentNode;
            pCurrentNode = pCurrentNode->pNext;
            if (pCurrentNode == pNode)
            {
                break;
            }
        }

        // To get the deleting node's next node
        Node *pNextNode = pNode->pNext;

        // If pNextNode is NULL, it means the deleting node is the tail node, we should change the m_pTail pointer
        if (pNextNode == NULL)
        {
            m_pTail = pPreviousNode;
        }

        // Relink the list
        pPreviousNode->pNext = pNextNode;
    }

    // Delete the node
    delete pNode;
    pNode = NULL;
    --m_lCount;
}

void JTList::RemoveAll()
{
    delete this;
}

void JTListIterator::First()
{
    m_pCurrent = m_pJTList->First();
}

void JTListIterator::Next()
{
    m_pCurrent = m_pCurrent->pNext;
}

bool JTListIterator::IsDone() const
{
    return m_pCurrent == m_pJTList->Last()->pNext;
}

Node *JTListIterator::CurrentItem() const
{
    return m_pCurrent;
}

int main()
{
    JTList *pJTList = new JTList;
    pJTList->Append(10);
    pJTList->Append(20);
    pJTList->Append(30);
    pJTList->Append(40);
    pJTList->Append(50);
    pJTList->Append(60);
    pJTList->Append(70);
    pJTList->Append(80);
    pJTList->Append(90);
    pJTList->Append(100);

    Iterator *pIterator = new JTListIterator(pJTList);

    // Print the list by JTListIterator
    for (pIterator->First(); !pIterator->IsDone(); pIterator->Next())
    {
        cout<<pIterator->CurrentItem()->value<<"->";
    }
    cout<<"NULL"<<endl;

    // Test for removing
    Node *pDeleteNode = NULL;
    for (pIterator->First(); !pIterator->IsDone(); pIterator->Next())
    {
        pDeleteNode = pIterator->CurrentItem();
        if (pDeleteNode->value == 100)
        {
            pJTList->Remove(pDeleteNode);
            break;
        }
    }

    // Print the list by JTListIterator
    for (pIterator->First(); !pIterator->IsDone(); pIterator->Next())
    {
        cout<<pIterator->CurrentItem()->value<<"->";
    }
    cout<<"NULL"<<endl;

    delete pIterator;
    delete pJTList;

    return 0;
}