#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int m, n, x, y, k;

    while (cin >> m >> n)
    {
        if (m == 0 && n == 0)
            break;

        x = m;
        y = n;
        k = 0;

        if (x < y)
            swap(x, y);

        if (y == 0)
            k = 0;
        else if (y == 1)
            k = x;
        else if (y == 2)
        {
            k += (x / 4) * 4;
            if (x % 4 == 1)
                k += 2;
            else if (x % 4 >= 2)
                k += 4;
        }
        else
        {
            if (y % 2 == 0)
                k += (y / 2) * x;
            else
                k += (y / 2) * x + (x + 1) / 2;
        }

        cout << k << " knights may be placed on a " << m << " row " << n << " column board.\n";
    }

    return 0;
}