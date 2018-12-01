#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int k, n[15];
    bool first = true;

    while (cin >> k && k)
    {
        for (int i = 0; i < k; i++)
            cin >> n[i];

        if (!first)
            cout << endl;
        else
            first = false;
        
        for (int a = 0; a <= k - 6; a++)
            for (int b = a + 1; b <= k - 5; b++)
                for (int c = b + 1; c <= k - 4; c++)
                    for (int d = c + 1; d <= k - 3; d++)
                        for (int e = d + 1; e <= k - 2; e++)
                            for (int f = e + 1; f <= k - 1; f++)
                                printf("%d %d %d %d %d %d\n", n[a], n[b], n[c], n[d], n[e], n[f]);
    }

    return 0;
}