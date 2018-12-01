#include <iostream>
using namespace std;

int main()
{
    long long s, n, k, p, pos, x, y;

    while (cin >> s >> n && s != 0)
    {
        k = 1;
        p = 1;
        pos = s / 2 + 1;

        if (n == 1)
        {
            cout << "Line = " << pos << ", column = " << pos << ".\n";
            continue;
        }

        if (n > p)
        {
            while (n > p)
            {
                k += 2;
                p = k * k;
                pos++;
            }

            k -= 2;
            p = k * k;
            pos--;
        }

        x = pos;
        y = pos + 1;

        n -= p + 1;

        if (n - k > 0)
        {
            n -= k;
            x -= k;

            if (n - k - 1 > 0)
            {
                n -= k + 1;
                y -= k + 1;

                if (n - k - 1 > 0)
                {
                    n -= k + 1;
                    x += k + 1;
                    y += n;
                }
                else
                {
                    x += n;
                }
            }
            else
            {
                y -= n;
            }
        }
        else
        {
            x -= n;
        }

        cout << "Line = " << y << ", column = " << x << ".\n";
    }
    
    return 0;
}