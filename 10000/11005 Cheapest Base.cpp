#include <iostream>
#include <climits>
using namespace std;

int find_cost(int num, int base, int price[])
{
    int cost = 0;

    while (num)
    {
        cost += price[num % base];
        num /= base;
    }

    return cost;
}

int main()
{
    int t, n, x, price[36], cost[37], min_cost;

    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ":\n";

        for (int m = 0; m < 36; m++)
            cin >> price[m];

        cin >> n;

        while (n--)
        {
            cin >> x;

            min_cost = INT_MAX;
            for (int b = 2; b <= 36; b++)
            {
                cost[b] = find_cost(x, b, price);
                if (cost[b] < min_cost)
                    min_cost = cost[b];
            }

            cout << "Cheapest base(s) for number " << x << ":";
            for (int b = 2; b <= 36; b++)
                if (cost[b] == min_cost)
                    cout << ' ' << b;
            cout << endl;
        }

        if (i != t)
            cout << endl;
    }

    return 0;
}