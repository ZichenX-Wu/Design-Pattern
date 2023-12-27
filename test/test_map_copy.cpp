#include <iostream>
#include <map>
using namespace std;

class Point
{
public:
    Point()
    {
        cout << "Point()" << endl;
    }

    Point(int x, int y)
    {
        m_x = x;
        m_y = y;
        cout << "Point(): " << x << "," << y << endl;
    }

    bool operator<(const Point& other) const
    {
        if (m_x < other.m_x)
        {
            return true;
        }
        else if (m_x == other.m_x)
        {
            return m_y < other.m_y;
        }

        return false;
    }

    int m_x = 0;
    int m_y = 0;
};

class Chess
{
public:
    Chess(Point point, int color)
    {
        m_color = color;
        m_point = point;
        cout << "Chess()" << endl;
    }

    void setPoint(Point point)
    {
        m_point = point;
    }

    Point getPoint()
    {
        return m_point;
    }

    Point m_point;
    int m_color = 0;
};

int main()
{
    Chess* c1 = new Chess(Point(0, 1), 10);
    map<Point, Chess*> board;
    // auto p = pair<Point, Chess*>(c1->getPoint(), c1);
    board.insert(make_pair(c1->getPoint(), c1));

    c1->setPoint(Point(1, 2));
    board.emplace(c1->getPoint(), c1);

    c1->setPoint(Point(2, 3));
    board.emplace(c1->getPoint(), c1);

    for(const auto& [f, s] : board)
    {
        cout << "Point: " << f.m_x << "," << f.m_y << " - " << &f << " - " << s << endl;
    }

    return 0;
}