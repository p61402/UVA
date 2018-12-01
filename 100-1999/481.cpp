#include <iostream>
using namespace std;

int max(int x, int y)
{
    if (x > y)
        return x;
    return y;
}

int main()
{
    int x, c = 0, a[100000], DP[100000];

    while (cin >> x)
    {
        a[c] = x;
        DP[c] = 1;
        c++;
    }

    for (int j = 0; j < c - 1; j++)
        for (int i = j + 1; i < c; i++)
            if (a[j] < a[i])
                DP[i] = max(DP[i], DP[j] + 1);

    cout << DP[c-1] << endl << '-' << endl;

    int num = 1;
    for (int i = 0; i < c - 1; i++)
        if (DP[i] == num && DP[i + 1] == num + 1)
        {
            cout << a[i] << endl;
            num++;
        }
    cout << a[c - 1] << endl;

    return 0;
}