#include <iostream>
#include <cstdio>
using namespace std;

struct Point {
    double x;
    double y;
};

bool equal(Point a, Point b)
{
    return a.x == b.x && a.y == b.y;
}

void assign(Point &a, Point &b)
{
    a.x = b.x;
    a.y = b.y;
    return;
}

int main()
{
    Point p1, p2, p3, p4, A, B, C;

    while (cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y)
    {
        if (equal(p1, p3))
        {
            assign(A, p2);
            assign(C, p4);
            assign(B, p1);
        }
        else if (equal(p1, p4))
        {
            assign(A, p2);
            assign(C, p3);
            assign(B, p1);
        }
        else if (equal(p2, p3))
        {
            assign(A, p1);
            assign(C, p4);
            assign(B, p2);
        }
        else if (equal(p2, p4))
        {
            assign(A, p1);
            assign(C, p3);
            assign(B, p2);
        }

        printf("%.3f %.3f\n", 2 * (0.5 * (A.x + C.x)) - B.x, 2 * (0.5 * (A.y + C.y)) - B.y);
    }

    return 0;
}