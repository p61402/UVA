#include <iostream>
using namespace std;

bool isLeap(int y)
{
    return (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
}

int main()
{
    int next, d, m, y, a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, k;

    while (cin >> next >> d >> m >> y)
    {
        if (next == 0)
            break;

        if (m != 1 && d != 1)
        {
            if (y == 2 && isLeap(y))
                k = 29;
            else
                k = a[m];

            if (next - k >= 0 && k - d >= 0)
            {
                next -= k - d + 1;
                d = 1;
                m++;
                if (m == 13)
                {
                    m = 1;
                    y++;
                }
            }
            else if (next - k < 0)
            {
                d += next;
                if (d > k)
                {
                    d -= k;
                    m++;
                }

                if (m == 13)
                {
                    m = 1;
                    y++;
                }
            }
        }

        cout << next << ' ' << d << ' ' << m << ' ' << y << endl;

        if (m != 1)
        {
            for (int i = m; i <= 12; i++)
            {
                if (y == 2 && isLeap(y))
                    k = 29;
                else
                    k = a[m];
                
                if (next - k >= 0)
                {
                    next -= k;
                    d = 1;
                    m++;
                    if (m == 13)
                    {
                        m = 1;
                        y++;
                    }
                }
            }
        }

        while (next > 365)
        {
            if (isLeap(y))
                next -= 366;
            else
                next -= 365;

            y++;
        }

        if (next > 0)
        {
            for (int i = m; i <= 12; i++)
            {
                if (y == 2 && isLeap(y))
                    k = 29;
                else
                    k = a[m];
                
                if (next - k >= 0)
                {
                    next -= k;
                    d = 1;
                }
                else
                {
                    m = i;
                    d = next;
                    break;
                }
            }
        }

        cout << next << ' ' << d << ' ' << m << ' ' << y << endl;
    }

    return 0;
}