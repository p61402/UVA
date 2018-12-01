#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int f, r, fc[10], rc[10], x;
    double ratios[100], max_spread;

    while (cin >> f && f)
    {
        cin >> r;

        for (int i = 0; i < f; i++)
            cin >> fc[i];
        
        for (int i = 0; i < r; i++)
            cin >> rc[i];

        x = 0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < f; j++)
                ratios[x++] = (double)rc[i] / fc[j];

        sort(ratios, ratios + x);

        max_spread = 0;
        for (int i = 1; i < x; i++)
            max_spread = max(max_spread, ratios[i] / ratios[i - 1]);

        printf("%.2f\n", max_spread);
    }

    return 0;
}