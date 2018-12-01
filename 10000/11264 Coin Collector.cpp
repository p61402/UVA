#include <iostream>
using namespace std;

int main()
{
    int t, n, coins[1005], amount, coin_count;

    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> coins[i];

        amount = 0;
        coin_count = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (amount + coins[i] < coins[i + 1])
            {
                amount += coins[i];
                coin_count++;
            }
        }

        cout << coin_count << endl;
    }

    return 0;
}