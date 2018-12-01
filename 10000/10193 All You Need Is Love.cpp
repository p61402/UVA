#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int main()
{
    int t, power, v1, v2;
    string s1, s2;

    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cin >> s1 >> s2;

        v1 = 0;
        power = 1;
        reverse(s1.begin(), s1.end());
        for (auto c : s1)
        {
            v1 += (c - '0') * power;
            power *= 2;
        }

        v2 = 0;
        power = 1;
        reverse(s2.begin(), s2.end());
        for (auto c : s2)
        {
            v2 += (c - '0') * power;
            power *= 2;
        }

        cout << "Pair #" << i << ": ";
        if (gcd(v1, v2) != 1)
            cout << "All you need is love!\n";
        else
            cout << "Love is not all you need!\n";
    }

    return 0;
}