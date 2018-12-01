#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    gcd(b, a % b);
}

int main()
{
    int n, v;

    while (cin >> n && n != 0)
    {
        v = 0;
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                v += gcd(i, j);

        cout << v << endl;
    }

    return 0;
}