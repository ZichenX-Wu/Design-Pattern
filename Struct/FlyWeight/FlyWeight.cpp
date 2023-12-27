#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef struct pointTag
{
    int x;
    int y;

    pointTag()
    {
        cout << "pointTag()" << endl;
    }
    
    pointTag(int a, int b)
    {
        x = a;
        y = b;
        cout << "pointTag(): " << x << "," << y << endl;
    }

    bool operator <(const pointTag& other) const
    {
        if (x < other.x)
        {
            return true;
        }
        else if (x == other.x)
        {
            return y < other.y;
        }

        return false;
    }
}POINT;

typedef enum PieceColorTag
{
    BLACK,
    WHITE
}PIECECOLOR;

class CPiece
{
public:
    CPiece(PIECECOLOR color)
        :m_color(color)
    {}
    
    PIECECOLOR GetColor() { return m_color; }

    // Set the external state
    void SetPoint(POINT point) { m_point = point; }
    POINT GetPoint() { return m_point; }

protected:
    // Internal state
    PIECECOLOR m_color;

    // external state
    POINT m_point;
};

class CGomoku : public CPiece
{
public:
    CGomoku(PIECECOLOR color)
        :CPiece(color)
    {}
};

class CPieceFactory
{
public:
    CPiece *GetPiece(PIECECOLOR color)
    {
        CPiece *pPiece = NULL;
        if (m_vecPiece.empty())
        {
            pPiece = new CGomoku(color);
            m_vecPiece.push_back(pPiece);
        }
        else
        {
            for (vector<CPiece *>::iterator it = m_vecPiece.begin(); it != m_vecPiece.end(); ++it)
            {
                if ((*it)->GetColor() == color)
                {
                    pPiece = *it;
                    break;
                }
            }
            if (pPiece == NULL)
            {
                pPiece = new CGomoku(color);
                m_vecPiece.push_back(pPiece);
            }
        }
            return pPiece;
    }

    ~CPieceFactory()
    {
        for (vector<CPiece *>::iterator it = m_vecPiece.begin(); it != m_vecPiece.end(); ++it)
        {
            if (*it != NULL)
            {
                delete *it;
                *it = NULL;
            }
        }
    }

    void getPieceAddress()
    {
        for(CPiece* p : m_vecPiece)
        {
            cout << "color: " << p->GetColor() << " " << "point: " << p->GetPoint().x << "," << p->GetPoint().y << " " << p << endl;
        }
    }

private:
    vector<CPiece *> m_vecPiece;
};

class CChessboard
{
public:
    void Draw(CPiece *piece)
    {
        if (piece->GetColor())
        {
                cout<< "Draw a White" << " at (" << piece->GetPoint().x << ","<< piece->GetPoint().y << ")" << endl;
        }
        else
        {
            cout<< "Draw a Black" << " at (" << piece->GetPoint().x << "," << piece->GetPoint().y << ")" << endl;
        }
        // m_mapPieces.insert(pair<POINT, CPiece *>(piece->GetPoint(), piece));
        m_mapPieces.emplace(piece->GetPoint(), piece);
    }

    void ShowAllPieces()
    {
        for (map<POINT, CPiece *>::iterator it = m_mapPieces.begin(); it != m_mapPieces.end(); ++it)
        {
            if (it->second->GetColor())
            {
                cout<< "(" << it->first.x << "," << it->first.y << ") has a White chese.";
            }
            else
            {
                cout<< "(" << it->first.x << "," << it->first.y << ") has a Black chese.";
            }
            cout << "Address: " << it->second << endl;
        }
    }

private:
    map<POINT, CPiece *> m_mapPieces;
};

int main()
{
    CPieceFactory *pPieceFactory = new CPieceFactory();
    CChessboard *pCheseboard = new CChessboard();

    // The player1 get a white piece from the pieces bowl
    CPiece *pPiece = pPieceFactory->GetPiece(WHITE);
    pPiece->SetPoint(POINT(2, 3));
    pCheseboard->Draw(pPiece);

    // The player2 get a black piece from the pieces bowl
    pPiece = pPieceFactory->GetPiece(BLACK);
    pPiece->SetPoint(POINT(4, 5));
    pCheseboard->Draw(pPiece);

    // The player1 get a white piece from the pieces bowl
    pPiece = pPieceFactory->GetPiece(WHITE);
    pPiece->SetPoint(POINT(2, 4));
    pCheseboard->Draw(pPiece);

    // The player2 get a black piece from the pieces bowl
    pPiece = pPieceFactory->GetPiece(BLACK);
    pPiece->SetPoint(POINT(3, 5));
    pCheseboard->Draw(pPiece);

    /*......*/

    pPieceFactory->getPieceAddress();

    //Show all cheses
    cout<<"Show all cheses"<<endl;
    pCheseboard->ShowAllPieces();

    if (pCheseboard != NULL)
    {
        delete pCheseboard;
        pCheseboard = NULL;
    }
    if (pPieceFactory != NULL)
    {
        delete pPieceFactory;
        pPieceFactory = NULL;
    }
}